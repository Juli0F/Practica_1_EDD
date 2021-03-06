#include <iostream>
#include "headers/class/Carreta.h"
#include "headers/pila.h"
#include "headers/class/NodoCliente.h"
#include "headers/Cola.h"
#include<stdlib.h>
#include<time.h>
#include "headers/Lista_Circular.h"
#include "headers/ListaDoble.h"
#include "file/File.h"
#include <chrono>
#include <thread>


using namespace std;


void crearClientes(int cant);
void crearCarretas(int cant);
void crearCajas(int cant);

void simulador();

void clientesLllegan();
void tomarCarreta(Pila *pila);
void clientesComprando(File *graph);
void pagandoCompras(File *graph);
void devolverCarreta(Carreta *carreta,int num);
void writeFile(File *graph);

int numRandom(int limitInferior, int limiteSuperior);


Pila *pilaCarretas; //pila de carretas disponibles
Pila *pilaCarretas_2;//pila de carretas disponibles

ListaDoble *listaDoble; //lista de Cajas disponibles para cobrar

Lista_Circular *comprando; //clientes haciendo compras

Cola *esperandoCarreta;//Clientes que llegan al supermercado, inicialmente pasan por una carreta
Cola *esperandoTurnoP; //clientes esperando a pagar

int paso = 0;
int clientesDisp;
int tes = -1;

int main() {

File *file = new File();
file->crearCarpeta("mkdir prueba");

    int cantClientes;
    int cantCarretas;
    int cantCajas;

    comprando = new Lista_Circular(); //inicialmente esta vacia, ya que nadie esta comprando
    esperandoTurnoP = new Cola(2);//inicialemte nadie esta haciendo cola para pagar

    cout<<"Cantidad de Clientes: ";
    cin>>cantClientes;

    cout<<"\nCantidad de Carretas: ";
    cin>>cantCarretas;

    cout<<"\nCantidad de Cajas: ";
    cin>>cantCajas;

     crearClientes(cantClientes); //cola de espera para tomar una carreta
     crearCarretas(cantCarretas); //pila de carretas
     crearCajas(cantCajas);




    //################################################simulacion###############################

    simulador();
}

void crearClientes(int cant){

    esperandoCarreta = new Cola(1);


    Cliente *cliente ;
    NodoCliente *nodoCliente;

    for (int i = 0; i < cant; ++i) {

            cliente = new Cliente(i);
            nodoCliente = new NodoCliente(i,cliente, nullptr);
            esperandoCarreta->encolar(nodoCliente);
    }


}
void crearCarretas(int cant){
    pilaCarretas =  new Pila(nullptr,1);
    pilaCarretas_2 =  new Pila(nullptr,2);

    Nodo *nodoCarreta ;
    Carreta *carreta;

     bool repartir = true;

    for (int i = 0; i < cant; ++i) {
            carreta = new Carreta(i);
            nodoCarreta = new Nodo(carreta, nullptr,i);

        if (repartir){
            pilaCarretas->push(nodoCarreta);
        }else{
            pilaCarretas_2->push(nodoCarreta);
        }
        repartir = !repartir;

    }
}
void crearCajas(int cant){
    listaDoble = new ListaDoble();

    Caja *cajaNueva ;
    NodoCaja *nCaja ;
    for (int i = 0; i < cant; ++i) {
        cajaNueva = new Caja(i,i*2);//modificar el tiempo para terminar Pago
        cajaNueva->setEstado(true);//estado actual disponible
        nCaja = new NodoCaja(cajaNueva, nullptr, nullptr,i);
        listaDoble->add(nCaja);
    }
}


void simulador(){
clientesDisp = 0;
    cout<<"Inicia Simulacion"<<endl;
    do {
        File *graph =new File();

        graph->escribirArchivo();

        paso++;
        cout<<"----------------------Paso "<<paso<<", Tomar Carreta ----------------------"<<endl;
        //paso uno llega el cliente
        clientesLllegan();
        writeFile(graph);

        //paso dos el cliente esta comprando, y  uno de ellos es posible que pase a pagar
        clientesComprando(graph);


        paso++;
        cout<<"----------------------Paso "<<paso<<", En Caja ----------------------"<<endl;
        //paso tres, cliente pasa a pagar
        pagandoCompras(graph);


        //graph->closeFile();
    } while (!((esperandoTurnoP->isEmpty() ) && (esperandoCarreta->isEmpty()) && (comprando->isEmpty())));

}

void clientesLllegan(){

    while (!(pilaCarretas->isEmpty() && pilaCarretas_2->isEmpty())){

    if (!(esperandoCarreta->isEmpty())) {//hay clientes llegando
            if (!pilaCarretas->isEmpty()) {//hay carretas disponibles

                tomarCarreta(pilaCarretas);

            } else if (!pilaCarretas_2->isEmpty()) {//pila uno esta vacia, por lo que se verifica la pila dos

                tomarCarreta(pilaCarretas_2);
            }
        } else {
            cout << "No hay Clientes esperando" << endl;
            break;
        }
    }
}
void tomarCarreta(Pila *pila){

    NodoCliente *clienteConCarreta = esperandoCarreta->desEncolar(); //pasa a tomar su carreta
    cout<<"Cliente: "<<clienteConCarreta->getCliente()->getId()<<" tomara la Carreta: "<<pila->peek()->getId()<<" Para Pasar a Comprar"<<endl;
    clienteConCarreta->getCliente()->setCarreta(pila->pop()->getCarreta()); //toma su carreta de la pila
    comprando->add(clienteConCarreta); //El Cliente entra a comprar
    cout<<"Cliente: "<<clienteConCarreta->getCliente()->getId()<<" Entro a  Comprar"<<endl;

}
int numRandom(int limitInferior, int limiteSuperior){

    return (rand()%limiteSuperior)+limitInferior;

}


void clientesComprando(File *graph){

        if (!(comprando->isEmpty())) {



            //revisar el metodo buscar nodo Cliente by id cliente
            int num =numRandom(0, 100);

            NodoCliente *nodoCliente = comprando->buscarNodoClienteByIdCliente(num);

            if (nodoCliente == nullptr){
                cout<<"Nadie Pasara a Pagar"<<endl;
            }else{
                paso++;
                cout<<"----------------------Paso "<<paso<<", Cola para Pagar----------------------"<<endl;
                cout<<"Cliente "<<nodoCliente->getCliente()->getId()<<", termina compras y pasara a Pagar "<<endl;

                comprando->eliminarByIdCliente(nodoCliente->getCliente()->getId());

                nodoCliente->setSiguiente(nullptr);
                nodoCliente->setAnterior(nullptr);
                esperandoTurnoP->encolar(nodoCliente);
                writeFile(graph);

            }
        }else{

        }
}
void pagandoCompras(File *graph){

    if (!esperandoTurnoP->isEmpty()) {
            NodoCaja *nCaja = listaDoble->getNodoCajaPrimero();


            while (nCaja != nullptr) {
                if (nCaja->getCaja()->isEstado()) {

                    paso++;
        cout<<"----------------------Paso "<<paso<<", Cliente en Caja----------------------"<<endl;
                    //el cliente esta en la caja
                    nCaja->getCaja()->setCliente(esperandoTurnoP->desEncolar()->getCliente());
                    //  aca el programa debe pararse el tiempo, lo que la caja tarda en terminar el servicio
                    cout<<"sleep"<<endl;
                    this_thread::sleep_for(chrono::milliseconds(1500));

                    devolverCarreta(nCaja->getCaja()->getCliente()->getCarreta(),numRandom(1,100));


                    writeFile(graph);
                    break;
                }
                nCaja = nCaja->getSiguiente();
            }
        }else{
            clientesDisp = clientesDisp-1;
        }
}
void devolverCarreta(Carreta *carreta,int num){
    Nodo *deRegreso = new Nodo(carreta, nullptr,carreta->getIdCarreta());
    if (num < 20){
        pilaCarretas->push(deRegreso);
    }else{
        pilaCarretas_2->push(deRegreso);
    }
}

void writeFile(File *graph){

        pilaCarretas->recorrerStructura(graph,"Primera Pila De Carretas");
        pilaCarretas_2->recorrerStructura(graph,"Segunda Pila De Carretas");
        esperandoCarreta->recorrerStructura(graph,"Personas Esperando Carreta");
        esperandoTurnoP->recorrerStructura(graph,"Esperando a pasar a Una Caja");
        comprando->recorrerStructura(graph,"Comprando");

        listaDoble->recorrerStructura(graph,"Cajas");

        graph->closeFile();



}
//
// Created by cross on 27/02/21.
//

#include <iostream>
#include "../headers/Lista_Circular.h"

using namespace std;

Lista_Circular::Lista_Circular() {

}

void Lista_Circular::setNodCliente(NodoCliente *nodoRoot) {
this->primero = nodoRoot;
}

NodoCliente *Lista_Circular::getNodoCliente() {
    return primero;
}


NodoCliente *Lista_Circular::getUltimo() {
    return  ultimo;
}

NodoCliente *Lista_Circular::buscarNodoClienteByIdNodo(int idBuscar) {
    if (primero == nullptr ){
        return nullptr;
    }else{

        if (primero->getIdNodoCliente() == idBuscar){
            return primero;
        }else{
            NodoCliente *temp = primero;

            while(temp ->getSiguiente() != nullptr){
                if (temp->getSiguiente()->getIdNodoCliente() == idBuscar){
                    return temp->getSiguiente();
                }else{
                    temp = temp->getSiguiente();
                    if (temp == ultimo){
                        return nullptr;
                    }
                }
            }
            return nullptr;
        }
    }
}

NodoCliente *Lista_Circular::buscarNodoClienteByIdCliente(int idClienteBuscar) {
    if (primero == nullptr) {
        return nullptr;
    } else {
        if (primero->getCliente()->getId() == idClienteBuscar) {
            return primero;
        } else {
            NodoCliente *temp = primero;

            while (temp->getSiguiente() != nullptr) {
                if (temp->getSiguiente()->getCliente()->getId() == idClienteBuscar) {
                    return temp->getSiguiente();
                } else {
                    temp = temp->getSiguiente();
                    if (temp == ultimo){
                        return nullptr;
                    }
                }
            }
            return nullptr;
        }
    }
}

    void Lista_Circular::add(NodoCliente *addNodo) {

        if (primero == nullptr){

            primero = ultimo = addNodo;

            primero->setSiguiente(ultimo);
            primero->setAnterior(ultimo);

            ultimo->setSiguiente(primero);
            ultimo->setAnterior(primero);

        }else{

            ultimo->setSiguiente(addNodo);

            addNodo->setAnterior(ultimo);
            addNodo->setSiguiente(primero);

            ultimo = addNodo;
        }

    }
    void Lista_Circular::eliminar(NodoCliente *nodoEliminar) {
        if (primero == nullptr){

        }else{
            NodoCliente *temp = primero;
            if (temp == nodoEliminar){
                primero = temp->getSiguiente();

                if (primero != ultimo){
                    ultimo->setSiguiente(primero);
                }
                delete temp;

            }else{
                while (temp->getSiguiente() != ultimo){

                    if (temp->getSiguiente() == nodoEliminar){
                        temp->setSiguiente(nodoEliminar->getSiguiente());

                        if (nodoEliminar == ultimo){
                            ultimo = temp->getSiguiente();
                        }
                        delete nodoEliminar;
                        return;
                    }

                    temp = temp->getSiguiente();
                }


            }

        }
    }
    void Lista_Circular::eliminarByIdNodo(int idNodo) {
         if(primero == nullptr){
        cout<<"Lista Circular Vacia";
    } else {
        NodoCliente* auxiliar;
        if(primero == ultimo && primero->getIdNodoCliente() == idNodo) {
            auxiliar = primero;
            primero = ultimo = nullptr;
            
        } else {
            if(primero->getIdNodoCliente() == idNodo){
                auxiliar = primero;
                ultimo = primero->getSiguiente();
                primero->setSiguiente(ultimo);
                primero = primero->getSiguiente();
            } else if(ultimo->getIdNodoCliente() == idNodo) {
                auxiliar = ultimo;
                ultimo = ultimo->getAnterior();
                ultimo->setSiguiente(primero);
                primero->setAnterior(ultimo);
                
            } else {
                NodoCliente* aux = primero;
                while(aux->getSiguiente() != nullptr){
                    if(aux->getIdNodoCliente() == idNodo){
                        break;
                    }
                    aux = aux->getSiguiente();
                }
                NodoCliente* anterior = aux->getAnterior();
                NodoCliente* siguiente = aux->getSiguiente();

                anterior->setSiguiente(siguiente);
                siguiente->setAnterior(anterior) ;
                auxiliar = aux;
            }
            
        }


    }

    }
void Lista_Circular::eliminarByIdCliente(int idCliente) {
    if(primero == nullptr){
            cout<<"Lista Circular Vacia";
    } else {

         NodoCliente* auxiliar;
        if(primero == ultimo && primero->getCliente()->getId() == idCliente) {
            auxiliar = primero;
            primero = ultimo = nullptr;
            cout<<"Eliminacion COmplenta"<<endl;

        } else {
            if(primero->getCliente()->getId() == idCliente){
                auxiliar = primero;
                ultimo = primero->getSiguiente();
                primero->setSiguiente(ultimo);
                primero = primero->getSiguiente();
                cout<<"Eliminacion COmplenta primero"<<endl;
            } else if(ultimo->getCliente()->getId() == idCliente) {
                auxiliar = ultimo;
                ultimo = ultimo->getAnterior();
                ultimo->setSiguiente(primero);
                primero->setAnterior(ultimo);

            } else {
                NodoCliente* aux = primero;
                while(aux->getSiguiente() != nullptr){
                    if(aux->getCliente()->getId() == idCliente){
                        break;
                    }
                    aux = aux->getSiguiente();
                }
                NodoCliente* anterior = aux->getAnterior();
                NodoCliente* siguiente = aux->getSiguiente();

                anterior->setSiguiente(siguiente);
                siguiente->setAnterior(anterior) ;
                auxiliar = aux;
            }

        }


        }

}



    bool Lista_Circular::isEmpty() {

        return primero == nullptr;
    }

    int Lista_Circular::size() {
     int cont = 1;
        if (primero == nullptr){
            return 0;
        }else{
            NodoCliente *temp = primero;

        while(temp->getSiguiente() != nullptr ){
            cont++;
            temp = temp->getSiguiente();
            if ( temp->getSiguiente() == ultimo){
                return cont;
            }
        }
        return cont;
    }


    }

void Lista_Circular::recorrerStructura(File *graphFile,string nombre) {

    if (primero != nullptr){
        //graphFile->addLinea("\tsubgraph lista_circular{\n\n");
        graphFile->addLinea("\tsubgraph cluster_3 {\n\n");


        NodoCliente *temp = primero;

        while (temp != nullptr){
            if (temp == ultimo){
                int id_cliente_1 = ultimo->getCliente()->getId();
                int id_cliente_2 = primero->getCliente()->getId();
                string id_cliente1_str(to_string(id_cliente_1));//(STRING(id_cliente_1));
                string id_cliente2_str(to_string(id_cliente_2));//(STRING(id_cliente_2));
                string strFinal = "\t\t\"" + id_cliente1_str + "_c\" -> \"" + id_cliente2_str + "_c\";\n";
                string strFinal_retroceso = "\t\t\"" + id_cliente2_str + "_c\" -> \"" + id_cliente1_str + "_c\";\n";
                graphFile->addLinea(strFinal);
                graphFile->addLinea(strFinal_retroceso);
                break;
                return;
            }else{

                int id_cliente_1 = temp->getCliente()->getId();
                int id_cliente_2 = temp->getSiguiente()->getCliente()->getId();
                string id_cliente1_str(to_string(id_cliente_1));//(STRING(id_cliente_1));
                string id_cliente2_str(to_string(id_cliente_2));//(STRING(id_cliente_2));
                string strFinal = "\t\t\"" + id_cliente1_str + "_c\" -> \"" + id_cliente2_str + "_c\";\n";
                string strFinal_retroceso = "\t\t\"" + id_cliente2_str + "_c\" -> \"" + id_cliente1_str + "_c\";\n";
                //string strFinal = "\t\t" + id_cliente1_str +"_c  -> " + id_cliente2_str +"_c;\n";

                graphFile->addLinea(strFinal);
                graphFile->addLinea(strFinal_retroceso);
                temp = temp->getSiguiente();
            }
        }

        graphFile->addLinea("\t\tlabel = \"" +nombre+"\";\n");
        graphFile->addLinea("\t\tcolor = blue;\n");
        graphFile->addLinea("\t}\n\n");
    }

}

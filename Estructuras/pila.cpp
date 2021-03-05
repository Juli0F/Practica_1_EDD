//
// Created by cross on 22/02/21.
//
#include "iostream"
#include "../headers/pila.h"
#include "string";
using namespace std;
Pila::Pila(Nodo *nodoParam, int id_param) {
    this->nodo = nodoParam;
    this->id = id_param;
}

Nodo *Pila::getNodo() {
    return nodo;
}

void Pila::push(Nodo *nodoNuevo) {

    if (nodo == nullptr){
        nodo = nodoNuevo;
    }else{
        Nodo* temp = nodo;
        while(temp->getSiguiente() != nullptr){
            temp = temp->getSiguiente();
        }
        temp->setSiguiente(nodoNuevo);
    }
}

Nodo* Pila::pop() {
    if (nodo == nullptr){
        cout<<"Pila Vacia"<<endl;
    }else{
        Nodo* temp = nodo;
        if (temp->getSiguiente() == nullptr){
            nodo = nullptr;
            return temp;
        }
        //  N1 --> N2 --> null //N2 es el tope, temp  = N1

        while (temp->getSiguiente()->getSiguiente() != nullptr){
            temp = temp->getSiguiente();
        }

        Nodo *aux = temp->getSiguiente();
        temp->setSiguiente(nullptr);

        return aux;

    }

}

Nodo* Pila::peek() {

    if (nodo == nullptr){
        cout<<"Pila Vacia"<<endl;

    }else{
        Nodo* temp = nodo;
        while (temp->getSiguiente() != nullptr){
            temp = temp->getSiguiente();
        }
    return temp;
    }

    return nullptr;

}

bool Pila::isEmpty() {
    return  nodo == nullptr;

}

int Pila::size() {
    int cont = 1;
    if (nodo == nullptr){
        return 0;
    }else{
        Nodo *temp = nodo;

        while(temp->getSiguiente() != nullptr){
            cont++;
            temp = temp->getSiguiente();
        }
        return cont;
    }

}

void Pila::recorrerStructura(File *graphFile,string nombre) {

int id_pila_int = id;
string idPila(to_string(id_pila_int));
graphFile->addLinea("\tsubgraph pila_"+idPila+"{\n\n");

graphFile->addLinea("\t\tlabel = \"" +nombre+"\";\n");
graphFile->addLinea("\t\tcolor = blue;\n");

    if (nodo != nullptr){


        Nodo *temp = nodo;

        while (temp != nullptr){

            if (temp->getSiguiente() != nullptr) {


                int nodo_uno = temp->getCarreta()->getIdCarreta();
                int nodo_dos = temp->getSiguiente()->getCarreta()->getIdCarreta();

                string nodo_uno_str = to_string(nodo_uno);
                string nodo_dos_str = to_string(nodo_dos);

                string str = "\t\t" + nodo_uno_str + " -> " + nodo_dos_str + ";\n";
                graphFile->addLinea(str);
            }

            temp = temp->getSiguiente();


        }


    }
graphFile->addLinea("\t}\n\n");
}

string Pila::toString() {

    return "Nodo",nodo->toString(),"---> siguiente",nodo->getSiguiente()->toString(),"\n";
}

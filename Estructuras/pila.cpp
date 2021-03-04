//
// Created by cross on 22/02/21.
//
#include "iostream"
#include "../headers/pila.h"
using namespace std;
Pila::Pila(Nodo *nodoParam) {
    this->nodo = nodoParam;
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
        delete temp;
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

string Pila::toString() {

    return "Nodo",nodo->toString(),"---> siguiente",nodo->getSiguiente()->toString(),"\n";
}

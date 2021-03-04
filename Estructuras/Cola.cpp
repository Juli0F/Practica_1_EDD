//
// Created by cross on 26/02/21.
//

#include <iostream>
#include "../headers/Cola.h"

using namespace std;
Cola::Cola() {
    //this->nodoCliente = nodoParam;
}

void Cola::setNodoCliente(NodoCliente *nodoParam) {
    this->nodoCliente = nodoParam;
}

NodoCliente *Cola::getNodoCliente() {
    return this->nodoCliente;
}

void Cola::encolar(NodoCliente *nodoNuevo) {
    if (nodoCliente == nullptr){
        nodoCliente = nodoNuevo;
    }else{
        NodoCliente *temp = nodoCliente;


        while (temp->getSiguiente() != nullptr){

            cout<<"Temp "<<temp->getSiguiente()->getCliente()->getId()  ;
            temp = temp->getSiguiente();
        }
        temp->setSiguiente(nodoNuevo);

    }

}

NodoCliente* Cola::desEncolar() {
    if (nodoCliente == nullptr){
        return nullptr;
    }else{

        NodoCliente *temp = nodoCliente;
        nodoCliente = temp->getSiguiente();
//cout<<"Desencolar :"<<temp->getCliente()->getId();
        return  temp;
    }
}

NodoCliente *Cola::peek() {
    return nodoCliente;
}

bool Cola::isEmpty() {
    return nodoCliente == nullptr;

}

int Cola::size() {
     int cont = 1;
    if (nodoCliente == nullptr){
        return 0;
    }else{
        NodoCliente *temp = nodoCliente;

        while(temp->getSiguiente() != nullptr){
            cont++;
            temp = temp->getSiguiente();
            cout<<"Recorrer"<<temp->getIdNodoCliente();
        }
        return cont;
    }


}

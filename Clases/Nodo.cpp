//
// Created by cross on 26/02/21.
//
#include "iostream"
#include "../headers/class/Nodo.h"
using namespace std;

Nodo::Nodo(Carreta *carretaParam, Nodo *nodoParam, int ident) {

    this->carreta = carretaParam;
    this->siguiente = nodoParam;
    this->id = ident;

}

Nodo *Nodo::getSiguiente() {
    return siguiente;
}

void Nodo::setSiguiente(Nodo *siguiente) {
    this->siguiente = siguiente;

}

Carreta *Nodo::getCarreta() {
    return this->carreta;
}

void Nodo::setCarreta(Carreta *carretaParam) {
    this->carreta = carretaParam;
}

int Nodo::getId() {
    return this->id;
}

int Nodo::setId(int idParam) {
    return this->id = idParam;
}

string Nodo::toString() {
//stringstream
    return "idNodo: " , id, ", Carreta "+carreta->getIdCarreta(),"\n";

}

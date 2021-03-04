//
// Created by cross on 26/02/21.
//

#include "../headers/NodoCliente.h"

NodoCliente::NodoCliente(int idParam, Cliente *clienteParam, NodoCliente *siguienteParam) {

    this->idNodoCliente = idParam;
    this->cliente = clienteParam;
    this->siguiente = siguienteParam;
}

int NodoCliente::getIdNodoCliente() {
    return this->idNodoCliente;
}

void NodoCliente::setIdNodoCliente(int idParam) {

    this->idNodoCliente = idParam;
}

void NodoCliente::setCliente(Cliente *clienteParam) {

    this->cliente = clienteParam;

}

Cliente *NodoCliente::getCliente() {
    return this->cliente;
}

void NodoCliente::setSiguiente(NodoCliente *siguienteParam) {
    this->siguiente = siguienteParam;
}

NodoCliente *NodoCliente::getSiguiente() {
    if (this->siguiente == nullptr){
        return nullptr;
    }
    return this->siguiente;
}

string NodoCliente::toString() {
    return std::string();
}

void NodoCliente::setAnterior(NodoCliente *anteriorParam) {

        this->anterior = anteriorParam;
}

NodoCliente *NodoCliente::getAnterior() {
    return this->anterior;
}

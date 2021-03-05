//
// Created by cross on 27/02/21.
//

#include "../headers/class/NodoCaja.h"

NodoCaja::NodoCaja(Caja *cajaParam, NodoCaja *primeroParam, NodoCaja *ultimoParam, int id) {

    this->caja = cajaParam;
    this->anterior = primeroParam;
    this->siguiente = ultimoParam;
    this->idNodo = id;

}

Caja *NodoCaja::getCaja() {
    return  this->caja;
}

void NodoCaja::setCaja(Caja *cajaParam) {

    this->caja = cajaParam;

}

void NodoCaja::setAnterior(NodoCaja *primeroParam) {
    this->anterior = primeroParam;
}

NodoCaja *NodoCaja::getAnterior() {
    return  this->anterior;
}

void NodoCaja::setSiguiente(NodoCaja *segundoParam) {

    this->siguiente = segundoParam;
}

NodoCaja *NodoCaja::getSiguiente() {
    return this->siguiente;
}

int NodoCaja::getIdNodoCaja() {
    return idNodo;
}

void NodoCaja::setIdNodoCaja(int idNodoParam) {
this->idNodo = idNodoParam;
}

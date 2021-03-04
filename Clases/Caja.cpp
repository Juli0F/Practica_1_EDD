//
// Created by cross on 26/02/21.
//

#include "../headers/class/Caja.h"

Caja::Caja(int idCajaParam, int tiempoDeServicio) {

    this->idCaja = idCajaParam;
    this->tiempoServicio = tiempoDeServicio;
    this->estado = true;
}

int Caja::getIdCaja() {
    return this->idCaja;
}

int Caja::getTiempo() {
    return this->tiempoServicio;
}

bool Caja::isEstado() {
    return this->estado;
}

Cliente *Caja::getCliente() {
    return this->cliente;
}

void  Caja::setCliente(Cliente *cliente_){
    this->cliente = cliente_;
}

void Caja::setIdCaja(int idCajaParam) {
    this->idCaja = idCajaParam;

}

void Caja::setTiempo(int tiempoParam) {
    this->tiempoServicio = tiempoParam;
}

void Caja::setEstado(bool estadoParam) {
    this->estado = estadoParam;
}

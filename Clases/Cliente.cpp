//
// Created by cross on 26/02/21.
//

#include "../headers/class/Cliente.h"

Cliente::Cliente(int idParam) {
    this->id = idParam;
}
int Cliente::getId() {
    return this->id;
}
void Cliente::setId(int idParam) {
    this->id=idParam;
}
Carreta * Cliente::getCarreta() {
    return this->carreta;
}
void Cliente::setCarreta(Carreta *carreta) {
    this->carreta = carreta;
}


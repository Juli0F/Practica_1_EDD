//
// Created by cross on 26/02/21.
//
#include <iostream>
#include "../headers/class/Carreta.h"

using namespace std;
 Carreta::Carreta(int idCarretaParam) {
        this->idCarreta=idCarretaParam;
 }
 int Carreta::getIdCarreta() {
     return this->idCarreta;
 }
 void Carreta::setIdCarreta(int idCarretaParam) {
     this->idCarreta =idCarretaParam;
 }




//
// Created by cross on 26/02/21.
//

#ifndef PRACTICA_1_CLIENTE_H
#define PRACTICA_1_CLIENTE_H


#include "Carreta.h"

class Cliente {
private:
    int id;
    Carreta* carreta;

public:
    Cliente(int);
    int getId();
    void setId(int idParam);
    Carreta* getCarreta();
    void setCarreta(Carreta* carreta);


};

#endif //PRACTICA_1_CLIENTE_H

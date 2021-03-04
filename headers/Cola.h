//
// Created by cross on 26/02/21.
//

#ifndef PRACTICA_1_COLA_H
#define PRACTICA_1_COLA_H


#include "NodoCliente.h"

class Cola {

private:
    NodoCliente *nodoCliente;
public:

    Cola();

    void setNodoCliente(NodoCliente*);
    NodoCliente* getNodoCliente();

    /* estos metodos deben ir en la lista circular
    NodoCliente* buscarNodoClienteByIdNodo(int idNodo);
    NodoCliente* buscarNodoClienteByIdCliente(int idCliente);
    */
    void encolar(NodoCliente*);
    NodoCliente* desEncolar();

    NodoCliente* peek();
    bool isEmpty();
    int size();

};


#endif //PRACTICA_1_COLA_H

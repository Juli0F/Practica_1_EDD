//
// Created by cross on 26/02/21.
//

#ifndef PRACTICA_1_NODOCLIENTE_H
#define PRACTICA_1_NODOCLIENTE_H

#include <string>
#include "Cliente.h"

using namespace std;

class NodoCliente {
private:
    int idNodoCliente;
    Cliente *cliente;
    NodoCliente *siguiente;
    NodoCliente *anterior;

public:

    NodoCliente(int, Cliente *, NodoCliente *);

    int getIdNodoCliente();
    void setIdNodoCliente(int);

    void setCliente(Cliente*);
    Cliente* getCliente();

    void setSiguiente(NodoCliente*);
    NodoCliente* getSiguiente();

    void setAnterior(NodoCliente*);
    NodoCliente* getAnterior();

    string toString();
};
#endif //PRACTICA_1_NODOCLIENTE_H
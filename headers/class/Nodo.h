//
// Created by cross on 26/02/21.
//

#ifndef PRACTICA_1_NODO_H
#define PRACTICA_1_NODO_H

#include "Cliente.h"
#include <string>

//nodo para una cola de tipo clientes
using namespace std;
class Nodo {
private:
    int id;
    Carreta *carreta;
    Nodo *siguiente;
public:

    Nodo(Carreta*,Nodo*,int);

    Nodo* getSiguiente();
    void setSiguiente(Nodo* siguiente);

    Carreta* getCarreta();
    void setCarreta(Carreta*);

    int getId();
    int setId(int idParam);

    string toString();

};

#endif //PRACTICA_1_NODO_H

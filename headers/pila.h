//
// Created by cross on 22/02/21.
//

#ifndef PRACTICA_1_PILA_H
#define PRACTICA_1_PILA_H


#include "class/Carreta.h"
#include "Nodo.h"
#include <string>

class Pila {
private:
    Nodo* nodo;
public:
    Pila(Nodo* );
    Nodo* getNodo();
    void push(Nodo*);
    Nodo* pop();
    Nodo* peek();
    bool isEmpty();
    int size();
    string toString();

};



#endif //PRACTICA_1_PILA_H

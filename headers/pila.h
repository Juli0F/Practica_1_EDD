//
// Created by cross on 22/02/21.
//

#ifndef PRACTICA_1_PILA_H
#define PRACTICA_1_PILA_H


#include "class/Carreta.h"
#include "class/Nodo.h"
#include "../file/File.h"
#include <string>

class Pila {
private:
    int id;
    Nodo* nodo;
public:
    Pila(Nodo* ,int id);
    Nodo* getNodo();
    void push(Nodo*);
    Nodo* pop();
    Nodo* peek();
    bool isEmpty();
    int size();
    void recorrerStructura(File *graphFile,string nombre);


    string toString();

};



#endif //PRACTICA_1_PILA_H

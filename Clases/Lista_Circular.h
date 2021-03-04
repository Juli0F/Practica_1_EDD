//
// Created by cross on 27/02/21.
//

#ifndef PRACTICA_1_LISTA_CIRCULAR_H
#define PRACTICA_1_LISTA_CIRCULAR_H


#include "../headers/NodoCliente.h"

class Lista_Circular {

private:
    NodoCliente *primero;//primero
    //NodoCliente *primero;
    NodoCliente *ultimo;

public:
    Lista_Circular();

    void setNodCliente(NodoCliente *);
     NodoCliente* getNodoCliente();


     NodoCliente* getUltimo();





     NodoCliente* buscarNodoClienteByIdNodo(int idBuscar);
     NodoCliente* buscarNodoClienteByIdCliente(int idClienteBuscar);

     void add(NodoCliente*);

     void eliminar(NodoCliente*);

     void eliminarByIdNodo(int idNodo);
     void eliminarByIdCliente(int idNodo);



     bool isEmpty();
     int size();
};


#endif //PRACTICA_1_LISTA_CIRCULAR_H

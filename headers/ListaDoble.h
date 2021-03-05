//
// Created by cross on 27/02/21.
//

#ifndef PRACTICA_1_LISTADOBLE_H
#define PRACTICA_1_LISTADOBLE_H


#include "class/NodoCaja.h"
#include "../file/File.h"

class ListaDoble {

private:
    NodoCaja* primero;
    NodoCaja* ultimo;

public:
    ListaDoble();

    NodoCaja* getNodoCajaPrimero();
    NodoCaja* getNodoCajaUltimo();
    void add(NodoCaja*);
    NodoCaja* eliminarByIdNodoCaja(int idNodoCaja);
    NodoCaja* eliminarByIdCaja(int idCaja );

    void recorrerStructura(File *graphFile,string nombre);

};


#endif //PRACTICA_1_LISTADOBLE_H

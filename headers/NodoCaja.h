//
// Created by cross on 27/02/21.
//

#ifndef PRACTICA_1_NODOCAJA_H
#define PRACTICA_1_NODOCAJA_H


#include "class/Caja.h"

class NodoCaja {
private:
    Caja *caja;
    NodoCaja* anterior;
    NodoCaja* siguiente;
    int idNodo;
public:

    NodoCaja(Caja*, NodoCaja*,NodoCaja*, int);

    Caja* getCaja();
    void setCaja(Caja* cajaParam);

    void setAnterior(NodoCaja *primeroParam);
    NodoCaja* getAnterior();

    void setSiguiente(NodoCaja *segundoParam);
    NodoCaja* getSiguiente();

    int getIdNodoCaja();
    void setIdNodoCaja(int idNodoParam);

};


#endif //PRACTICA_1_NODOCAJA_H

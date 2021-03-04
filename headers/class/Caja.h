//
// Created by cross on 26/02/21.
//

#ifndef PRACTICA_1_CAJA_H
#define PRACTICA_1_CAJA_H


#include "Cliente.h"

class Caja {
private:
    int idCaja;
    int tiempoServicio;//tiempo en segundos
    bool estado;
    Cliente *cliente;
public:
    Caja(int idCajaParam, int tiempoParam);

    int getIdCaja();
    int getTiempo();
    bool isEstado();
    Cliente* getCliente();
    void setCliente(Cliente *cliente_);
    void setIdCaja(int idCajaParam);
    void setTiempo(int tiempoParam);
    void setEstado(bool estadoParam);

};


#endif //PRACTICA_1_CAJA_H

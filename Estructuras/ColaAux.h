//
// Created by cross on 4/03/21.
//

#ifndef PRACTICA_1_COLAAUX_H
#define PRACTICA_1_COLAAUX_H


#include "../headers/Cola.h"
#include "../file/File.h"

class ColaAux : public Cola {
private:
    int cont;
    string *cadena;
public:
    void recorrerStructura(File *graphFile);
    string getSubGraph();


};


#endif //PRACTICA_1_COLAAUX_H

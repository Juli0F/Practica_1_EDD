//
// Created by cross on 26/02/21.
//

#ifndef PRACTICA_1_CARRETA_H
#define PRACTICA_1_CARRETA_H


class Carreta {
private:
    int idCarreta;
public:
    Carreta(int);
    int getIdCarreta();
    void setIdCarreta(int idCarretaParam);

    Carreta(Carreta *pCarreta);
};

#endif //PRACTICA_1_CARRETA_H

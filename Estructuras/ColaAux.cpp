//
// Created by cross on 4/03/21.
//

#include "ColaAux.h"
#include <iostream>
using namespace  std;
void ColaAux::recorrerStructura(File *graphFile) {

    NodoCliente *nodo = getNodoCliente();

    string idDesc;

    graphFile->addLinea("\tsubgraph cluster_0 {");

    if (getNodoCliente() == nullptr){

    }else{
        NodoCliente *temp = nodo;
        while (temp != nullptr){
            if (temp->getSiguiente() != nullptr){
                idDesc =  temp->getCliente()->getId() +" -> "+temp->getSiguiente()->getCliente()->getId() ;

            }else{
                idDesc =  temp->getCliente()->getId();

            }
            graphFile->addLinea("\t\t"+idDesc+"\n");





        }
        //cadena = cadena + "\n}";
        cadena->append("\n}",10);
        graphFile->addLinea("\n}");
    }
    cout<<"--> "<<cadena->data()<<endl;

}


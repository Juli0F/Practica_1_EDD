//
// Created by cross on 26/02/21.
//

#include <iostream>
#include "../headers/Cola.h"
#include "string"
#define STRING(num) #num

using namespace std;
Cola::Cola(int idParam) {
    this->id = idParam;
    //this->nodoCliente = nodoParam;
}

void Cola::setNodoCliente(NodoCliente *nodoParam) {
    this->nodoCliente = nodoParam;
}

NodoCliente *Cola::getNodoCliente() {
    return this->nodoCliente;
}

void Cola::encolar(NodoCliente *nodoNuevo) {
    if (nodoCliente == nullptr){
        nodoCliente = nodoNuevo;
    }else{
        NodoCliente *temp = nodoCliente;


        while (temp->getSiguiente() != nullptr){

            cout<<"Temp "<<temp->getSiguiente()->getCliente()->getId()  ;
            temp = temp->getSiguiente();
        }
        temp->setSiguiente(nodoNuevo);

    }

}

NodoCliente* Cola::desEncolar() {
    if (nodoCliente == nullptr){
        return nullptr;
    }else{

        NodoCliente *temp = nodoCliente;
        nodoCliente = temp->getSiguiente();
//cout<<"Desencolar :"<<temp->getCliente()->getId();
        return  temp;
    }
}

NodoCliente *Cola::peek() {
    return nodoCliente;
}

bool Cola::isEmpty() {
    return nodoCliente == nullptr;

}

int Cola::size() {
     int cont = 1;
    if (nodoCliente == nullptr){
        return 0;
    }else{
        NodoCliente *temp = nodoCliente;

        while(temp->getSiguiente() != nullptr){
            cont++;
            temp = temp->getSiguiente();
            cout<<"Recorrer"<<temp->getIdNodoCliente();
        }
        return cont;
    }


}

void Cola::recorrerStructura(File *graphFile,string nombre) {


int id_cola_int = id;
string id_cola(to_string(id_cola_int));
graphFile->addLinea("\tsubgraph cluster_0 {\n\n");
graphFile->addLinea("\t//Cola+ "+nombre+"\n\n");


//label = "Container B";
        //color=blue;
    if (nodoCliente != nullptr) {

        NodoCliente *temp = nodoCliente->getSiguiente();
        while (temp != nullptr) {
            if (temp->getSiguiente() != nullptr) {

                int id_cliente_1 = temp->getCliente()->getId();
                int id_cliente_2 = temp->getSiguiente()->getCliente()->getId();
                string id_cliente1_str(to_string(id_cliente_1));//(STRING(id_cliente_1));
                string id_cliente2_str(to_string(id_cliente_2));//(STRING(id_cliente_2));
                string strFinal = "\t\t\"cliente: " + id_cliente1_str +" cola "+to_string(id)+"\"  -> \"cliente: " + id_cliente2_str +" cola "+to_string(id)+ "\";\n";

                graphFile->addLinea(strFinal);

            }
            temp = temp->getSiguiente();

        }
    }

graphFile->addLinea("\t\tlabel = \"" +nombre+"\";\n");
graphFile->addLinea("\t\tcolor = blue;\n");
graphFile->addLinea("\t}\n");

}

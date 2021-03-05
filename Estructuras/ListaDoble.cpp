//
// Created by cross on 27/02/21.
//

#include "../headers/ListaDoble.h"

ListaDoble::ListaDoble() {
    this->ultimo = nullptr;
    this->primero = nullptr;
}

void ListaDoble::add(NodoCaja *addNodoCaja) {
    if (primero == nullptr){
        this->primero = addNodoCaja;
        this->ultimo = addNodoCaja;
    }else{
        if(addNodoCaja->getIdNodoCaja() <= primero->getIdNodoCaja()){
            addNodoCaja->setSiguiente(primero)  ;
            primero->setAnterior(addNodoCaja);
            primero = addNodoCaja;
        } else if (addNodoCaja->getIdNodoCaja() >= ultimo->getIdNodoCaja()) {
            ultimo->setSiguiente(addNodoCaja);
            addNodoCaja->setAnterior(ultimo);
            ultimo = addNodoCaja;
        } else {
            NodoCaja *aux = primero;
            while(aux->getSiguiente() != nullptr){
                if(addNodoCaja->getIdNodoCaja() >= aux->getIdNodoCaja()) {
                    break;
                }
                aux = aux->getSiguiente();
            }
            NodoCaja *siguiente = aux->getSiguiente();
            aux->setSiguiente(addNodoCaja);
            addNodoCaja->setAnterior(aux);
            addNodoCaja->setSiguiente(siguiente);
            siguiente->setSiguiente(addNodoCaja);
        }
    }

}

NodoCaja *ListaDoble::eliminarByIdNodoCaja(int idNodoCaja) {
    if(primero == nullptr){
        //vacia
    } else {
        //para cuando solo hay uno en la cola
        if(this->primero == this->ultimo && this->primero->getIdNodoCaja() == idNodoCaja) {
            //para eliminarlo los igualo a null
            //aunque creo que debo usar delete
            delete primero,ultimo;
            this->primero = nullptr;
            this->ultimo = nullptr;
        } else {
            NodoCaja *nodoCajaTemp;
            //para cuando hay mas de un elemento en la lista
            //pero cabal el primero es el nodo a eliminar
            if(this->primero->getIdNodoCaja() == idNodoCaja){
                nodoCajaTemp = primero;
                this->primero = this->primero->getSiguiente();

                //libera la memoria, no estoy seguro asi que si algo falla quitar esta linea---------------
                delete nodoCajaTemp;

                //para cuando el nodo a eliminar es el ultimo
            } else if(this->ultimo->getIdNodoCaja() == idNodoCaja) {
                nodoCajaTemp = ultimo;
                this->ultimo = this->ultimo->getAnterior();
                delete nodoCajaTemp;
            } else {

                NodoCaja* aux = this->primero;

                //aux->getSiguiente() != nullptr || aux->getSiguiente()->getIdNodoCaja != idNodoCaja
                while(aux->getSiguiente() != nullptr){
                    if(aux->getIdNodoCaja() == idNodoCaja){
                        break;
                    }
                    aux = aux->getSiguiente();
                }

                NodoCaja* anterior = aux->getAnterior();
                NodoCaja* siguiente = aux->getSiguiente();
                anterior->setSiguiente(siguiente);
                siguiente->setAnterior(anterior);
            }

        }

    }
}

NodoCaja *ListaDoble::eliminarByIdCaja(int idCaja) {
    if(primero == nullptr){
        //vacia
    } else {
        //para cuando solo hay uno en la cola
        if(this->primero == this->ultimo && this->primero->getCaja()->getIdCaja() == idCaja) {
            //para eliminarlo los igualo a null
            //aunque creo que debo usar delete
            delete primero,ultimo;
            this->primero = nullptr;
            this->ultimo = nullptr;
        } else {
            NodoCaja *nodoCajaTemp;
            //para cuando hay mas de un elemento en la lista
            //pero cabal el primero es el nodo a eliminar
            if(this->primero->getCaja()->getIdCaja() == idCaja){
                nodoCajaTemp = primero;
                this->primero = this->primero->getSiguiente();

                //libera la memoria, no estoy seguro asi que si algo falla quitar esta linea---------------
                delete nodoCajaTemp;

                //para cuando el nodo a eliminar es el ultimo
            } else if(this->ultimo->getCaja()->getIdCaja() == idCaja) {

                nodoCajaTemp = ultimo;
                this->ultimo = this->ultimo->getAnterior();
                delete nodoCajaTemp;

            } else {

                NodoCaja* aux = this->primero;

                //aux->getSiguiente() != nullptr || aux->getSiguiente()->getIdNodoCaja != idNodoCaja
                while(aux->getSiguiente() != nullptr){
                    if(aux->getCaja()->getIdCaja() == idCaja){
                        break;
                    }
                    aux = aux->getSiguiente();
                }

                NodoCaja* anterior = aux->getAnterior();
                NodoCaja* siguiente = aux->getSiguiente();
                anterior->setSiguiente(siguiente);
                siguiente->setAnterior(anterior);
            }

        }

    }

}

NodoCaja *ListaDoble::getNodoCajaPrimero() {
    return this->primero;
}

NodoCaja *ListaDoble::getNodoCajaUltimo() {
    return this->ultimo;
}

void ListaDoble::recorrerStructura(File *graphFile,string nombre) {


    if (primero != nullptr){
        graphFile->addLinea("\tsubgraph lista_doble{\n\n");
        graphFile->addLinea("\t\tlabel = \"" +nombre+"\";\n");
graphFile->addLinea("\t\tcolor = blue;\n");

        NodoCaja *temp = primero;
        while (temp != nullptr){
            if (temp == ultimo){
                 int id_cliente_1 = ultimo->getCaja()->getIdCaja();
                int id_cliente_2 = ultimo->getAnterior()->getCaja()->getIdCaja();
                string id_cliente1_str(to_string(id_cliente_1));//(STRING(id_cliente_1));
                string id_cliente2_str(to_string(id_cliente_2));//(STRING(id_cliente_2));
                string strFinal = "\t\t" + id_cliente1_str + " -> " + id_cliente2_str + ";\n";
                string strFinal_retroceso = "\t\t" + id_cliente2_str + " -> " + id_cliente1_str + ";\n";
                graphFile->addLinea(strFinal);
                graphFile->addLinea(strFinal_retroceso);
                break;
            }else{

                int id_cliente_1 = temp->getCaja()->getIdCaja();
                int id_cliente_2 = temp->getSiguiente()->getCaja()->getIdCaja();
                string id_cliente1_str(to_string(id_cliente_1));//(STRING(id_cliente_1));
                string id_cliente2_str(to_string(id_cliente_2));//(STRING(id_cliente_2));
                string strFinal = "\t\t" + id_cliente1_str + " -> " + id_cliente2_str + ";\n";
                string strFinal_retroceso = "\t\t" + id_cliente2_str + " -> " + id_cliente1_str + ";\n";
                graphFile->addLinea(strFinal);
                //graphFile->addLinea(strFinal_retroceso);
                temp = temp->getSiguiente();

            }

        }
graphFile->addLinea("\t}\n");
    }

}

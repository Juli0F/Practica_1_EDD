//
// Created by cross on 27/02/21.
//

#include "ListaDoble.h"

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

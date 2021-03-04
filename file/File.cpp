//
// Created by cross on 3/03/21.
//

#include "File.h"
#include <iostream>
#include <fstream>


void File::crearCarpeta(char *nombre) {

    system(nombre);
}

void File::crearArchivo(string nombre) {




}

void File::crearImg(string nombre) {
    system("dot -Tpng prueba/graph.dot -o img.png");
}

void File::escribirArchivo() {
  file.open("prueba/graph.dot");

  file << "digraph Graph {\n";
}

void File::addLinea(string linea) {
    file << linea;
}

void File::closeFile() {
    file << "}";
    file.close();
}

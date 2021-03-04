//
// Created by cross on 3/03/21.
//

#ifndef PRACTICA_1_FILE_H
#define PRACTICA_1_FILE_H
#include <iostream>
#include <fstream>
#include <string>

using namespace std;
class File {
private:
    string carpeta;
    string archivo;
    string img;
    string linea;
    ofstream file;
public:
    void escribirArchivo();
    void addLinea(string);
    void closeFile();

    void crearCarpeta(char *nombre);
    void crearArchivo(string nombre);
    void crearImg(string nombre);



};


#endif //PRACTICA_1_FILE_H

cmake_minimum_required(VERSION 3.17)
project(practica_1)

set(CMAKE_CXX_STANDARD 14)

add_executable(practica_1 main.cpp Estructuras/pila.cpp headers/pila.h cmake-build-debug/Nodo.h Estructuras/Cola.cpp headers/Cola.h Clases/Cliente.cpp headers/class/Cliente.h Clases/Carreta.cpp headers/class/Carreta.h Clases/Caja.cpp headers/class/Caja.h Clases/Nodo.cpp headers/class/Nodo.h Clases/NodoCliente.cpp headers/class/NodoCliente.h Estructuras/Lista_Circular.cpp headers/Lista_Circular.h Clases/NodoCaja.cpp headers/class/NodoCaja.h Estructuras/ListaDoble.cpp headers/ListaDoble.h Simulador.cpp Simulador.h file/File.cpp file/File.h)
//
// Created by daniela on 02/09/23.
//

#include "Espia.h"
Espia::Espia(int fila, int columna) {
    this->fila = fila;
    this->columna = columna;
}
int Espia::obtenerFila(){
    return this->fila;
}
int Espia::obtenerColumna(){
    return this->columna;
}

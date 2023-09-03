//
// Created by daniela on 01/09/23.
//

#include "Tablero.h"
#include <iostream>
Tablero::Tablero() {
    this->tablero = new char *[TAMANIO_TABLERO];
    for(int i = 0; i < TAMANIO_TABLERO; i++){
        this->tablero[i] = new char[TAMANIO_TABLERO];
        for(int j = 0; j < TAMANIO_TABLERO;j++){
            this->tablero[i][j] = ' ';
        }
    }
}
char  Tablero::obtenerStringTablero(int fila, int columna){
    return this->tablero[fila][columna];
}
void Tablero::setearCaracer(char caracterNuevo, int fila, int columna){
    this->tablero[fila][columna] = caracterNuevo;
}

void Tablero::imprimirTablero() {
    for(int i = 0; i < TAMANIO_TABLERO; i++ ){
        for(int j = 0; j < TAMANIO_TABLERO; j++){
            std::cout<< this->tablero[i][j]<<' ';
        }
        std::cout<<std::endl;
    }
}
Tablero::~Tablero(){
    for(int i = 0;i < TAMANIO_TABLERO;i++){
        delete[] tablero[i];
    }
    delete[] tablero;
}

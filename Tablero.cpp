//
// Created by daniela on 26/08/23.
//
#include <iostream>
#include "Tablero.h"

Tablero::Tablero(int filas, int columnas) {
    this->filas = filas;
    this->columnas = columnas;
    this->casilleros = new Casillas*[filas];
    for(int i = 0; i < this->filas;i++){
        this->casilleros[i] = new Casillas[tablero->columnas];
    }


}
void Tablero::mostrar()const {
    for(int i = 0; i < this->filas; i++){
        for(int j = 0; j < this->columnas; j++){
            std::cout<< this->casilleros[i][j].obtenerContenido()<<" ";
        }
        std::cout<<std::endl;
    }
}
Tablero::~Tablero() {
    for(int i = 0; i < this->filas; i++){
        delete[] casilleros[i];
    }
    delete[]casilleros;

}

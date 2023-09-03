//
// Created by daniela on 01/09/23.
//

#include "Tesoro.h"
Tesoro::Tesoro(int fila, int columna) {
    this->fila = fila;
    this->columna = columna;
    this->espiasTurnosRestantes = 0;
    this->activo = true;
}

int Tesoro::getFila() {
    return this->fila;
}
int Tesoro::getColumna() {
    return this->columna;
}
bool Tesoro::estaRecuperandoEspia() {
    if(this->espiasTurnosRestantes > 0){
        return this->espiasTurnosRestantes;
    }
}
void Tesoro::inhabilitarCasillero(){
    this->espiasTurnosRestantes = TURNOSESPIAS;
}
void Tesoro::descontarTurnosEspias() {
    if(this->espiasTurnosRestantes > 0){
        this->espiasTurnosRestantes--;
    }
}
bool Tesoro::estaActivo() {
    return this->activo;
}

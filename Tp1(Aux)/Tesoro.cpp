//
// Created by daniela on 01/09/23.
//

#include "Tesoro.h"
Tesoro::Tesoro(int fila, int columna, std::string simbolo) {
    this->fila = fila;
    this->columna = columna;
    this->turnoHabilitado = 0;
    this->estado = true;
    this->simbolo = simbolo;
    this->turnoEncontrado = 0;
}
Tesoro::Tesoro() {
    this->fila = 0;
    this->columna = 0;
    this->turnoHabilitado = 0;
    this->estado = true;
}
void Tesoro::setearTurnoEncontrado(int turno){
    this->turnoEncontrado = turno;
    this->turnoHabilitado = this->turnoEncontrado + TURNOSINHABILITADO;
   desactivarTesoro();
}
int Tesoro::getTurnoEncontrado(){
    return this->turnoEncontrado;
}

void Tesoro::setearSimbolo(std::string simboloNuevo){
    this->simbolo = simboloNuevo;
}
void Tesoro::setearFila(int filaNueva){
    this->fila = filaNueva;
}
void Tesoro::setearColumna(int columnaNueva){
    this->columna = columnaNueva;
}
int Tesoro::getFila() {
    return this->fila;
}

int Tesoro::getColumna() {
    return this->columna;
}
std::string Tesoro::getSimbolo(){
    return this->simbolo;
}


bool Tesoro::estaActivo() {
    return this->estado;
}
void Tesoro::desactivarTesoro(){
    this->estado = false;
}
void Tesoro::activarTesoro(){
    this->estado = true;
}
Tesoro::~Tesoro(){
}

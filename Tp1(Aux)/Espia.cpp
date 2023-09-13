//
// Created by daniela on 02/09/23.
//

#include "Espia.h"
Espia::Espia(){

}
Espia::Espia(int fila, int columna, std::string simbolo) {
    this->fila = fila;
    this->columna = columna;
    this->simbolo = simbolo;
}
int Espia::obtenerFila(){
    return this->fila;
}
int Espia::obtenerColumna(){
    return this->columna;
}
void Espia::setearFila(int filaNueva){
    this->fila = filaNueva;
}
void Espia::setearColumna(int columnaNueva) {
    this->columna = columnaNueva;
}
const std::string &Espia::getSimbolo() const {
    return simbolo;
}
void Espia::setearSimboloEspia(std::string nuevoSimbolo){
    this->simbolo = nuevoSimbolo;
}
void Espia::eliminar(){
    this->simbolo = " ";
    this->fila = 0;
    this->columna = 0;
}
Espia::~Espia() {}
//
// Created by daniela on 01/09/23.
//
#include "Jugador.h"
Jugador::Jugador(char jugadorId) {
    this->simbolo = jugadorId;
    this->tesoroRestantes = CANTIDAD_TESORO;
    this->tesoros = new Tesoro *[CANTIDAD_TESORO];
    this->espia = new Espia * [CANTIDAD_TESORO];

}
void Jugador::aumentarTesorosRestantes() {
    this->tesoroRestantes++;
}
void Jugador::setearTesorosRestantes(int numero){
    this->tesoroRestantes = numero;
}
void Jugador::colocarTesoro(char **tablero, int fila, int columna, int nroTesoro) {
    if(tablero[fila][columna] != ' '){
        tesoros[nroTesoro] = new Tesoro(fila, columna);
        tablero[fila][columna] = this->simbolo;
    }
}
char Jugador::obtenerSimbolo() {
    return this->simbolo;
}
Espia** Jugador::obtenerEspias(){
    return this->espia;
}
Tesoro** Jugador::obtenerTesoros() {
    return this->tesoros;
}
int Jugador::obtenerNumerosTesororsRestantes(){
    return this->tesoroRestantes;
}
Jugador::~Jugador(){
    delete[] this->tesoros;
    delete[] this->espia;
}

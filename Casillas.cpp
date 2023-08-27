//
// Created by daniela on 26/08/23.
//

#include "Casillas.h"
Casillas::Casillas(){
    this->caracter = 'X';
    this->estado = 0;
    this->caracterJugador1 = '1';
    this->caracterJugador2 = '2';
}
void Casillas::colocarTesoro() {
    if(this->estado == 1){
        this->caracter = 'T';
    }
}
char Casillas::obtenerContenido() {
    return caracter;
}
void Casillas::colocarEspias() {
    if(estado == 2){
        this->caracter = 'E';
    }
}
Casillas::~Casillas(){

}

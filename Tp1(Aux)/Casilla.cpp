//
// Created by daniela on 04/09/23.
//

#include "Casilla.h"
#include <string>

enum estado{
    Habilitada,
    Inhabilitada,
    Ocupada,
};
Casilla::Casilla(){
    this->caracter =" ";
    this->estado = Habilitada;

}
void Casilla::setContenido(std::string caracterNuevo) {
    this->caracter = caracterNuevo;
}
std::string Casilla::obtenerContenido() {
    return caracter;
}
void Casilla::colocarEspias() {
    if(estado == 1){
        this->setContenido("1") ;
    }
    else if(estado == 2){
        this->setContenido("2");
    }
}
void Casilla::colocarTesoro(std::string simbolo){
    if(estado == 3){
        this->setContenido( simbolo);
    }
}
void Casilla::inhabilitar(){
    if(estado == 4){
        this->setContenido("X");
    }
}
Casilla::~Casilla(){

}

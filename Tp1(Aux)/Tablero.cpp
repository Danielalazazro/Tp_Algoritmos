//
// Created by daniela on 01/09/23.
//

#include "Tablero.h"
#include <iostream>
#include <string>
Tablero::Tablero() {
    this->casillas =  new Casilla*[TAMANIO_TABLERO];
    for(int i = 0; i < TAMANIO_TABLERO; i++){
        this->casillas[i] =  new Casilla[TAMANIO_TABLERO];
        for(int j = 0; j < TAMANIO_TABLERO;j++){
            this->casillas[i][j].setContenido(" ");
        }
    }
}
std::string Tablero::obtenerStringTablero(int fila, int columna){
    return this->casillas[fila][columna].obtenerContenido();
}
void Tablero::setearCaracer(std::string caracterNuevo, int fila, int columna){
    this->casillas[fila][columna].setContenido(caracterNuevo);
}
void Tablero::imprimirTableroEnArchivo(){
    std::string tablero = "";
    obtenerTableroJugador("1",tablero);
    obtenerTableroJugador("2",tablero);
    std::ofstream archivo("Tablero.txt");
    if( archivo.fail()){
        std::cout<<"No se pudo abrir el archivo"<<std::endl;
    }
    archivo<<tablero;
    archivo.close();
}
void Tablero::obtenerTableroJugador(std::string jugador, std::string &tableroTexto){
    tableroTexto += "-----------------------------------------\n";
    for(int i = 0; i < TAMANIO_TABLERO; i++){
        tableroTexto += "|";
        for(int j = 0; j < TAMANIO_TABLERO; j++){
            if((this->casillas[i][j].obtenerContenido() == "A" || this->casillas[i][j].obtenerContenido() == "1" || this->casillas[i][j].obtenerContenido() == "X") && (jugador=="1")){
                tableroTexto += this-> casillas[i][j].obtenerContenido()+"|";
            }
            else if((this->casillas[i][j].obtenerContenido() == "B" || this->casillas[i][j].obtenerContenido() == "2" ||
                                                                      this->casillas[i][j].obtenerContenido() == "X") && (jugador == "2")){
                tableroTexto += this->casillas[i][j].obtenerContenido()+"|";
            }else{
                tableroTexto += " |";
            }
        }
        tableroTexto += "\ṇ-----------------------------------------\n";
    }
}
void Tablero::imprimirTablero(std::string  jugador  ) {
    std::cout << "-----------------------------------------\n";
    for(int i = 0; i < TAMANIO_TABLERO; i++ ){
        std::cout << "|";
        for(int j = 0; j < TAMANIO_TABLERO; j++){
            if( (this->casillas[i][j].obtenerContenido() == "A"  || this->casillas[i][j].obtenerContenido() == "1" ||this->casillas[i][j].obtenerContenido() == "X")  && (jugador == "1")){
                std::cout<<this->casillas[i][j].obtenerContenido()<<"|";
            }
            else if ((this->casillas[i][j].obtenerContenido() == "B"  || this->casillas[i][j].obtenerContenido() == "2" ||
                    this->casillas[i][j].obtenerContenido() == "X") && (jugador == "2")  ){
                std::cout<<this->casillas[i][j].obtenerContenido()<<"|";
            }
            else{
                std::cout<<" "<<"|";
            }
        }
        std::cout << "\ṇ-----------------------------------------\n";
    }
}
Tablero::~Tablero(){
    for(int i = 0;i < TAMANIO_TABLERO;i++){
        delete[] this->casillas[i];
    }
    delete[] this->casillas;
}

void Tablero::insertarTesoro(Tesoro tesoro) {
    std::string unTesoroSimbolo = tesoro.getSimbolo();
    this->casillas[tesoro.getFila()][ tesoro.getColumna()].setContenido(unTesoroSimbolo);
}
void Tablero::insertarEspias(Espia espia) {
    std::string simboloESpia = espia.getSimbolo();
    this->casillas[espia.obtenerFila()][espia.obtenerColumna()].setContenido(simboloESpia);
}

void Tablero::moverTesoro(Tesoro tesoro, int filaFutura, int columnaFutura) {
    int i = 1;
    bool seRealizoElCambio = false;
    // Se mueve en forma horizontal
    if(filaFutura == tesoro.getFila() && 0 <= columnaFutura && columnaFutura < TAMANIO_TABLERO ){
        this->casillas[tesoro.getFila()][tesoro.getColumna()].setContenido(" ");
        this->casillas[filaFutura][columnaFutura].setContenido(tesoro.getSimbolo());
    }
    // Se mueve en forma vertical
    else if(0 <= filaFutura < TAMANIO_TABLERO && columnaFutura == tesoro.getColumna() ){
        this->casillas[tesoro.getFila()][tesoro.getColumna()].setContenido(" ");
        this->casillas[filaFutura][columnaFutura].setContenido(tesoro.getSimbolo());
    }
    // se mueve en forma diagonal
    while (i < TAMANIO_TABLERO && !seRealizoElCambio){
        if((filaFutura  == tesoro.getFila() + i) && (tesoro.getColumna() + i == columnaFutura)){
            this->casillas[tesoro.getFila()][tesoro.getColumna()].setContenido(" ");
            this->casillas[filaFutura][columnaFutura].setContenido(tesoro.getSimbolo());
            seRealizoElCambio = true;
        }
        i++;
    }
}


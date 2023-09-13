//

#include "Jugador.h"
Jugador::Jugador(std::string simbolo, std::string simboloTesoro) {
    this->cantidadTesoroEncontrados = 0;
    this->tesoros = new Tesoro[CANTIDAD_TESORO];
    this->espias =  new Espia[CANTIDAD_ESPIAS_MAXIMO];
    this->cantidadEspiasActual = 0;
    this->simbolo = simbolo;
    this->simboloTesoro = simboloTesoro;
}
std::string Jugador::getSimbolo(){
    return this->simbolo;
}
std::string Jugador::getSimboloTesoro(){
    return this->simboloTesoro;
}
void Jugador::guardarPosTesoro(int fila , int columna, int numeroTesoro){
   Tesoro tesoro = this->tesoros[numeroTesoro];
   tesoro.setearFila(fila);
   tesoro.setearColumna(columna);
   tesoro.setearSimbolo(this->getSimboloTesoro());
   this->tesoros[numeroTesoro] = tesoro;
}
void Jugador::guardarPosEspias(int fila, int columna){
    Espia espia = this->espias[this->cantidadEspiasActual];
    espia.setearFila(fila);
    espia.setearColumna(columna);
    this->espias[this->cantidadEspiasActual] = espia;
    this->espias[this->cantidadEspiasActual].setearSimboloEspia(this->getSimbolo());
    this->cantidadEspiasActual++;
}
void Jugador::aumentarCantidadTesorosEncontrados() {
    this->cantidadTesoroEncontrados++;
}
int Jugador::obtenerCantidadTesorosEncontrados(){
    return this->cantidadTesoroEncontrados;
}
Espia* Jugador::obtenerEspias(){
    return this->espias;
}
Espia Jugador::obtenerEspia(int fila, int columna){
    for(int i = 0 ; i < this->cantidadEspiasActual; i++){
        Espia espia = this->espias[i];
        if(espia.obtenerFila() == fila && espia.obtenerColumna() == columna){
            return espia;
        }
    }
}
Tesoro* Jugador::obtenerTesoros() {
    return this->tesoros;
}
int Jugador::obtenerPosicionDelTesoro(int fila, int columna){
    for(int i = 0; i < TESOROS; i++){
        Tesoro tesoro = this->tesoros[i];
        if(tesoro.getFila() == fila && tesoro.getColumna() == columna){
            return i;
        }
    }
}
int Jugador::obtenerPosicionEspia(int fila, int columna){
    for(int i = 0; i < CANTIDAD_ESPIAS_MAXIMO; i++){
        Espia espia = this->espias[i];
        if(espia.obtenerFila() == fila && espia.obtenerColumna() == columna){
            return i;
        }
    }
}
Jugador::~Jugador(){
    delete[] this->tesoros;
    delete[] this->espias;
}
void Jugador::moverTesoro(int filaActual, int columnaActual, int filaFutura, int columnaFutura) {
    int i = 1;
    bool seEstablecioPosicion = false;
    int posITesoro = obtenerPosicionDelTesoro(filaActual, columnaActual );
    if(filaActual == filaFutura && 0 <= columnaActual <TAMANIO_TABLERO){
        tesoros[posITesoro].setearFila(filaFutura);
        tesoros[posITesoro].setearColumna(columnaFutura);
    }
    else if(columnaActual == columnaFutura && 0<= filaFutura < TAMANIO_TABLERO){
        tesoros[posITesoro].setearFila(filaFutura);
        tesoros[posITesoro].setearColumna(columnaFutura);
    }
    else {
        std::cout<<"posicion no valida para mover el tesoro"<<std::endl;
    }
    while (i < TAMANIO_TABLERO && !seEstablecioPosicion){
        if(filaActual  + i == filaFutura && columnaActual + i == columnaFutura){
            tesoros[posITesoro].setearFila(filaFutura);
            tesoros[posITesoro].setearColumna(columnaFutura);
            seEstablecioPosicion = true;
        }
        i++;
    }

}
Tesoro Jugador::obtenerTesoro(int fila, int columna) {
    for(int i = 0; i < TESOROS; i++){
        Tesoro tesoro = this->tesoros[i];
        if(tesoro.getFila() == fila && tesoro.getColumna() == columna ){
            return tesoro;
        }
    }
}

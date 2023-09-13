//
// Created by daniela on 02/09/23.
//
#include "TesoroBinario.h"
#include <iostream>
TesoroBinario::TesoroBinario() {
    this->tablero =  new Tablero();
    this->jugador1 = new Jugador("1","A");
    this->jugador2 = new Jugador("2","B");
    this->turno = 0;
}
void TesoroBinario::jugar(){
    int opcion = 0;
    bool continuarJuego = true;
    inicilizarTesoros();
    while (continuarJuego){
        std::cout<<"Estan son las opciones del juego:"<<std::endl;
        std::cout<<"Opcion 1: Desea ingresar un espias"<<std::endl;
        std::cout<<"Opcion 2: Desea mover un tesoro (solo se puede mover de forma horizontal, vertical y en forma diagonal)"<<std::endl;
        std::cin>>opcion;
        if(opcion == 1 ){
            completarPosicionesEspiaSegunTipoJugaor();
        }
        else if(opcion == 2) {
            moverTesoroSegunTipoJugador();
        }
        if(this->jugador1->obtenerCantidadTesorosEncontrados() == TESOROS){
            std::cout<<"Gana el jugador 1ª"<<std::endl;
            continuarJuego = false;
        }
        else if(this->jugador2->obtenerCantidadTesorosEncontrados() == TESOROS){
            std::cout<<"Gana el jugador 2ª"<<std::endl;
            continuarJuego = false;
        }
    }
}
void TesoroBinario::moverTesoroSegunTipoJugador(){
    if(this->turno % 2 == 0){
        std::cout<<"El jugador 1ª mueve un tesoro(solo puedes moverlo de forma horizontal, vertical y en forma diagonal): "<<std::endl;
        std::cout<<"EL turno es: "<< this->turno + 1<<std::endl;
        moverTesoro(this->jugador1 );
        tablero->imprimirTablero(this->jugador1->getSimbolo());
    }
    else if(this->turno % 2 != 0){
        std::cout<<"El jugador 2ª mueve un tesoro (solo puedes moverlo de forma horizontal, vertical y en forma diagonal): "<<std::endl;
        std::cout<<"EL turno es: "<< this->turno + 1<<std::endl;
        moverTesoro(this->jugador2);
        tablero->imprimirTablero(this->jugador2->getSimbolo());
    }
    this->tablero->imprimirTableroEnArchivo();
    this->turno++;
}
void TesoroBinario::completarPosicionesEspiaSegunTipoJugaor(){
    if(this->turno % 2 == 0){
        std::cout<<"Jugador 1ª ingresa un espia por turno "<<std::endl;
        std::cout<<"El turno es :"<< this->turno + 1<<std::endl;
        solicitarPosicionesEspias(this->jugador1, this->jugador2);
        tablero->imprimirTablero("1");
    }
    else if(this->turno % 2 != 0){
        std::cout<<"Jugador 2ª ingresa un espia por turno"<<std::endl;
        std::cout<<"El turno es: "<< this->turno + 1<<std::endl;
        solicitarPosicionesEspias(this->jugador2, this->jugador1);
        tablero->imprimirTablero("2");
    }
    this->tablero->imprimirTableroEnArchivo();
    this->turno++;
}
void TesoroBinario::analizarCasillasParaLaPocionDelEspia(std::string simbolo,  Jugador* otroJugador,Jugador* jugadorActual, int filaEspia, int columnaEspia){
    if((simbolo == "1" && jugadorActual->getSimbolo() == "1") || (simbolo == "2" && jugadorActual->getSimbolo() == "2") ){
        std::cout<<"En esta casilla ya tienes un espia, no puedes ingresar un espia"<<std::endl;
    }
    else if((simbolo == "A" && jugadorActual->getSimbolo() == "1") || (simbolo == "B" && jugadorActual->getSimbolo() == "2")){
        std::cout<<"En esta casilla tenes un tesoro no puedes ingresar un espia"<<std::endl;
    }
    else if((simbolo == "1" && jugadorActual->getSimbolo() == "2") || (simbolo == "2" && jugadorActual->getSimbolo() == "1")){
        std::cout<<"En esta casilla se encuentra un espia del  1ª jugador ambos espias quedan eliminados "<<std::endl;
        int posicionEspia = otroJugador->obtenerPosicionEspia(filaEspia,columnaEspia);
        otroJugador->obtenerEspias()[posicionEspia].eliminar();
        this->tablero->setearCaracer(otroJugador->obtenerEspias()[posicionEspia].getSimbolo(),filaEspia,columnaEspia);
    }
    else if((simbolo == "B" && jugadorActual->getSimbolo() == "1") || (simbolo=="A" && jugadorActual->getSimbolo() == "2")){
        std::cout<<"Encontraste un tesoro jugador 1"<<std::endl;
        jugadorActual->aumentarCantidadTesorosEncontrados();
        int posTesoro = otroJugador->obtenerPosicionDelTesoro(filaEspia,columnaEspia);
        otroJugador->obtenerTesoros()[posTesoro].setearTurnoEncontrado(this->turno);
        this->tablero->setearCaracer("X",filaEspia,columnaEspia);
    }
}
void TesoroBinario::solicitarPosicionesEspias(Jugador* jugadorActual,Jugador* otroJugador){
    int filaEspia = 0;
    int columnaEspia = 0;
    std::cout<<"Ingrese la fila del espias: "<<std::endl;
    std::cin>>filaEspia;
    std::cout<<"Ingrese la columna del espias: "<<std::endl;
    std::cin>>columnaEspia;
    filaEspia -= 1;
    columnaEspia -= 1;
    std::string simboloActual = this->tablero->obtenerStringTablero(filaEspia, columnaEspia);
    if(simboloActual != " "){
        analizarCasillasParaLaPocionDelEspia(simboloActual,otroJugador,jugadorActual,filaEspia,columnaEspia);
    }
    else if(simboloActual == " "){
        jugadorActual->guardarPosEspias(filaEspia,columnaEspia);
        this->tablero->insertarEspias(jugadorActual->obtenerEspia(filaEspia,columnaEspia));
    }
    if(jugadorActual->obtenerCantidadTesorosEncontrados() > 0){
        Tesoro* tesoros = otroJugador->obtenerTesoros();
        for(int i = 0; i < TESOROS; i++){
            Tesoro tesoro = tesoros[i];
            if(tesoro.estaActivo() == false && (tesoro.getTurnoEncontrado() + TURNOSINHABILITADO) <= this->turno ){
                tesoro.activarTesoro();
                this->tablero->setearCaracer(tesoro.getSimbolo(),tesoro.getFila(),tesoro.getColumna());
            }
        }
    }
}
void TesoroBinario::moverTesoro(Jugador* jugadorActual){
    int filaActual = 0;
    int columnaActual = 0;
    int filaAmover = 0;
    int columnaAmover = 0;
    int contador = 0;
    bool encontrado = false;
    Tesoro tesoro ;
    while (contador < TESOROS && !encontrado ){
        std::cout<<"Ingrese la fila del tesoro actual:"<<std::endl;
        std::cin>>filaActual;
        std::cout<<"Ingrese la columna del tesoro actual: "<<std::endl;
        std::cin>>columnaActual;
        filaActual -=1;
        columnaActual -= 1;
        std::string simboloActual = this->tablero->obtenerStringTablero(filaActual,columnaActual);
        if((simboloActual != "A") && (simboloActual != "B")){
            std::cout<< "En este casillero no se encuentra ningun tesoro"<<std::endl;
        }
        else if((simboloActual == "A") || (simboloActual == "B")){
            tesoro = jugadorActual->obtenerTesoro(filaActual,columnaActual);
            encontrado = true;
        }
        contador++;
    }
    std::cout<<"Ingrese la fila a mover el tesoro: "<<std::endl;
    std::cin>>filaAmover;
    std::cout<<"Ingrese la columna a mover el tesoro: "<<std::endl;
    std::cin>>columnaAmover;
    filaAmover -= 1;
    columnaAmover -= 1;
    std::string simboloAmover = this->tablero->obtenerStringTablero(filaAmover, columnaAmover);
    if((simboloAmover == "A" && tesoro.getSimbolo() == "A") || (simboloAmover == "B" && tesoro.getSimbolo() == "B")){
        std::cout<<"No se puede mover este tesoro porque ya tienes un tesoro en ese posicion"<<std::endl;
    }
    else if((simboloAmover == "A" && tesoro.getSimbolo() == "B") || (simboloAmover == "B" && tesoro.getSimbolo() == "A" ) ){
       std::cout<<"Tu tesoro fue encontrado por el tesoro del jugador contrario"<<std::endl;
       std::cout<<"Puedes mandar un espia para recuperarlo"<<std::endl;
    }
    this->tablero->moverTesoro( tesoro,filaAmover,columnaAmover);
    jugadorActual->moverTesoro(filaActual, columnaActual, filaAmover, columnaAmover);

}
void TesoroBinario::solicitarPosicionesDeLosTesoros(Jugador* jugadorAtual){
    int filaTesoro = 0;
    int columnaTesoro = 0;
    int i = 0;
    while (i < TESOROS){
        std::cout<<"Ingrese la fila del tesoro "<<i+1<<": "<<std::endl;
        std::cin>>filaTesoro;
        std::cout<<"Ingrese la columna del tesoro "<<i+1<<": "<<std::endl;
        std::cin>>columnaTesoro;
        filaTesoro -= 1;
        columnaTesoro -= 1;
        jugadorAtual->guardarPosTesoro(filaTesoro ,columnaTesoro ,i);
        this->tablero->insertarTesoro(jugadorAtual->obtenerTesoro(filaTesoro ,columnaTesoro));
        i++;
    }
}
void TesoroBinario::inicilizarTesoros(){
    std::cout<<"Bienvenido al juego del TesoroBinario: "<<std::endl;
    std::cout<<"Comienza el 1ª jugador, ingresando las posiciones de los tesoros "<<std::endl;
    solicitarPosicionesDeLosTesoros(this->jugador1);
    std::cout<<"Continua el 2ª jugador, ingresando las posiciones de los tesoros "<<std::endl;
    solicitarPosicionesDeLosTesoros(this->jugador2);
}
TesoroBinario::~TesoroBinario() {
    delete jugador1;
    delete jugador2;
    delete tablero;
}

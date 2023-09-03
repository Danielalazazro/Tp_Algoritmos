//
// Created by daniela on 02/09/23.
//

#include "Juego.h"
#include <iostream>
Juego::Juego() {
    this->tablero =  new Tablero();
    this->juegador1 = new Jugador('1');
    this->jugador2 = new Jugador('2');
    this->turno = 400;
}
void inicilizarTesoros(){

}
void Juego::jugar() {
    tablero->imprimirTablero();
    Tesoro** tesoros;
    while (true){
        Jugador* jugadorActual = NULL;
        Jugador* otroJugador = NULL;

        if(this->turno % 2 == 0){
            jugadorActual = this->juegador1;
            std::cout<<"Tuerno de jugador actual "<< jugadorActual->obtenerSimbolo();
        }
        else if(this->turno % 2 != 0){
            Jugador* otroJugador = this->jugador2;
            std::cout<<"Turno de jugador actual es: "<< otroJugador->obtenerSimbolo();
        }
        //COlocar espia en una casilla
        int filaEspia;
        int columnaEspia;
        std::cout<<"Ingrese la fila donde colocar el espia:  "<<std::endl;
        std::cin>>filaEspia;
        std::cout<<"Ingrese la columna donde colocar el espia: "<<std::endl;
        std::cin>>columnaEspia;
        if(filaEspia >= 0 && filaEspia < TAMANIO_TABLERO && columnaEspia >= 0 && columnaEspia < TAMANIO_TABLERO ){
            if(tablero->obtenerStringTablero(filaEspia, columnaEspia) == ' '){
                //COlocar el espia en el tablero
                tablero->setearCaracer(filaEspia, columnaEspia,'E');
                jugadorActual->obtenerEspias()[this->turno - 1] = new Espia(filaEspia, columnaEspia);
                //Verificar si se encuentra un tesoro
                for(int i = 0; i < CANTIDAD_TESORO; i++){
                    tesoros = otroJugador->obtenerTesoros();
                    Tesoro* tesoro = tesoros[i];
                    bool estaActivo = tesoro->estaActivo();
                    if(estaActivo == true && tesoro->getFila() == filaEspia && tesoros[i]->getColumna() == columnaEspia){
                        std::cout<<"EL espia enocntro el tesoro !, recuperando en 5 turnos"<<std::endl;
                        tesoro->inhabilitarCasillero();
                        tablero->setearCaracer('X',filaEspia,columnaEspia );
                        break;
                    }
                }
            }
        }
        else {
            std::cout<<"Movimiento invalido .Intentalo de nuevo"<<std::endl;
            continue;
        }
        //MOver tesoro
        int opcion;
        std::cout<<"1 Mover tesoro "<<std::endl;
        std::cout<<"2 Pasar al siguiente tuerno "<<std::endl;
        std::cout<<"Eligue una opcion "<<std::endl;
        std::cin>>opcion;
        if(opcion == 1){
            int tesoroIdx;
            std::cout<<"Eligue un tesoro de(0- 3)"<<std::endl;
            std::cin>>opcion;
            if(tesoroIdx >= 0 && tesoroIdx < CANTIDAD_TESORO && jugadorActual->obtenerNumerosTesororsRestantes() > 0){
                int nuevaFila;
                int nuevaColumna;
                std::cout<<"Ingrese la nueva fila del tesoro"<<std::endl;
                std::cin>>nuevaFila;
                std::cout<<"Ingrese la nueva columna del tesoro"<<std::endl;
                std::cin>>nuevaColumna;
                //Vlidar movimiento del tesoro
                if(nuevaFila >= 0 && nuevaFila < TAMANIO_TABLERO && nuevaColumna >= 0 && nuevaColumna <TAMANIO_TABLERO && tablero->obtenerStringTablero(nuevaFila, nuevaFila) == ' ' ){
                    //MOver el tesoro
                    tablero->obtenerStringTablero(jugadorActual->obtenerTesoros()[tesoroIdx]->getFila(), jugadorActual->obtenerTesoros()[tesoroIdx]->getColumna()) == ' ';
                    char simboloNuevotablero = tablero->obtenerStringTablero(nuevaFila, nuevaColumna) ;
                    simboloNuevotablero = jugadorActual->obtenerSimbolo();
                    int filaActual = jugadorActual->obtenerTesoros()[tesoroIdx]->getFila();
                    filaActual =   nuevaFila;
                    int columnaActual = jugadorActual->obtenerTesoros()[tesoroIdx]->getColumna();
                    columnaActual= nuevaColumna;
                    //Verificar si el tesoro se encuentrae en el nuevo lugar
                    for(int i = 0; i <CANTIDAD_TESORO;i++ ){
                        Tesoro* otroTesoro = otroJugador->obtenerTesoros()[i];
                        if(otroTesoro->estaActivo() && otroTesoro->getFila() == nuevaFila && otroTesoro->getColumna() == nuevaColumna){
                            std::cout<<"El tesoro se movio a una casilla con un tesoro enemigo"<<std::endl;
                            std::cout<<"Envia un espia para recuperarlo"<<std::endl;
                            break;
                        }
                    }
                }
                else{
                    std::cout<<"Movimiento no valido para el tesoro.Intentelo de nuevo "<<std::endl;
                    continue;
                }
            }
            else{
                std::cout<<"NO tienes tesoros restantes para mover "<<std::endl;
            }
        }
        else if(opcion == 2){
            //Pasar al siguiente turno
            this->turno++;
            jugadorActual->setearTesorosRestantes(0);
            for(int i = 0; i< CANTIDAD_TESORO; i++){
                if(jugadorActual->obtenerTesoros()[i]->estaActivo()){
                    jugadorActual->aumentarTesorosRestantes();
                }
            }

        }
        if(jugadorActual->obtenerTesoros() == 0 || otroJugador->obtenerTesoros() == 0){
            std::cout<<"!El juego ha terminado"<<std::endl;
            if(juegador1->obtenerTesoros() == 0){
                std::cout<<"El jugador 2 gana "<<std::endl;
            }
            else{
                std::cout<<"El jugador uno gana"<<std::endl;
            }
            break;
        }




    }
}
Juego::~Juego() {
    delete juegador1;
    delete jugador2;
    delete tablero;
}

//
// Created by daniela on 01/09/23.
//
#ifndef TP1_AUX__JUGADOR_H
#define TP1_AUX__JUGADOR_H
#include "Tablero.h"
#include "Tesoro.h"
#include "Espia.h"
#include <iostream>
static const int CANTIDAD_TESORO = 4;
static const int CANTIDAD_ESPIAS_MAXIMO = 400;

class Jugador {
private:
    int cantidadTesoroEncontrados;
    int cantidadEspiasActual;
    Tesoro* tesoros;
    Espia* espias;
    std::string simbolo;
    std::string simboloTesoro;
public:
    /*
     * Construstor de jugador , el cual se le pasa por parametro el simbolo del tipo de jugador.
     */
    Jugador(std::string simbolo,std::string simboloTesoro);
    /*
     *En este metodo te devuelve el simbolo de cada jugador.
     */
    std::string getSimbolo();
    /*
     * En este metodo se guarda la posicion del tesoro y se recibe como parametro la fila ,la columna y el numero de posicion del tesoro en el vector y
     * el simbolo del mismo.
     */
    void guardarPosTesoro(int fila , int columna, int numeroTesoro);
    /*
     * Este metodo devulve la cantidad de tesoros encontrados
     */
    int obtenerCantidadTesorosEncontrados();
    /*
     *En este metodo aumenta la cantidad de tesoros encontrados
     */
    void aumentarCantidadTesorosEncontrados();
    /*
     *En este metodo se obtiene el vector de espias
     */
    Espia * obtenerEspias();
    /*
     *En este metodo se obtiene el vector de tesoros
     */
    Tesoro* obtenerTesoros();
    /*
     * En este metodo se gurdad la posicion de los espias y se recibe por parametro la fila , la columna y el simbolo del mismo.
     */
    void guardarPosEspias(int fila, int columna);
    /*
     * En este metodo se obtiene la posicion de un espia segun su posicion y se recibe los por parametro.
     */
    int obtenerPosicionEspia(int fila, int columna);
    /*
     * En este metodo se obtiene el tesoro segun la posicion en el tablero.
     */
    int obtenerPosicionDelTesoro(int fila, int columna);
    /*
     * En este metodo se mueve el tesoro de la fila y columna actual ; fila y columna futura.
     */
    void moverTesoro(int filaActual, int columnaActual, int filaFutura, int columnaFutura);
    /*
     * En este metodo se obtiene el tesoro segun la fila y la columna.
     */
    Tesoro obtenerTesoro(int fila, int columna);
    /*
     * En este metodo se obtiene un espia con la posicion.
     */
    Espia obtenerEspia(int fila, int columna);
    /*
     * El destructor del jugador , en este metodo se elimina el vector el tesoro y el de espia.
     */
    ~Jugador();

    std::string getSimboloTesoro();
};


#endif //TP1_AUX__JUGADOR_H

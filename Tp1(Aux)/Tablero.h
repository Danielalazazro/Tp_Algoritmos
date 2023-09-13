//
// Created by daniela on 01/09/23.
//

#ifndef TP1_AUX__TABLERO_H
#define TP1_AUX__TABLERO_H

#include "Tesoro.h"
#include "Espia.h"
#include "Casilla.h"
#include <fstream>
static int const TAMANIO_TABLERO = 20;
class Tablero {
private:
    Casilla** casillas;

public:
    /*
     * Constructor del tablero
     */
    Tablero();
    /*
     * Este metodo imprime el tablero y recibe como parametro al jugador
     */
    void imprimirTablero(std::string  jugador );
    /*
     * En este metodo devulve un string segun las coordenadas del tablero.
     */
    std::string obtenerStringTablero(int fila, int columna);
    /*
     * En este metodo se cambia el caracter, y recibe como parametro el caracter nuevo con las coordenadas en el tablero
     */
    void setearCaracer(std::string caracterNuevo, int fila, int columna);
    /*
     * En este metodo se inserta el simbolo del tesoro en el tablero , con las coordenadas del mismo y rescibe como parametro el
     * mismo.
     */
    void insertarTesoro(Tesoro tesoro);
    /*
     * En este metodo se inserta el simbolo del espia y en las coordenadas con el espia pasada por parametro
     */
    void insertarEspias(Espia espia);
    /*
     * En este tesoro se le pasa un
     */
    void moverTesoro(Tesoro tesoro, int filaFutura, int columnaFutura);
    /*
     *En este metodo se obtine el texto segun el jugador en un string pasado por parametros los mismos.
     */
    void obtenerTableroJugador(std::string jugador, std::string &tableroTexto);
    /*
     * En este metodo se imprime el tablero en un archivo
     */
    void imprimirTableroEnArchivo();
    /*
     * Este metodo es el destructor del tablero.
     */
    ~Tablero();
};


#endif //TP1_AUX__TABLERO_H

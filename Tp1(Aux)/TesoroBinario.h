//
// Created by daniela on 02/09/23.
//

#ifndef TP1_AUX__TESOROBINARIO_H
#define TP1_AUX__TESOROBINARIO_H
#include "Jugador.h"
#include "Tablero.h"

class TesoroBinario {
private:
    Jugador* jugador1;
    Jugador* jugador2;
    Tablero* tablero;
    int turno;

public:
    /*
     * Constructor del juego
     */
    TesoroBinario();
    /*
     * En este metodo se encuetra toda la logica del juego
     */
    void jugar();
    /*
     *En este metodo se solicita las posiciones de los espias para cada jugador
     */
    void solicitarPosicionesEspias(Jugador* jugadorActual,Jugador* otroJugador);
    /*
     * Con este metodo se puede mover el tesoro de un jugador
     */
    void moverTesoro(Jugador* jugadorActual);
    /*
     * En este metodo se solicita las posiciones de los tesoros de cada jugador
     */
    void solicitarPosicionesDeLosTesoros(Jugador* jugadorAtual);
    /*
     * En este metodo  se inicializa los tesoros de cada jugador y se les da la bienvenida.
     */
    void inicilizarTesoros();
    /*
     * En este metodo se les solicita a los usuarios que ingresen las posiones de sus espias y se lo imprime en el tablero
     */
    void completarPosicionesEspiaSegunTipoJugaor();
    /*
     * En este metodo se mueven los tesoros segun el tipo de jugador y se llama a imprimir a tablero , previamente se completa al mismo con sus caracteres
     */
    void moverTesoroSegunTipoJugador();
    /*
     * En este metodo se analizan las casillas del tablero antes de intertarlo al mismo y para ello se recibe por parametro al simbolo del tablero
     * el jugadorActula , al otorJugador y a la posicion solicitada.
     */
    void analizarCasillasParaLaPocionDelEspia(std::string simbolo,  Jugador *otroJugador,Jugador *jugadorActual, int filaEspia, int columnaEspia);

    /*
     * Destructor de la clase TesoroBinario, en el cual se libera memoria de los jugadores y del tablero
     */
    ~TesoroBinario();


};


#endif //TP1_AUX__TESOROBINARIO_H

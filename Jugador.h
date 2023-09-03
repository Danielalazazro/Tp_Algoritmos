//
// Created by daniela on 01/09/23.
//

#ifndef TP1_AUX__JUGADOR_H
#define TP1_AUX__JUGADOR_H
#include "Tablero.h"
#include "Tesoro.h"
#include "Espia.h"
static const int CANTIDAD_TESORO = 4;
static const int CANTIDAD_TESORO_MAXIMO = 400;
class Jugador {
private:
    char simbolo;
    Tesoro** tesoros;
    Espia** espia;
    int tesoroRestantes;
public:
    Jugador(char jugadorId);
    void colocarTesoro(char** tablero ,int fila, int columna,int nroTesoro);
    void setearTesorosRestantes(int numero);
    void aumentarTesorosRestantes();
    char obtenerSimbolo();
    Espia ** obtenerEspias();
    Tesoro** obtenerTesoros();
    int obtenerNumerosTesororsRestantes();
    ~Jugador();
};


#endif //TP1_AUX__JUGADOR_H

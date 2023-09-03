//
// Created by daniela on 02/09/23.
//

#ifndef TP1_AUX__JUEGO_H
#define TP1_AUX__JUEGO_H
#include "Jugador.h"

class Juego {
private:
    Jugador* juegador1;
    Jugador* jugador2;
    Tablero* tablero;
    int turno;
public:
    Juego();

    void jugar();
    //void inicializarTesoro();
    ~Juego();


};


#endif //TP1_AUX__JUEGO_H

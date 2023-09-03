//
// Created by daniela on 01/09/23.
//

#ifndef TP1_AUX__TESORO_H
#define TP1_AUX__TESORO_H

static int const TESOROS = 4;
static int const TURNOSESPIAS = 5;
class Tesoro {
private:
    int fila;
    int columna;
    int espiasTurnosRestantes;
    bool activo;
public:
    Tesoro(int fila, int columna);
    int getFila();
    int getColumna();
    bool estaRecuperandoEspia();
    void inhabilitarCasillero();
    void descontarTurnosEspias();
    bool estaActivo();
    ~Tesoro();



};


#endif //TP1_AUX__TESORO_H

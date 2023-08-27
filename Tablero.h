//
// Created by daniela on 26/08/23.
//

#ifndef TP1NUEVO_TABLERO_H
#define TP1NUEVO_TABLERO_H
#include "Casillas.h"

class Tablero {
private:
    Tablero* tablero;
    int filas;
    int columnas;
    Casillas **casilleros;
public:
    //EL constructor del tablero
    Tablero(int filas,int columnas);
    //En este metodo imprimo el tablero.
    void mostrar()const;
    //EL destructor del tablero
    ~Tablero();

};


#endif //TP1NUEVO_TABLERO_H

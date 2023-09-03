//
// Created by daniela on 01/09/23.
//

#ifndef TP1_AUX__TABLERO_H
#define TP1_AUX__TABLERO_H

static int const TAMANIO_TABLERO = 20;
class Tablero {
private:
    char ** tablero;

public:
    Tablero();
    void imprimirTablero();
    char  obtenerStringTablero(int fila, int columna);
    void setearCaracer(char caracterNuevo, int fila, int columna);
    ~Tablero();
};


#endif //TP1_AUX__TABLERO_H



#ifndef IMPRIMIR_H_
#define IMPRIMIR_H_
# include "EasyBMP.h"
#include "Tablero.h"
#include "Celda.h"
#include "Celula.h"
#include "Gen.h"

class Imprimir{

public:
    Imprimir();
    /*
     * pre: recibe un objeto del tipo puntero a tablero.
     * pos: devulve el conjunto de imagenes del tablero.
    */
    void pintarCelda(Tablero *tablero);

};

#endif /* IMPRIMIR_H_ */

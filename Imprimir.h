

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
     * pre:
     * pos:
    */
    void pintarCelda(Tablero *tablero);
    /*
    * pre:
    * pos:
    */
    void imprimirTablero(Tablero *tablero);
};

#endif /* IMPRIMIR_H_ */

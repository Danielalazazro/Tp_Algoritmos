

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
    void pintarCelda(BMP Imagen,const char* nombre,int profundidadActual);
    /*
    * pre:
    * pos:
    */
    void imprimirTablero(Imprimir imprimir);
}

#endif /* IMPRIMIR_H_ */

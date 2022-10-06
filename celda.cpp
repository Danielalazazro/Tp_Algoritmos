//
#include "celda.h"
#include <iostream>
#include <stdlib.h>

int Celda::aplicarConportamiento() {
        estadoDeCelda = 1 + rand() % 5;
        if (estadoDeCelda == 1){
            aplicarEnvenenamiento();

        }
        else if (estadoDeCelda == 2){
            aplicarContaminacion();
        }
        else if (estadoDeCelda == 3){
            aplicarPortal();

        }
        else if(estadoDeCelda == 4){
            aplicarProcreadora()    ;
        }
        else if (estadoDeCelda == 5){
            aplicarRadioactividad();
        }
}



/*
 *     int contaminada;//estado = 1:celda contaminada
    int envenenada;//estado = 2 :celda envenenada
    int procreadora;//estade = 3:celda preocreadora
    int portal;//estado = 4:celda portal
    //estado = 5 :celda radioactiva
    int estadoDeCelda;
 */
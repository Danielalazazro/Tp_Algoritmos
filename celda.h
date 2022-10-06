//
// Created by daniela on 29/09/22.
//

#ifndef TP2_CELULAS_H
#define TP2_CELULAS_H


class Celda {
private:

    int estadoDeCelda;//estado que epuede variar
public:
    int aplicarConportamiento();
    void aplicarEnvenenamiento();
    void aplicarContaminacion();
    void aplicarPortal();
    void aplicarProcreadora();
    void  aplicarRadioactividad();

};


//estado qu epuede variar
/*
int contaminada;//estado = 1:celda contaminada
int envenenada;//estado = 2 :celda envenenada
int procreadora;//estade = 3:celda preocreadora
int portal;//estado = 4:celda portal
//estado = 5 :celda radioactiva
int estadoDeCelda;
*/


#endif //TP2_CELULAS_H

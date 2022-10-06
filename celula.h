//
// Created by daniela on 29/09/22.
//

#ifndef TP2_CELULA_H
#define TP2_CELULA_H
#include "Gen.h"


class Celula {
private:
    int estado;
    Gen arrayGen[3];
    Gen arrayNuevoGen[3];

public:
    int cuantificarGenes();
    int obtenerCargaGeneticaPredominante();

    Celula();
    Celula(int  gen1,int  gen2, int  gen3);
    ~Celula();


};


#endif //TP2_CELULA_H

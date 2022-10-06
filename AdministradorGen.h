//
// Created by daniela on 01/10/22.
//

#ifndef TP2_ADMINISTRADORGEN_H
#define TP2_ADMINISTRADORGEN_H
#include "Gen.h"

class AdministradorGen {
private:
    Gen gen1;
    Gen gen2;
    Gen gen3;

public:
    /*
     *pre:
     * post:
     */
    AdministradorGen(Gen gen1,Gen gen2 ,Gen gen3);
    /*
     * pre:
     * post:
     */
    Gen obtenerGen();


};


#endif //TP2_ADMINISTRADORGEN_H

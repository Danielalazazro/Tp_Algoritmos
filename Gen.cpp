//
// Created by daniela on 01/10/22.
//

#include "Gen.h"
#include <iostream>
Gen::Gen() {}
Gen::Gen(unsigned int cargaGen) {
    verificarEnRango(cargaGen);
    if (verificarEnRango(cargaGen)){
        this->cargaGenetica = cargaGen;
    }
    else {
        cargaGenetica =  rand() % 255;
    }
}
Gen::~Gen() {}

unsigned int Gen::getCargaGenetica() {
    return this->cargaGenetica;
}
void Gen::setCargaGenetica(unsigned int cargaGenetica) {
    this->cargaGenetica = cargaGenetica;
}
bool Gen::verificarEnRango(unsigned int cargaGenetica) {
    return ((cargaGenetica >= 0) && (cargaGenetica <= maximaCargaGenetica));
}
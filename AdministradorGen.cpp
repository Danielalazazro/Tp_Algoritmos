//
// Created by daniela on 01/10/22.
//

#include "AdministradorGen.h"
#include <iostream>
#include <cstdlib>
#include <math.h>

AdministradorGen::AdministradorGen(Gen gen1,Gen gen2 ,Gen gen3){
    this->gen1 = gen1;
    this->gen2 = gen2;
    this->gen3 = gen3;

};
Gen AdministradorGen::obtenerGen() {
    int numeroAleatorio = 1 + rand() % 3 ;
    Gen gen4;
    if (numeroAleatorio == 1){
        unsigned int promedio = (gen1.getCargaGenetica() + gen2.getCargaGenetica() +  gen3.getCargaGenetica())/3  ;
        gen4  = Gen(promedio) ;
    }

    else if(numeroAleatorio == 2){
        unsigned int maxAux1 = std::max(gen1.getCargaGenetica(),gen2.getCargaGenetica());
        unsigned int maximo = std::max(maxAux1,gen3.getCargaGenetica());
        gen4 = Gen (maximo);
    }

    else if(numeroAleatorio == 3){
        unsigned int modulo = sqrt(pow(gen1.getCargaGenetica(),2) + pow(gen2.getCargaGenetica(),2) + pow(gen3.getCargaGenetica(),2));
        gen4 =  Gen(modulo);
    }
    return gen4;
};
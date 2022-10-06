//
// Created by daniela on 29/09/22.
//

#include "celula.h"
#include <cstdlib>
# include <iostream>
#include "AdministradorGen.h"
#include "Gen.h"
using namespace std;
int Celula::obtenerCargaGeneticaPredominante()
{
    AdministradorGen adminGen = AdministradorGen( arrayGen[0], arrayGen[1], arrayGen[2]);
    return adminGen.obtenerGen().getCargaGenetica();

}

Celula::Celula(int gen1, int gen2, int gen3) {
    arrayGen[0] = Gen(gen1);
    arrayGen[1] = Gen(gen2);
    arrayGen[2] = Gen (gen3);



}

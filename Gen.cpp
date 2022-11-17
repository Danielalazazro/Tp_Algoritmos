//
#include "Gen.h"
#include <iostream>
using namespace std;
Gen::Gen() {
    cargaGenetica = 0;
}
Gen::Gen(unsigned int cargaGen) {

    verificarEnRango(cargaGen);
    if (verificarEnRango(cargaGen)){
        this->cargaGenetica = cargaGen;
    }
    else {
       this->cargaGenetica =  rand() % maximaCargaGenetica;
    }
}
Gen::~Gen(){}
unsigned int Gen::getCargaGenetica() {
    return this->cargaGenetica;
}

bool Gen::verificarEnRango(unsigned int cargaGenetica) {
    return ((cargaGenetica >= 0) && (cargaGenetica <= maximaCargaGenetica));
}
void Gen::insertarCargaUsuario(){
    unsigned int cargaGeneticaIngreso = 300;
    cout << "Ingrese la  carga genetica  de la celula :"<< endl;
    while(not (verificarEnRango(cargaGeneticaIngreso))){
        cin >> cargaGeneticaIngreso;
        if(not verificarEnRango(cargaGeneticaIngreso)){
            cout << "Error, ingrese una carga genetica valida o dentro del rango"<<endl;
        }
    }
    this->cargaGenetica = cargaGeneticaIngreso;
}

bool Gen::estaVivoGen(){
    {
        return (cargaGenetica > 0);
    }
}
void Gen::matarGen(){

    cargaGenetica = 0;
}

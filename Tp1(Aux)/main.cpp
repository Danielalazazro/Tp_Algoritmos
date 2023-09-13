#include <iostream>
#include <fstream>
#include "TesoroBinario.h"
static const int FILAS = 3;
static const int COLUMNAS = 3;
Tesoro* generarTesoros(){
    Tesoro* unosTesoros = new Tesoro[4];
    // cargar 4 posicones
    unosTesoros[0] = Tesoro(0, 0, "A" );
    unosTesoros[1] = Tesoro(1, 1, "B");
    unosTesoros[2] = Tesoro(2, 2, "A");
    unosTesoros[3] = Tesoro(2, 1, "B");
    return unosTesoros;
}

void imprimiPosTesoros(Tesoro* tesoros){
    for(int i = 0; i < 4; i++){
        Tesoro tesoro = tesoros[i];
        std::cout<< "("<<tesoro.getFila()<<","<< tesoro.getColumna()<<")"<<std::endl;
    }
}
Espia* generarEspias(){
     Espia* espias = new  Espia[4];
     /*espias[0] = Espia(3, 3, "1");
     espias[1] = Espia(4, 2, "2");
     espias[2] = Espia(5, 5, "1");
     espias[3] = Espia(6, 6, "2");*/
     for(int i  = 0; i < 4; i++){
         espias[i].setearSimboloEspia("1");
     }
    return espias;
}
void imprimirPosEspias(Espia* espias,int tope ){
    for(int i = 0; i < tope;i++){
        Espia espia = espias[i];
        std::cout<<espia.getSimbolo()<<std::endl;
    }
}
void eliminarEspia(int posicion, Espia* espias, int tope){
    for(int i= posicion; i+1 < tope; i++){
        espias[i] = espias[i+1];
    }
    tope--;
    imprimirPosEspias(espias,tope);
}
void exportarTablero(int tablero[FILAS][COLUMNAS],const char* nombreArchivo ){
    std::ofstream archivo(nombreArchivo);
    if(archivo.is_open()){
        for(int i = 0 ; i < FILAS; i++){
            for(int j = 0; j < COLUMNAS;j++){
                archivo<<tablero[i][j]<<" ";
            }
            archivo<<std::endl;
        }
        archivo.close();
        std::cout<<"Tablero exportado exitosamente "<<nombreArchivo<<std::endl;
    }
    else{
        std::cout<<"No se pudo abrir el archivo"<<std::endl;
    }
}

int main() {
    //Tesoro* tesoros = generarTesoros();
    //Espia* espias = generarEspias();
    //std::cout<<"Imprimo las posiciones de los tesoros: "<<std::endl;
    //imprimiPosTesoros(tesoros);
    //std::cout<<"Imprimo las posiciones de los espias: "<<std::endl;
    //imprimirPosEspias(espias, 4);
    //std::cout<< "-------------------------" <<std::endl;
    //eliminarEspia(2,espias,4);
    //imprimirPosEspias(espias,4);
    //Tablero* unTablero = new Tablero();
    //unTablero->insertarTesorosYEspias(tesoros, espias);
    //unTablero->imprimirTablero();
    TesoroBinario* juego = new TesoroBinario();
    //juego->inicilizarTesoros();
    //juego->imprimirTableroJugadores();
    juego->jugar();
    //juego->imprimirTableroJugadores();
    /*int tablero[FILAS][COLUMNAS] = {{1,2,3},
                                    {4,5,6},
                                    {7,8,9}
                                    };
    exportarTablero(tablero,"tablero.txt");*/
    delete juego;
    return 0;
}

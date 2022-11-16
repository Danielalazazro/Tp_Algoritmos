#include "Imprimir.h"
#include <iostream>
#include <string>

Imprimir::Imprimir() {

}

void Imprimir::pintarCelda(Tablero *tablero){
    BMP Imagen;
    Imagen.SetBitDepth(8);
    for(int prof = 0; prof < tablero->obtenerProfundidad(); prof++){
        Imagen.ReadFromFile("BaseImagen.bmp");
        Imagen.SetSize(tablero->obtenerFila(), tablero->obtenerColumna());
        for( int i = 0 ; i < Imagen.TellWidth(); i++) {
            for (int j = 0; j < Imagen.TellHeight(); j++) {
                Imagen(i, j)->Red = tablero->obtenerCelda(prof, i, j)->obtenerCelula()->obtenerCargaEnPos(0);
                Imagen(i, j)->Blue = tablero->obtenerCelda(prof, i, j)->obtenerCelula()->obtenerCargaEnPos(1);
                Imagen(i, j)->Green = tablero->obtenerCelda(prof, i, j)->obtenerCelula()->obtenerCargaEnPos(2);
                Imagen(i, j)->Alpha = 0;
            }
        }
        std::string imagenIesima = "imagen" + to_string(prof) + ".bmp";
        Imagen.WriteToFile(imagenIesima.c_str());
    }
}


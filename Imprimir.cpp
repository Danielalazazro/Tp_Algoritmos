#include "Imprimir.h"
#include <iostream>
#include <string>


void Imprimir::pintarCelda(BMP Imagen,const char* nombre,int profundidadActual){

	for( int i=0 ; i < Imagen.TellHeight(); i++){
			for( int j=0 ; j < Imagen.TellWidth() ; j++){
				Tablero* pintarCeldaDeTablero = obtenerCelda(profundidadActual,i,j).obtenerCelula().getArrayGen();

					Imagen(i,j)->Red = genes[0];
					Imagen(i,j)->Green = genes[1];
					Imagen(i,j)->Blue = genes[2];
					Imagen(i,j)->Alpha= 0;
			}
			Imagen.WriteToFile(nombre);
	}
}


void Imprimir::imprimirTablero(Imprimir imprimir) {
	if(obtenerProfundidad() == 0){
		return;
	}
	else{

		BMP Imagen;
		Imagen.SetSize(obtenerFila(),obtenerColumna());
		string nombre = "capa";
		string bmp = ".bmp"

		for(int i = 0; i < obtenerProfundidad() + 1 ; i++){

			int profundidadActual = i;
			string numero = to_string(i);
			string nombreCapa = nombre + numero + bmp;

			pintarCelda(Imagen , nombreCapa.c_str() , profundidadActual);
		}

	}



}

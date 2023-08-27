#include <iostream>
#include "Tablero.h"
#include "Casillas.h"
static const int FILAS = 20;
static const int COLUMNAS = 20;
void menuJuego(){
    std::string mueveTesoro;
    std::string recuperarTesoro;
    int posActualFila;
    int posActualColumnas;
    int posAmoverFila;
    int posAmoverColumnas;
    int posActualRecuperarTesoroFila;
    int posActualRecuperarTesoroColumnas;
    std::cout<<"Opcion 1: Desea mover su tesoro (s/n): "<<std::endl;
    std::cin>>mueveTesoro;
    std::cout<<"Ingrese su posicion actual de la fila del tesoro: "<<std::endl;
    std::cin>>posActualFila;
    std::cout<<"Ingrese su posicion actual de la columnas del tesoro: "<<std::endl;
    std::cin>>posActualColumnas;
    std::cout<<"Ingrese la fila a mover el tesoro: "<<std::endl;
    std::cin>>posAmoverFila;
    std::cout<<"Ingrese  la columna  a mover del tesoro: "<<std::endl;
    std::cin>>posAmoverColumnas;
    std::cout<<"Opcion 2: Desea recuperar su tesoro del otro tesoro (s/n): "<<std::endl;
    std::cin>>recuperarTesoro;
    std::cout<<"Ingrese la fila donde se encuentra su tesoro: "<<std::endl;
    std::cin>>posActualRecuperarTesoroFila;
    std::cout<<"Ingrese la columnas donde se encuentra su tesoro: "<<std::endl;
    std::cin>>posActualRecuperarTesoroColumnas;

}
// Tablero con memoria estatica
void imprimirTablero(const std::string tablero[][COLUMNAS]){
    for(int i = 0; i <FILAS; i++){
        for(int j = 0; j <COLUMNAS; j++){
            std::cout<<tablero[i][j] ;
        }
        std::cout<<"\n";
    }
}
void iniciarJuego( std::string tablero[][COLUMNAS] ,std::string valor){
    int posFila;
    int posColumna;
    std::cout<<"Ingrese una fila: "<<std::endl;
    std::cin>>posFila;
    std::cout<<"ingrese una columnas"<<std::endl;
    std::cin>>posColumna;
    tablero[posFila][posColumna] = valor;



}
void crearTableroYcargarTesosros( std::string tablero[][COLUMNAS],std::string simboloTesoro, std::string simboloVacio){
    //Inicializo el tablero

    for(int i = 0; i < FILAS; i++){
        for(int j = 0; j< COLUMNAS ; j++){
            tablero[i][j] = simboloVacio;
            if((i  == 18 && j == 10) ){
                tablero[i][j] = simboloTesoro;
            }
            else if( i == 4 && j == 6){
                tablero[i][j] = simboloTesoro;
            }
            else if( i == 7 && j == 9){
                tablero[i][j] = simboloTesoro;
            }
            else if(i == 16 && j == 4){
                tablero[i][j] = simboloTesoro;
            }
            else if(i == 14 && j == 5){
                tablero[i][j] = simboloTesoro;
            }
            else if(i == 12 && j == 2){
                tablero[i][j] = simboloTesoro;
            }
            else if( i == 8 && j == 6){
                tablero[i][j] = simboloTesoro;
            }
            else if( i == 11 && j == 13){
                tablero[i][j] = simboloTesoro;
            }
        }
    }
    //iMPRIMO EL TABLERO:
   /* for(int i = 0; i <FILAS; i++){
        for(int j = 0; j <COLUMNAS; j++){
            std::cout<<tablero[i][j] ;
        }
        std::cout<<"\n";
    }*/
}
//Tablero con memoria dinamica:


int main() {
    Tablero tablero1(FILAS,COLUMNAS);
    tablero1.mostrar();
    /*std::string tablero[FILAS][COLUMNAS];
    std::string simboloTesoro = "T";
    std::string simboloVacio = " ";
    crearTableroYcargarTesosros(tablero,"T"," ");
    imprimirTablero(tablero);
    iniciarJuego(tablero,"E1");
    imprimirTablero(tablero);*/
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

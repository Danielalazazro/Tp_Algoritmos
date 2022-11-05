//
// Created by daniela on 08/10/22.
//

#include "Tablero.h"
#include "Celda.h"
#include "Lista.h"
#include <string>
using namespace std;
#include <iostream>
#include <cmath>
#include <math.h>

Celda* Tablero::obtenerCelda(int posicionZ , int posicionX, int poscionY ){
    //cout << posicionZ;
    //cout <<posicionX;
    //cout << posicionY;
    return this->tableroCelda->obtenerSegunPosicionDato(posicionZ)->obtenerSegunPosicionDato(
            posicionX)->obtenerSegunPosicionDato(poscionY);
}

void Tablero::asignarValoresAleatoria(int *profundiaRandom, int *filaRandom, int* columnaRandom ){
    *profundiaRandom = rand() % cantidadMaximaPosZ;
    *filaRandom = rand() % cantidadMaximaPosY;
    *columnaRandom = rand() % cantidadMaximaPosX;

}

void Tablero::verificarIngresoUsuario(int limiteSuperior, int* ingresoUsuario){
    *ingresoUsuario = -1;
    std::cout << "Que debe estar entre 1 y limite superior "<<limiteSuperior <<": "<<endl;
    while( (*ingresoUsuario > limiteSuperior ) || (*ingresoUsuario <= 0) ){
        cin >> *ingresoUsuario;
        if((*ingresoUsuario > limiteSuperior  ) ||(*ingresoUsuario <= 0)){
            std::cout<<"ERROR RANGO INVALIDO\n";
            std::cout << "Que debe estar entre 1 y limite superior "<<limiteSuperior <<": "<<endl;
        }
    }
    *ingresoUsuario = *ingresoUsuario -1;
}
void Tablero::cargarCelulasVivasyCargaRandom(){

    cantidadCelulaVivasActuales = 8 + rand() % 20;
    int i = 0;
    while(i < cantidadCelulaVivasActuales){
        int filaRandom, columnaRandom, profundidadRandom;
        asignarValoresAleatoria(&profundidadRandom, &columnaRandom, &filaRandom);
        Celda * celdaAleatoria = obtenerCelda(profundidadRandom, filaRandom, columnaRandom);
        if( not celdaAleatoria->obtenerCelula()->estaViva()){
            celdaAleatoria->obtenerCelula()->revivir();
            celdaAleatoria->obtenerCelula()->setearCargaGeneticaAleatoria();
            i++;
        }
    }
}
void Tablero::cargarCelulaUsuario(int modoJuego) {

    int posicionX = 0, posicionY = 0 , posicionZ = 0;
    int i = 0;
    while ( i < cantidadCelulaVivasActuales ){

        cout << "Ingrese la posicionX de la tableroCelda con la celula viva: ";
        verificarIngresoUsuario(cantidadMaximaPosX, &posicionX);
        cout << "Ingrese la posicionY de la tableroCelda con la celula viva: ";
        verificarIngresoUsuario(cantidadMaximaPosY, &posicionY);
        cout << "Ingrese la posicionZ de la tableroCelda con la celula viva: ";
        verificarIngresoUsuario(cantidadMaximaPosZ, &posicionZ);

        Celda* celdaUsuario = obtenerCelda(posicionX,posicionY, posicionZ);
        if(not celdaUsuario->obtenerCelula()->estaViva()){
            celdaUsuario->obtenerCelula()->revivir();
            if(modoJuego == 3){
                celdaUsuario->obtenerCelula()->setearCargaGeneticaAleatoria();
            }
            else if(modoJuego==1){
                celdaUsuario->obtenerCelula()->setearCargaGeneticaUsuario();
            }
            i++;
        }
        else{
            cout << "ERROR POSCION OCUPADA INGRESE OTRA POSICION DE LA CELDA CON CELULA VIVA \n";
        }

    }

}

int Tablero::obtenerFila() {
    return this->cantidadMaximaPosX;
}

int Tablero::obtenerColumna(){
    return this->cantidadMaximaPosY;
}

int Tablero::obtenerProfundidad() {
    return this->cantidadMaximaPosZ;
}
Tablero::Tablero(int cantidadFila, int cantidadColumnas, int cantidaProfundiad) {
    //creo todas las celdas
    this->cantTurno = 0;
    listaCaracteresCubo = new Lista<char> ();
    this->cantCelNacidasTurno = 0,
    this->cantCelMuertasTurno = 0;
    this->cantidadCelulasMuertasTotales = 0;
    this->cantidadCelulasNacidasTotales = 0;
    this->tableroCelda = new Lista< Lista <Lista<Celda*> *> *>();
    this->cantidadMaximaPosX = cantidadFila;
    this->cantidadMaximaPosY = cantidadColumnas;
    this->cantidadMaximaPosZ = cantidaProfundiad;
    // tableroCelda->obtener(profundida4)->obtener(fila7)->obtenerSegunPosicionDato(columna9)
    for(int i = 0; i < this->cantidadMaximaPosZ; i++){
        Lista<Lista<Celda*>*>* columna = new Lista<Lista<Celda*>*>();
        for(int j = 0; j < this->cantidadMaximaPosX ; j++){
            Lista<Celda*>* fila = new Lista< Celda* >();
            for(int k = 0; k < this->cantidadMaximaPosY; k++){
                Celda* celda = new Celda(j, k, i);
                fila->insertarElemento(celda);
            }
            columna->insertarElemento(fila);
        }
        this->tableroCelda->insertarElemento(columna);
    }

    for(int i = 0; i < cantidadMaximaPosZ; i++){
        for(int j = 0; j < cantidadMaximaPosX ; j++){
            for(int k = 0; k < cantidadMaximaPosY ; k++){
                asignarCeldasAdayacentes(obtenerCelda(i, j, k));
            }
        }
    }

}
void Tablero::asignarCeldasAdayacentes(Celda* unaCelda) {
    Celda *nuevaCelda;
    if (unaCelda->getPosX() - 1 >= 0) {
        nuevaCelda = obtenerCelda(unaCelda->getPosZ(), unaCelda->getPosX() - 1, unaCelda->getPosY());
        unaCelda->agregarAdyacente(nuevaCelda);
    }
    if (unaCelda->getPosY() - 1 >= 0) {
        nuevaCelda = obtenerCelda(unaCelda->getPosZ(), unaCelda->getPosX(), unaCelda->getPosY() - 1);
        unaCelda->agregarAdyacente(nuevaCelda);
    }
    if (unaCelda->getPosZ() - 1 >= 0) {
        nuevaCelda = obtenerCelda(unaCelda->getPosZ() - 1, unaCelda->getPosX(), unaCelda->getPosY());
        unaCelda->agregarAdyacente(nuevaCelda);
    }
    if (unaCelda->getPosX() + 1 < cantidadMaximaPosX) {
        nuevaCelda = obtenerCelda(unaCelda->getPosZ(), unaCelda->getPosX() + 1, unaCelda->getPosY());
        unaCelda->agregarAdyacente(nuevaCelda);
    }
    if (unaCelda->getPosY() + 1 < cantidadMaximaPosY) {
        nuevaCelda = obtenerCelda(unaCelda->getPosZ(), unaCelda->getPosX(), unaCelda->getPosY() + 1);
        unaCelda->agregarAdyacente(nuevaCelda);
    }
    if (unaCelda->getPosZ() + 1 < cantidadMaximaPosZ) {
        nuevaCelda = obtenerCelda(unaCelda->getPosZ() + 1, unaCelda->getPosX(), unaCelda->getPosY() );
        unaCelda->agregarAdyacente(nuevaCelda);
    }
    if ((unaCelda->getPosX() + 1 < cantidadMaximaPosX) && (unaCelda->getPosY() + 1 < cantidadMaximaPosY)) {
        nuevaCelda = obtenerCelda(unaCelda->getPosZ(), unaCelda->getPosX() + 1, unaCelda->getPosY() + 1);
        unaCelda->agregarAdyacente(nuevaCelda);
    }

    if ((unaCelda->getPosX() + 1 < cantidadMaximaPosX) && (unaCelda->getPosZ() + 1 < cantidadMaximaPosZ)) {
        nuevaCelda = obtenerCelda(unaCelda->getPosZ() + 1, unaCelda->getPosX() + 1, unaCelda->getPosY());
        unaCelda->agregarAdyacente(nuevaCelda);
    }
    if ((unaCelda->getPosY() + 1 < cantidadMaximaPosY) && (unaCelda->getPosZ() + 1 < cantidadMaximaPosZ)) {
        nuevaCelda = obtenerCelda(unaCelda->getPosZ() + 1, unaCelda->getPosX(), unaCelda->getPosY() + 1);
        unaCelda->agregarAdyacente(nuevaCelda);
    }
    //negativos
    if ((unaCelda->getPosX() - 1 >= 0) && (unaCelda->getPosY() - 1 >= 0)) {
        nuevaCelda = obtenerCelda(unaCelda->getPosZ(), unaCelda->getPosX() - 1, unaCelda->getPosY() - 1);
        unaCelda->agregarAdyacente(nuevaCelda);
    }

    if ((unaCelda->getPosX() - 1 >= 0) && (unaCelda->getPosZ() - 1 >= 0)) {
        nuevaCelda = obtenerCelda(unaCelda->getPosZ() - 1, unaCelda->getPosX() - 1, unaCelda->getPosY());
        unaCelda->agregarAdyacente(nuevaCelda);
    }
    if ((unaCelda->getPosY() - 1 >= 0) && (unaCelda->getPosZ() - 1 >= 0)) {
        nuevaCelda = obtenerCelda(unaCelda->getPosZ() - 1, unaCelda->getPosX(), unaCelda->getPosY() - 1);
        unaCelda->agregarAdyacente(nuevaCelda);
    }
    //convivno negativos con positivos
    if ((unaCelda->getPosX() - 1 >= 0) && (unaCelda->getPosY() + 1 < cantidadMaximaPosY)) {
        nuevaCelda = obtenerCelda(unaCelda->getPosZ(), unaCelda->getPosX() - 1, unaCelda->getPosY() + 1);
        unaCelda->agregarAdyacente(nuevaCelda);
    }
    if ((unaCelda->getPosY() - 1 >= 0) && (unaCelda->getPosZ() + 1 < cantidadMaximaPosZ)) {
        nuevaCelda = obtenerCelda(unaCelda->getPosZ() + 1, unaCelda->getPosX() , unaCelda->getPosY() - 1);
        unaCelda->agregarAdyacente(nuevaCelda);
    }
    if ((unaCelda->getPosX() + 1 < cantidadMaximaPosX) && (unaCelda->getPosY() - 1 >= 0)) {
        nuevaCelda = obtenerCelda(unaCelda->getPosZ(), unaCelda->getPosX() + 1, unaCelda->getPosY() - 1);
        unaCelda->agregarAdyacente(nuevaCelda);
    }
    if ((unaCelda->getPosY() + 1 < cantidadMaximaPosY) && (unaCelda->getPosZ() - 1 >= 0)) {
        nuevaCelda = obtenerCelda(unaCelda->getPosZ() - 1, unaCelda->getPosX(), unaCelda->getPosY() + 1);
        unaCelda->agregarAdyacente(nuevaCelda);
    }
    if ((unaCelda->getPosX() + 1 < cantidadMaximaPosX) && (unaCelda->getPosZ() - 1 >= 0)) {
        nuevaCelda = obtenerCelda(unaCelda->getPosZ() - 1, unaCelda->getPosX() + 1, unaCelda->getPosY());
        unaCelda->agregarAdyacente(nuevaCelda);
    }

    //verificacion de 3
    if ((unaCelda->getPosX() + 1 < cantidadMaximaPosX) && (unaCelda->getPosY() + 1 < cantidadMaximaPosY) &&
        (unaCelda->getPosZ() + 1 < cantidadMaximaPosZ)) {
        nuevaCelda = obtenerCelda(unaCelda->getPosZ() + 1, unaCelda->getPosX() + 1, unaCelda->getPosY() + 1);
        unaCelda->agregarAdyacente(nuevaCelda);
    }
    if ((unaCelda->getPosX() - 1 >= 0) && (unaCelda->getPosY() - 1 >= 0) && (unaCelda->getPosZ() - 1 >= 0)) {
        nuevaCelda = obtenerCelda(unaCelda->getPosZ() - 1, unaCelda->getPosX() - 1, unaCelda->getPosY() - 1);
        unaCelda->agregarAdyacente(nuevaCelda);
    }
    //Convinacion de 3 cifras de negativos y positivos
    if ((unaCelda->getPosX() - 1 >= 0) && (unaCelda->getPosY() + 1 < cantidadMaximaPosY) &&
        (unaCelda->getPosZ() - 1 >= 0)) {
        nuevaCelda = obtenerCelda(unaCelda->getPosZ() - 1, unaCelda->getPosX() - 1, unaCelda->getPosY() + 1);
        unaCelda->agregarAdyacente(nuevaCelda);
    }
    //
    if ((unaCelda->getPosX() + 1 < cantidadMaximaPosX) && (unaCelda->getPosY() + 1 < cantidadMaximaPosY) &&
        (unaCelda->getPosZ() - 1 >= 0)) {
        nuevaCelda = obtenerCelda(unaCelda->getPosZ() - 1, unaCelda->getPosX() + 1, unaCelda->getPosY() + 1);
        unaCelda->agregarAdyacente(nuevaCelda);
    }
    //
    if ((unaCelda->getPosX() + 1 < cantidadMaximaPosX) && (unaCelda->getPosY() - 1 >= 0) &&
        (unaCelda->getPosZ() - 1 >= 0)) {
        nuevaCelda = obtenerCelda(unaCelda->getPosZ() - 1, unaCelda->getPosX() + 1, unaCelda->getPosY() - 1);
        unaCelda->agregarAdyacente(nuevaCelda);
    }
    //
    if ((unaCelda->getPosX() - 1 >= 0) && (unaCelda->getPosY() - 1 >= 0) &&
        (unaCelda->getPosZ() + 1 < cantidadMaximaPosZ)) {
        nuevaCelda = obtenerCelda(unaCelda->getPosZ() + 1, unaCelda->getPosX() - 1, unaCelda->getPosY() - 1);
        unaCelda->agregarAdyacente(nuevaCelda);
    }
    //
    if ((unaCelda->getPosX() - 1 >= 0) && (unaCelda->getPosY() + 1 < cantidadMaximaPosY) &&
        (unaCelda->getPosZ() + 1 < cantidadMaximaPosZ)) {
        nuevaCelda = obtenerCelda(unaCelda->getPosZ() + 1, unaCelda->getPosX() - 1, unaCelda->getPosY() + 1);
        unaCelda->agregarAdyacente(nuevaCelda);
    }
    //
    if((unaCelda->getPosX() + 1 < cantidadMaximaPosX) && (unaCelda->getPosY() - 1 >= 0) &&
       (unaCelda->getPosZ() + 1 < cantidadMaximaPosZ)) {
        nuevaCelda = obtenerCelda(unaCelda->getPosZ() + 1, unaCelda->getPosX() + 1, unaCelda->getPosY() - 1);
        unaCelda->agregarAdyacente(nuevaCelda);
    }
    //
    if((unaCelda->getPosX() - 1 >= 0) && (unaCelda->getPosZ() + 1 < cantidadMaximaPosZ)) {
        nuevaCelda = obtenerCelda(unaCelda->getPosZ() + 1, unaCelda->getPosX() - 1, unaCelda->getPosY());
        unaCelda->agregarAdyacente(nuevaCelda);
    }
}

void Tablero::imprimirTableroyResumen(){

    cout << "cantidad de filas :"<<cantidadMaximaPosX << "\t";
    cout << "cantidad de columna :"<<cantidadMaximaPosY << "\t";
    cout << "cantidad de planos: "<<cantidadMaximaPosZ << "\t";
    cout << "cantidad de celulas vivas de actuales: " << cantidadCelulaVivasActuales << "\n";
    cout << "cantidad de celulas vivas para nacer: "<< cantidadCelulasVecinasParaNacer << "\t";
    cout << "cantidad de celulas para seguir viva 1:"<<cantidadCelulasVecinasParaSeguirViva1 << "\t";
    cout << "cantidad de celulas para seguir viva 2:"<< cantidadCelulaVecinasParaSeguirViva2 << "\t"<<"\n";
    //cout << "cantidad de celulas muertas totales:  " << cantidadCelulasMuertasTotales << "\n";
    //cout << "cantidad de celulas nacidas totales: " << cantidadCelulasNacidasTotales << "\n";
    cout << "cantidad de celulas muertas en este turno: " <<cantCelMuertasTurno <<" \t ";
    cout << "cantidad de celulas nacidas en este turno: "<<cantCelNacidasTurno<<" \t ";
    cout << "El numero de turno es: "<<cantTurno<<"\n";
    float promedioDeNacidas = (float) cantidadCelulasNacidasTotales/(float) cantTurno;
    float promedioMuertas = (float) cantidadCelulasMuertasTotales/(float) cantTurno;
    cout << "Promedio de nacimientos de celulas : "<<promedioDeNacidas<< "\t";
    cout << "Promedio de muertes de cada celula: "<<promedioMuertas << "\n";

    reporteSiseCongeloTablero();
    imprimirTablero();

}


void Tablero::insertarCaracteresEnLista(Lista<char>* listaInsertar){
    for( int prof = 0; prof < this->cantidadMaximaPosZ; prof++){
        for(int i = 0; i < this->cantidadMaximaPosX; i++) {
            for (int j = 0; j < this->cantidadMaximaPosY; j++) {
                Celda *celda = obtenerCelda(prof, i, j);
                listaInsertar->insertarElemento(celda->obtenerCelula()->dibujar() );
            }
        }
    }


}

void Tablero::setearCantidadCelulasVivasParaNacer(int cantCelulasParaNacer, int cantCelulasParaSeguirViva1, int cantCelulasParaSeguirViva2 ,int modoJuego){

    this->cantidadCelulasVecinasParaNacer = cantCelulasParaNacer;
    this->cantidadCelulasVecinasParaSeguirViva1 = cantCelulasParaSeguirViva1;
    this->cantidadCelulaVecinasParaSeguirViva2 = cantCelulasParaSeguirViva2;
    cargarCelulaUsuario(modoJuego);

}

void Tablero::actualizarTablero(){
    imprimirTableroyResumen();
    cantCelNacidasTurno = 0, cantCelMuertasTurno = 0;
    int nuevasCelulas = 0;
    aplicarLogicaDelJuego();
    for(int i = 0; i < cantidadMaximaPosX; i++){
        for(int j = 0; j < cantidadMaximaPosY ; j++){
            for(int k = 0; k < cantidadMaximaPosZ ; k++){
                nuevasCelulas = cantCelNacidasTurno;
                obtenerCelda(k, i, j)->aplicarConportamiento(&cantCelNacidasTurno);
                cantidadCelulaVivasActuales += (cantCelNacidasTurno - nuevasCelulas);
                if(obtenerCelda(k,i,j)->tieneEstadoProcreadora()){
                    setCantCelulasVivasParaNacer();
                }
                if((obtenerCelda(k,i,j)->tieneEstadoContaminada()) && (obtenerCelda(k, i, j)->obtenerCelula()->estaViva())){
                    obtenerCelda(k,i,j)->obtenerCelula()->antesVivaAhoraMuerta();
                    obtenerCelda(k,i,j)->obtenerCelula()->matarCelula();
                    cantidadCelulaVivasActuales--;
                    cantCelMuertasTurno++;
                }
            }
        }
    }
    cantidadCelulasNacidasTotales += cantCelNacidasTurno;
    cantidadCelulasMuertasTotales += cantCelMuertasTurno;
    actualizarEstadoDeCeldas();
}
void Tablero::actualizarEstadoDeCeldas(){
    for(int i = 0; i < cantidadMaximaPosX; i++){
        for(int j = 0; j < cantidadMaximaPosY ; j++){
            for(int k = 0; k < cantidadMaximaPosZ ; k++){
                obtenerCelda(k, i, j)->setNuevoEstado();

            }
        }
    }
}


void Tablero::setCantCelulasVivasParaNacer(){
    this->cantidadCelulasVecinasParaNacer = 1 + rand() % minimoDeLasDimensionesTablero()   ;
}
int Tablero::minimoDeLasDimensionesTablero(){
    int min1, min2 ;
    min1 = min(cantidadMaximaPosY, cantidadMaximaPosX);

    min2 = min(min1, cantidadMaximaPosZ);
    return min2;
}


Tablero::~Tablero() {
    //deletes de celdas;
    for(int i = 0; i < this->cantidadMaximaPosZ; i++){
        for(int j = 0; j < this->cantidadMaximaPosX ; j++){
            for(int k = 0; k < this->cantidadMaximaPosY; k++){
                delete this->tableroCelda->obtenerSegunPosicionDato(i)->obtenerSegunPosicionDato(j)->obtenerSegunPosicionDato(k);
            }
            delete this->tableroCelda->obtenerSegunPosicionDato(i)->obtenerSegunPosicionDato(j);
        }
        delete this->tableroCelda->obtenerSegunPosicionDato(i);
    }
    delete this->tableroCelda;

    delete this->listaCaracteresCubo;
}

void Tablero::cargarParametrosRandom() {
    int minimo = minEntreFilaColumnaProfundidad();
    cantidadCelulasVecinasParaNacer = 1 + rand() % minimo;
    cantidadCelulasVecinasParaSeguirViva1 = 1 + rand() % minimo;
    cantidadCelulaVecinasParaSeguirViva2 = cantidadCelulasVecinasParaSeguirViva1 + 2;

}
int Tablero::minEntreFilaColumnaProfundidad(){
    int minimoTemporal = min(cantidadMaximaPosX,cantidadMaximaPosY);
    return min(minimoTemporal, cantidadMaximaPosZ);
}



void Tablero::setCantCelulasVivasActuale(int nuevaCantCelulas) {
    this->cantidadCelulaVivasActuales = nuevaCantCelulas;

}

void Tablero::aplicarLogicaDelJuego() {
    int cantCelVivas = 0;
    for(int i = 0; i < cantidadMaximaPosX; i++){
        for(int j = 0; j < cantidadMaximaPosY;j++){
            for(int k = 0; k < cantidadMaximaPosZ; k++){
                Celda * unaCelda = obtenerCelda(k, i, j);
                cantCelVivas = unaCelda->obtenerCantCelVivasAdy();
                if((unaCelda->obtenerCelula()->estaMuerta()) && (cantCelVivas == cantidadCelulasVecinasParaNacer)){
                    Lista<Celula*>* unaListaCelulas = new Lista<Celula*>();
                    unaCelda->obtenerCelula()->revivir();
                    int estadoCelda = unaCelda->getEstado();
                    unaListaCelulas = obtenerCelulasVivasActuales(unaCelda->getCeldasAdyacentes() ,unaListaCelulas);
                    unaCelda->obtenerCelula()->heredarCargaGenetica(unaListaCelulas, estadoCelda);
                    cantidadCelulaVivasActuales++;
                    this->cantCelNacidasTurno++;
                    delete unaListaCelulas;
                }
                else if((unaCelda->obtenerCelula()->estaViva()) && (puedeMantenerseConVida(cantCelVivas))){
                    unaCelda->obtenerCelula()->revivir();
                }
                else if( (unaCelda->obtenerCelula()->estaViva())  && not (puedeMantenerseConVida(cantCelVivas)) ){
                    unaCelda->obtenerCelula()->antesVivaAhoraMuerta();
                    unaCelda->obtenerCelula()->matarCelula();
                    cantidadCelulaVivasActuales--;
                    this->cantCelMuertasTurno++;
                }
            }
        }
    }
}
bool Tablero::puedeMantenerseConVida(int cantCelVivas) {
    return ((cantCelVivas >= cantidadCelulasVecinasParaSeguirViva1) && (cantCelVivas <= cantidadCelulaVecinasParaSeguirViva2));

}

Lista<Celula*>* Tablero::obtenerCelulasVivasActuales(Lista<Celda *> *celdaAdyacentes, Lista<Celula*>* listaCelulas) {
    celdaAdyacentes->iniciarCursor();
    int i = 0;
    while(celdaAdyacentes->avanzarCursor() && (i < celdaAdyacentes->getTamanioLista())){
        if(celdaAdyacentes->obtenerCursor()== NULL) {
             i++;
        }
        else if (celdaAdyacentes->obtenerCursor()->obtenerCelula()->estaViva()){
            listaCelulas->insertarElemento(celdaAdyacentes->obtenerCursor()->obtenerCelula());
        }
    }
    return listaCelulas;
}

void Tablero::aumentarTurno() {
    cantTurno++;
}

void Tablero::imprimirTablero() {
    for( int prof = 0; prof < this->cantidadMaximaPosZ; prof++){
        cout << "imprime el tableroCelda en  z = "<< prof << endl;
        for(int i = 0; i < this->cantidadMaximaPosX; i++) {
            for (int j = 0; j < this->cantidadMaximaPosY; j++) {
                Celda *celda = obtenerCelda(prof, i, j);
                std::cout << celda->obtenerCelula()->dibujar();
            }
            cout << "\n";
        }
    }

}

bool Tablero::listasCaracteresSonIguales(Lista<char> *nuevaListaCarct, Lista<char> *caracteresCuboAnt) {
   if( nuevaListaCarct->getTamanioLista() != caracteresCuboAnt->getTamanioLista()){
       return false;
   }
   bool sonIguales = true;
   int i = 0;
   int tamLista = nuevaListaCarct->getTamanioLista();
   while( i < tamLista && sonIguales ){
       if( nuevaListaCarct->obtenerSegunPosicionDato(i) != caracteresCuboAnt->obtenerSegunPosicionDato(i) ){
           sonIguales = false;
       }
       i++;
   }
   return sonIguales;
}

void Tablero::reporteSiseCongeloTablero() {
    Lista<char>* nuevaLista = new Lista<char>();
    if(cantTurno == 1 ){
        insertarCaracteresEnLista(listaCaracteresCubo);
    }

    if(cantTurno >= 2 ){
        insertarCaracteresEnLista(nuevaLista);
    }

    bool iguales = listasCaracteresSonIguales(nuevaLista, listaCaracteresCubo);
    if ( !iguales && cantTurno >= 2){
        delete listaCaracteresCubo;
        listaCaracteresCubo = new Lista<char>() ;
        int i = 0;
        int tamTotal = nuevaLista->getTamanioLista();
        while( i < tamTotal){
            listaCaracteresCubo->insertarElemento( nuevaLista->obtenerSegunPosicionDato(i)  );
            i++;
        }
    }
    if(iguales){
        std::cout<<"El juego se Congelo"<<std::endl;
    }
    else{
        std::cout<<"El juego NO se Congelo"<<std::endl;
    }

    delete nuevaLista;

}

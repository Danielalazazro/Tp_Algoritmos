#include "Juego.h"
#include <iostream>
#include "Tablero.h"
#include "cmath"

using namespace std;

Juego::Juego(){
    ingresoUsuarioMenu = 0;
    modoJuego = 0;
}
int Juego::obtenerModoJuego(){
    return this->modoJuego;
}

void Juego::mostrarModoDeJuego(){
    int modoJuego  = 0;
    cout << "Bienvenido al juego de la vida\n";
    cout << "Modo de configuracion del Juego es:\n";
    cout << "1. El jugador  ingresa las dimensiones del tablero, las posiciones de la celula viva, la cantidad de celula vivas, las cargas genetica.\n"
            "2. El todo es aleatorio . \n"
            "3. El programador ingresa las posiciones de la celula viva , la carga genetica de cada celula\n  "
            "Ingrese el modo de juego : ";
    cin >> modoJuego;
    while( not (modoJuego <= 3 && modoJuego > 0)){
        std::cout<<"Error ingrese un modo de juego correcto: ";
        cin >>modoJuego;
    }
    this->modoJuego = modoJuego;

}


void Juego::configuracionDeJuego(){
    mostrarModoDeJuego();
    if(obtenerModoJuego() == 1) {
        cargarDimensionesDelTableroUsuario();
        cargarCantCelulaVivaNacerySigaViva();
    }
    else if(obtenerModoJuego() == 2){
        cargaDeDimensionesDeTableroAleatoria();
        tablero->cargarParametrosRandom();
        tablero->cargarCelulasVivasyCargaRandom();
    }
    else if(obtenerModoJuego() == 3){
        cargarDimensionesDelTableroUsuario();
        cargarPosicionesyOtroParametros();
    }
    tablero->aumentarTurno();
    tablero->actualizarTablero();
}

void Juego::iniciarJuego(){
    configuracionDeJuego();
    mostrarMenuJuego();
}

//Llamo a las celulas ingresada por el usuario segun el modo de juego elegido.
//

void Juego:: mostrarMenuJuego() {

    while (ingresoUsuarioMenu != 3 ) {
        cout << "\nMenu del Juego de la vida:" << endl;
        cout << " 1. Ejecutar otro turno" << endl;
        cout << " 2. Reiniciar el juego" << endl;
        cout << " 3. Terminar el juego de la vida" << endl;
        cout << "    Ingrese una opcion: " << endl;
        verificadorEnRango(1, 3, &ingresoUsuarioMenu);
        if (ingresoUsuarioMenu == 1) {
            ejecutarOtroTurno();
        } else if (ingresoUsuarioMenu == 2) {
            reiniciarJuego(); //mostrarMenuJuego()
        } else if (ingresoUsuarioMenu == 3) {
            terminarJuego();
        }
    }
}

void Juego::cargarDimensionesDelTableroUsuario(){
    int fila = 0;
    int columna = 0;
    int profundidad = 0;

    cout << "Ingrese la fila del tablero, ";
    verificadorEnRango(minimaDimensionDelTablero, maximaDimensionDelTablero, &fila);
    cout << "Ingrese la columna del tablero, ";
    verificadorEnRango(minimaDimensionDelTablero, maximaDimensionDelTablero, &columna);
    cout << "Ingrese la profundidad del tablero, ";
    verificadorEnRango(minimaDimensionDelTablero, maximaDimensionDelTablero ,&profundidad);

    tablero = new Tablero(fila, columna, profundidad);


}
void Juego::cargaDeDimensionesDeTableroAleatoria(){
    int anchoAleatorio = minimaDimensionDelTablero + rand() %  maximaDimensionDelTablero;
    int altoAleatorio = minimaDimensionDelTablero + rand() % maximaDimensionDelTablero;
    int profundidadAleatorio = minimaDimensionDelTablero + rand() % maximaDimensionDelTablero;
    tablero = new Tablero(anchoAleatorio, altoAleatorio, profundidadAleatorio);
}

void Juego::verificadorEnRango(int limiteinferior, int limiteSuperior, int *ingresoUsuario){
    *ingresoUsuario = -1;
    std::cout << "debe estar entre   "<< limiteinferior << " y   " << limiteSuperior << ": "<<std::endl;
    while((*ingresoUsuario > limiteSuperior ) || (*ingresoUsuario < limiteinferior)){
        std::cin >> *ingresoUsuario;
        if((*ingresoUsuario > limiteSuperior) || (*ingresoUsuario < limiteinferior )) {
            std::cout << "Error rango invalido" << std::endl;
            std::cout << "debe estar entre   "<< limiteinferior << " y " << limiteSuperior << ": "<<std::endl;
        }
    }
}
int Juego::maxCantCelulasVivas(){
    int maximoGeneral = tablero->obtenerFila()* tablero->obtenerColumna() * tablero->obtenerProfundidad();
    return maximoGeneral;

}

void Juego::cargarCantCelulaVivaNacerySigaViva(){
    int cantCelulasVecinasParaNacer, cantidadCelulasSigaViva1, cantidadCelulasSigaViva2, cantidadCelulasVivas;
    cout << "Ingrese la cantidad de celulas vivas (" <<minimoCantCelulaVivas << " a 26):"<<endl;

    verificadorEnRango(minimoCantCelulaVivas, maxCantCelulasVivas(),&cantidadCelulasVivas);
    tablero->setCantCelulasVivasActuales(cantidadCelulasVivas);

    //Tengo que hacer con un while y contador ingreso de posiciones de celulas vivas y la tableroCelda->celula->cargarCargaGenticaUsuario.
    cout << "Ingrese la cantidad de celulas vecinas vivas para que una celula nueva nazca: " <<endl;

    verificadorEnRango(1, tablero->minEntreFilaColumnaProfundidad(), &cantCelulasVecinasParaNacer);

    cout << "Ingrese la cantidad de celulas vecinas  para que una celula siga viva: "<<endl;

    verificadorEnRango(1, tablero->minEntreFilaColumnaProfundidad(), &cantidadCelulasSigaViva1);
    cout << "Ingrese la otra cantidad de celulas vecinas  para que una celula siga viva: "<<endl;

    verificadorEnRango(cantidadCelulasSigaViva1, cantidadCelulasSigaViva1 + 2, &cantidadCelulasSigaViva2);
    tablero->setearCantidadCelulasVivasParaNacer(cantCelulasVecinasParaNacer,cantidadCelulasSigaViva1,cantidadCelulasSigaViva2,1);
}


Juego::~Juego(){
    delete tablero;
}
//
void Juego::cargarPosicionesyOtroParametros() {
    int cantCelulasVecinasParaNacer, cantidadCelulasSigaViva1, cantidadCelulasSigaViva2, cantidadCelulasVivas;
    cout << "Ingrese la cantidad de celulas vivas (" << minimoCantCelulaVivas << " a "<< maxCantCelulasVivas() << "):" ;

    verificadorEnRango(minimoCantCelulaVivas, maxCantCelulasVivas(),&cantidadCelulasVivas);
    tablero->setCantCelulasVivasActuales(cantidadCelulasVivas);
    //Tengo que hacer con un while y contador ingreso de posiciones de celulas vivas y la tableroCelda->celula->cargarCargaGenticaUsuario.

    cantCelulasVecinasParaNacer = 1 + rand() % tablero->minEntreFilaColumnaProfundidad();
    cantidadCelulasSigaViva1 = 1 + rand() % tablero->minEntreFilaColumnaProfundidad();
    cantidadCelulasSigaViva2 = cantidadCelulasSigaViva1 + 2;
    tablero->setearCantidadCelulasVivasParaNacer(cantCelulasVecinasParaNacer,cantidadCelulasSigaViva1,cantidadCelulasSigaViva2, 3);

}

void Juego::ejecutarOtroTurno() {
    tablero->aumentarTurno();
    tablero->actualizarTablero();
}

void Juego::reiniciarJuego() {
    delete tablero;
    iniciarJuego();

}

void Juego::terminarJuego() {
    cout << "Termino el juego, gracias por jugar."<<endl;

}

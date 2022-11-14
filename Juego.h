//
// Created by daniela on 12/10/22.
//

#ifndef TP2_JUEGO_H
#define TP2_JUEGO_H

#include "Tablero.h"
static const unsigned int maximaCelulasVecinasAdy = 26;
static const unsigned int minimoCantCelulaVivas = 2;
class Juego {
private:

    Tablero* tablero;
    int ingresoUsuarioMenu;
    int modoJuego;

public:
    /*
     * pre: -
     * pos: inicializo los atributos de juego.
     */
    Juego();
    /*
     * pre: nos muestra la configuracion del juego.
     * post: Nos solicita el modo de juego que va de 1-3 para continuar el mismo .
     */
     void mostrarModoDeJuego();
    /*
     * pre:  el juego tiene que estar en modo 1 o 3.
     * pos: solicitamos el ingreso de las dimensiones del tablero y lo verificamos; se lo asignamos al contructor del tablero.
     */
    void cargarDimensionesDelTableroUsuario();
    /*
     * pre: el tablero tiene que ser creado.
     * post:Destruye el atributo tablero .
     */
    ~Juego();

    /*
     * pre: el modo de juego tiene que ser 2.
     * post:nos devuelve las dimensiones del tableroCelda con las dimensiones aleatorias.
     */
    void cargaDeDimensionesDeTableroAleatoria();
    /*
     * pre: necesitamos el modo de juego.
     * post: devulve el tablero cargado con las dimensiones del tablero y la cantidad de celulas necesarias para que viva una celula o viva.
     */
    void configuracionDeJuego();
    /*
     * pre: el modo de juego tiene que ser 1.
     * post: cargo la cantidadCelulasVivas, cantCelulasVecinasParaNacer, cantidadCelulasSigaViva1 y la cantidadCelulasSigaViva2.
     */
    void cargarCantCelulaVivaNacerySigaViva();

    /*
     * pre: necesita el limiteSuperior, limiteInferior Y *ingresoUsuario.
     * post:nos devulve *ingresoUsuario verificado  o un mensaje de error en caso contrario.
     */
    void  verificadorEnRango(int limiteInferior, int limiteSuperior, int *ingresoUsuario);
    /*
     * pre: necesitamos el tablero cargado con sus dimensones.
     * post:devuelve el maximoGeneral de las celulas vivas del tablero.
     */
    int maxCantCelulasVivas();
    /*
     * pre: el modo de juego tiene que ser 3.
     * post: Le solcitamos al usuario el ingrseo de  cantidad de celulas vivas,las variables que van a ser de forma
     *       aleatorias son: cantCelulasVecinasParaNacer, cantidadCelulasSigaViva1 y cantidadCelulasSigaViva2.
     */
    void cargarPosicionesyOtroParametros();
    /*
     * pre: se tuvo que escojer el modoJuego, cargar las variables solicitadas en el tablero.
     * pos: devulve el tablero impreso con las variables solicitadas y te muestra el menu del juego.
     */
    void mostrarMenuJuego();
    /*
     * pre: el juego tiene que haber iniciado.
     * post:actualiza el tablero segun las reglas del juego, aumenta la cantidad de turnos
     */
    void ejecutarOtroTurno();
    /*
     * pre: el juego tiene que haber iniciado.
     * pos: se elimina el tablero y se inicia el juego.
     */
    void reiniciarJuego();
    /*
     * pre: el juego tiene que haber iniciado e imprimir el tablero.
     * pos: se deuvel un mensaje de despedida para el usuario.
     */
    void terminarJuego();
    /*
     * pre: se solicita al usuario un modo de juego.
     * pos: se llama a los metodos de configuracion de juego y mostrar menu de juego.
     */
    void iniciarJuego();
};


#endif //TP2_JUEGO_H

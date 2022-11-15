//
// Created by daniela on 29/09/22.
//

#ifndef TP2_CELULAS_H
#define TP2_CELULAS_H
#include "Celula.h"
#include "Lista.h"

class Celda {
private:
    
    Celda****vecinosAdyacentes;
    Lista<Celda*> * celdasAdyacentes;
    int estadoDeCelda; //estadoActual que epuede variar
    Celula* celula;
    int posicionX;
    int posicionY;
    int posicionZ;
public:
    /*
     * pre:-
     * post:inicializo los atributos en 0.
     */
    Celda();
    /*
     * pre:-
     * post: le asigno nuevos parametros a los atributos.
     */
    Celda(int filaIngresa, int columnaIngresada, int profundidadIngresada);
    /*
     * pre: recibe como parametro la cantidad de celulas nacidas.
     * pos: le asiganamos un metodo a cada estado celda.
     */
    void aplicarConportamiento(int *cantCelNacidasTurno);
    /*
     * pre:-
     * post: matamos un gen en este metodo.
     */
    void aplicarEnvenenamiento();

    /*
     * pre:-
     * post: nace una celula nueva ademas de la qu nace por cantidad de celulas vecinas.
     */
    void aplicarPortal(int *cantCelNacidasTurno);
    /*
     * pre:-
     * post: obtengo la celula que es un puntero a celula.
     */
    Celula* obtenerCelula();

    /*
     * pre:-
     * post: eliminamos la celulas adyacentes y la celula creada con memoria dinamica.
     */
    ~Celda();

    /*
     * pre:-
     * post: devolvemos la posicionX de la celda.
     */
    int getPosX();
    /*
     * pre:-
     * post: devolvemos la posicionY de la celda.
     */
    int getPosY();
    /*
     * pre:-
     * post: devolvemos la posicionZ de la celda.
     */
    int getPosZ();
    /*
     * pre: recibo como parametro una celda.
     * pos: inserto una celda a las celdas adyacentes
     */

    void agregarAdyacente(Celda *pCelda);
    /*
     * pre:-
     * post: obtengo la lista de celdas adyacentes.
     */
    Lista<Celda*>* getCeldasAdyacentes();

    void imprimirCelda();

    void revivirCelula();
    /*
     * pre:-
     * pos: devulve tru si el estado de celda es 4.
     */
    bool tieneEstadoProcreadora();
    /*
     * pre:-
     * post: devulve la cantidad de celulas vivas.
     */
    int obtenerCantCelVivasAdy();
    /*
     * pre:-
     * pos: obtengo el estado de celda.
     */
    int getEstado();
    /*
     * pre:-
     * pos: devulve true si el estado de celda es igual a 2 (contaminada).
     */
    bool tieneEstadoContaminada();
    /*
     * pre: recibimos un estado de celda
     * pos: cambio un estado de celda a uno nuevo.
     */
    void setNuevoEstado();

    void setCelula(Celula *celulaIngresada);

    void asignarVecino(int ancho, int alto, int profundidad, Celda *celVecino);
};
#endif //TP2_CELULAS_H

//
// Created by daniela on 29/09/22.
//

#ifndef TP2_CELULA_H
#define TP2_CELULA_H
#include "Gen.h"
#include "Lista.h"
#include "math.h"

static unsigned int maximoGenes = 3;
class Celula {
private:
    int estadoActual;
    int estadoAnterior;
    Gen arrayGen[3];
    char celula;

public:
    /*
     * pre:
     * post: convierte una de las cargagenetica en 0.
     */
    void matarUnGen();
    /*
     * pre:
     * post:constructor inicializo el array de gen en 0 y los otros atributos.
     */
    Celula();
    /*
     * pre:
     * pos:inicializo la carga genetica con los datos ingresados.
     */

    Celula(int  gen1,int  gen2, int  gen3);
    /*
     * pre:
     * post: destructor de celula por defecto.
     */
    ~Celula();
    /*
     * pre:-
     * post:devolvemos un caracter en caso de que este viva o 0 si esta muerta.
     */
    char dibujar();
    /*
     * pre: -
     * post: devulve 0 o 1 si esta viva o muerta.
     */
    bool estaViva();
    /*
     * pre: previmente el estadoActual de la celula es 0 , lo cual indica que esta muerta.
     * post: cambia el estadoActual de la celula a 1.
     */
    void revivir();
    /*
     * pre: recibe la celula sin carga genetica
     * post: cambia el valor de la carga genetica en forma aleatoria.
     */
    void setearCargaGeneticaAleatoria();
    /*
     * pre: recibe las celulas muertas
     * post: devulve las celulas  con las carga geneticas ingresadas por el usuario.
     */
    void setearCargaGeneticaUsuario();
    /*
     * pre: la celula tiene que estar en estado 1 (viva).
     * post: devulve el estado de celula a 0.
     */
    void matarCelula();
    /*
     * pre: la celula tiene que estar creada.
     * post: devulve true si el estado de la celula anterior estaba en 0 y el estado actual 1.
     */
    bool haNacido();
    /*
     * pre: el estado de la celula esta en 1 (viva).
     * post: el estado de la celula esta en 0 (muerta).
     */
    bool estaMuerta();
    /*
     * pre: -
     * post: devolvemos la cargaGenetica de las nuevas celulas generadas por las celulas existentes.
     */
    void heredarCargaGenetica(Lista<Celula *> *celulasVivas, int estadoCelda );
    /*
     * pre:-
     * pos: devolvemos el arrayGen.
     */
    Gen* getArrayGen();
    /*
     * pre: necesitas previamente una lista de celulas vivas.
     * pos: devulvo la carga genetica nueva como el promedio de las celulas vivas .
     */
    void promedioDeCargas(Lista<Celula *> *celulasVivas, int *cargaGen1, int *cargaGen2, int *cargaGen3);
    /*
     * pre: necesitamos la lista de celulas vivas que contengan sus cargas geneticas.
     * post: nos devulve el minimo de la carga genetica.
     */
    void minimoDeCargas(Lista<Celula *> *celulasVivas, int *cargaGen1, int *cargaGen2, int *cargaGen3);
    /*
     * pre: necesitamos la lista de celulas vivas que contengan sus cargas geneticas.
     * post: nos devuelve el maximo de la carga genetica de las celulas vivas.
     */
    void maximoDeCargas(Lista<Celula *> *celulasVivas, int *pGen, int *pInt, int *pInt1);
    /*
     * pre: tiene que tener una celda.
     * pos: nos muestra los estados de una celula que antes estaba viva ahora muerta.
     */
    void antesVivaAhoraMuerta();

    int obtenerCargaGeneticaPredominante();
    /*
     * pre: la posicion del arrayGen tiene que ser de 0 a 2.
     * pos: devulve la cargaGenetica del arrayGen.
     */
    int obtenerCargaEnPos(int posicion);
};


#endif //TP2_CELULA_H

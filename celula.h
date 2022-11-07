//
// Created by daniela on 29/09/22.
//

#ifndef TP2_CELULA_H
#define TP2_CELULA_H
#include "Gen.h"
#include "Lista.h"

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
     * post: convierte la cargagenetica en 0.
     */
    void matarUnGen();
    /*
     * pre:
     * post:
     */
    Celula();

    Celula(int  gen1,int  gen2, int  gen3);
    /*
     * pre:
     * post:
     */
    ~Celula();
    /*
     * pre:
     * post:
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
     * post: cambia el valor de la carga genetica.
     */
    void setearCargaGeneticaAleatoria();
    /*
     * pre: recibe el tableroCelda con celulas muertas
     * post: devulve el tableroCelda con las carga geneticas ingresadas por el usuario.
     */
    void setearCargaGeneticaUsuario();
    /*
     * pre:
     * post:
     */
    void matarCelula();
    /*
     * pre:
     * post:
     */
    bool haNacido();
    /*
     * pre:
     * post:
     */
    bool estaMuerta();
    /*
     * pre:
     * post:
     */
    void heredarCargaGenetica(Lista<Celula *> *celulasVivas, int estadoCelda );
    /*
     * pre:
     * post:
     */
    Gen* getArrayGen();
    /*
     * pre:
     * post:
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
};


#endif //TP2_CELULA_H

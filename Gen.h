//
// Created by daniela on 01/10/22.
//

#ifndef TP2_GEN_H
#define TP2_GEN_H
#include "math.h"

static const unsigned int maximaCargaGenetica = 255;

class Gen{
private:
    unsigned int cargaGenetica;
public:
    /*
     * pre:-
     * post:constructor por defecto.
     */
    Gen();
    /*
     * pre:-
     * post: inicializamos el atributo.
     */
    Gen(unsigned int cargaGenetica);
    /*
     * pre: el gen tiene que ser creado.
     * post: destructor por defecto.
     */
    virtual ~Gen();
    /*
     * pre:-
     * post: devolvemos el valor de la carga genetica.
     */
    unsigned int getCargaGenetica();

    /*
     * pre: esperamoe le ingreso de la carga genetica
     * post: verificamos la carga genetica y devulve tru si esta en el rango entre y la maximaCargaGenetica.
     */
    bool verificarEnRango(unsigned int cargaGenetica );
    /*
     * pre: nesecita las posiciones de la celula.
     * post: asignamos  al atributo de cargaGenetica lo ingresado entr el usuario .
     */
    void insertarCargaUsuario();

    /*
     * pre:-
     * post:nos devuelve true o false  para virificar si esta vivo el gen.
     */
    bool estaVivoGen();
    /*
     * pre: por lo menos una carga genetica de la celula tiene que ser mayor a 0.
     * post: convierte la carga genetica a 0.
     */
    void matarGen();

};
#endif //TP2_GEN_H

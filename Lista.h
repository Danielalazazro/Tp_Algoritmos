//
// Created by daniela on 05/10/22.
//

#ifndef EJERCICIO_1_LISTA_H
#define EJERCICIO_1_LISTA_H
#include "Nodo.h"

class Lista {
private:
    Nodo* p;
public:
    Lista();//Constructor sin argumentos (agregar el constructor copia)
    ~Lista();//Destructor
    void altaFin(int );//Alta al final
    void altaPrin(int);//Alta al principio
    void baja(int);//Baja de la primera aparicion de un elemento determinado
                //Modificado para que realice la baja de todas las aparicione
    bool esta(int);//Retorna un bool indicado si el enetero pasado por argumento esta en la lista.
    void emite();//emite la lista

    //Alta al final realiza un alta al final de la lista
    //Como precondicion la lista debe exitir
    //esta quedara modificada luego del alta.
    //recibe por argumento el dato al insertar.







};


#endif //EJERCICIO_1_LISTA_H

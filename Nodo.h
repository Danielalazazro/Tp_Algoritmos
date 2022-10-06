//ListaSimpleItera
#ifndef EJERCICIO_1_NODO_H
#define EJERCICIO_1_NODO_H


class Nodo {
private:
    int info;

    Nodo* sig;

public:
    Nodo(int,Nodo*);

    int getInfo();

    Nodo* getSig();

    void setInfo(int i);

    void setSig(Nodo* n);

};


#endif //EJERCICIO_1_NODO_H

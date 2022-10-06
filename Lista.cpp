//
#include "Lista.h"
#include <iostream>

using namespace std;
/*
 * altaFin realiza un alta al final de la lista
 * como precondicion la lista debe exitir
 * esta quedara modificada luego del alta
 * recibe por argumento el dato a insertar
 */
void Lista::altaFin(int x) {
    Nodo *aux = p;
    while ((aux) && (aux->getSig())) {
        aux = aux->getSig();
    }
    if (aux){
        aux->setSig(new Nodo(x,0));
    }
    else{
        p = new Nodo(x,p);
    }
}
/*
 * altaPrin realiza un alta al final de la lista como precondicion
 * la lista debe exitir esta quedara modificada luego del alta
 * recibe por argumento el dato a insertar
 */
void Lista::altaPrin(int X) {
    p = new Nodo(X,p);
}

/*
 * Baja elimina la primera aparicion del dato pasado por argumento
 *como precondicion la lista debe exitir y no debe estar vacia
 * esta quedara modificada luego de la baja.
 * recibe por argumento el dato al eliminar
 * se propone modificar este codigo todas la apariciones del dato
 */
void Lista::baja(int x){
    if(p){
        if((p->getInfo() != x)&&(p->getSig())){
            Nodo *aux1 = p, *aux2 = p->getSig();
            while((aux2->getInfo() != x)&&(aux2->getSig() != NULL)){
                aux1 = aux2;
                aux2 = aux2 ->getSig();
            }

            if(aux2->getInfo() == x){
                aux1->setSig(aux2->getSig());
                delete aux2;
            }
            else if(p->getInfo() == x){
                Nodo* aux = p;
                p = p->getSig();
                delete aux;
            }
        }
    }
}
Lista::~Lista() {
    if(p){
        Nodo* aux = p;
        while (aux){
            p = p->getSig();
            delete aux;
            aux = p;
        }
    }
}

/*
 * Esta retorna un valor logico indicando si el dato pasado esta en la lista
 * como precondicion la lista debe exitir
 * no modifica de modo alguno la instancia sobre cual trabaja(podemos indicarlo//como
 * metodo const)
 *
 */
bool Lista::esta(int x){
    Nodo* aux = p;
    while(aux){
        if(aux->getInfo()==x){
            return true;
        }
        else{
            aux = aux->getSig();
        }
    }
    return false;
}
/*
 * Emite hace una emision por pantalla del contenido
 * de la lista como precondicion de la lista debe exitir
 * no modifica indicarselo como metodo const
 */
void Lista::emite() {
    Nodo* aux = p;
    while (aux){
        cout << aux->getInfo();
        aux = aux->getSig();
    }
}
/*
 * Constructor :crea la lista , inicalizando sus atributos
 * de modo que quede en condiciones de ser utilizada (la crea vacia)ç
 * NO tiene precondiciones
 * Post:lista vacia
 */
Lista::Lista():p(0){

}

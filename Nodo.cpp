//
#include "Nodo.h"
#include <iostream>

using namespace std;
Nodo* Nodo::getSig() {
    return sig;

}
int Nodo::getInfo() {
    return info;
}
void Nodo::setSig(Nodo *n) {
    sig = n;
}
void Nodo::setInfo(int i) {
    info = i;

}
Nodo::Nodo(int X, Nodo * p) {
    info = X;
    sig = p;

}

//
// Created by daniela on 04/09/23.
//

#ifndef TRABAJOS_PRACTICOS_ALGO2_CASILLA_H
#define TRABAJOS_PRACTICOS_ALGO2_CASILLA_H
#include <string>

class Casilla {
private:
    //cambiar nombre
    std::string caracter;
    int estado;


public:
    //Inicializo los atributos
    Casilla();
    //Coloco el caracter de tesosro en el tablero
    void setContenido(std::string caracterNuevo);
    //Coloco los espias en el tablero
    void colocarEspias();
    //metodo que coloco los tesoros
    void colocarTesoro(std::string simbolo);
    //Obtener contenido del casillero
    std::string obtenerContenido();
    //Inhabilitar la casilla
    void inhabilitar();
    //Destructor de casillero
    ~Casilla();

};


#endif //TRABAJOS_PRACTICOS_ALGO2_CASILLA_H

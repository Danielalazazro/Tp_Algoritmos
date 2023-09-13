//
// Created by daniela on 02/09/23.
//

#ifndef TP1_AUX__ESPIA_H
#define TP1_AUX__ESPIA_H


#include <string>

class Espia {
private:
    int fila;
    int columna;
    std::string simbolo;
public:
    const std::string &getSimbolo() const;
public:
    /*
     * Este metodo es el constructor del Espia, donde se inicilizan los atributos, por defecto.
     */
    Espia();
    /*
     *Este metodo es el constructor del Espia, donde se inicilizan los atributos con los parametros recibidos.
     */
    Espia(int fila, int columna, std::string simbolo);
    /*
     * En este metodo se obtiene la fila.
     */
    int obtenerFila();
    /*
     * En este metodo se obtiene la columna
     */
    int obtenerColumna();
    /*
     * En este metodo se puede cambiar la fila del espia
     */
    void setearFila(int filaNueva);
    /*
     * En este metodo se puede cambiar la columna del espia.
     */
    void setearColumna(int columnaNueva);
    /*
     * En este metodo se puede setear el simbolo del espia.
     */
    void setearSimboloEspia(std::string nuevoSimbolo);
    /*
     * En este metodo elimina el espia cambiando el simbolo a un caracter vacio.
     */
    void eliminar();
    /*
     * Destructor de espia.
     */
    ~Espia();
};



#endif //TP1_AUX__ESPIA_H

//
// Created by daniela on 01/09/23.
//

#ifndef TP1_AUX__TESORO_H
#define TP1_AUX__TESORO_H

#include <string>

static int const TESOROS = 4;
static int const TURNOSINHABILITADO = 5;
class Tesoro {
private:
    int fila;
    int columna;
    int turnoHabilitado;
    bool estado;
    std::string simbolo;
    int turnoEncontrado;
public:
    /*
     * En este metodo es el constructor de Tesoro
     */
    Tesoro();
    /*
     * En este metodo se inicializa los atributos de Tesoro.
     */
    Tesoro(int fila, int columna, std::string simbolo);
    /*
     * En este metodo se obtiene la fila.
     */
    int getFila();
    /*
     *En este metodo se obtiene la columna.
     */
    int getColumna();
    /*
     * En este metodo se puede cambiar la fila.
     */
    void setearFila(int filaNueva);
    /*
     * En este metodo se puede cambiar la columna.
     */
    void setearColumna(int columnaNueva);
    /*
     * En este metodo se puede cambiar el simbolo del tesoro.
     */
    void setearSimbolo(std::string simboloNuevo);
    /*
     * En este metodo se puede cambiar el turno esncontrado.
     */
    void setearTurnoEncontrado(int turno);
    /*
     * Verifica que este estado el tesoro.
     */
    bool estaActivo();
    /*
     * En este metodo se obtiene el simbolo del tesoro.
     */
    std::string getSimbolo();
    /*
     * En este metodo se obtiene el turno en el cual fue encontrado el tesoro.
     */
    int getTurnoEncontrado();
    /*
     * En este metodo se puede desaticar el tesoro, cambiando su estado a false.
     */
    void desactivarTesoro();
    /*
     * En este metodo se cambia el estado a true.
     */
    void activarTesoro();
    /*
     * Este metodo es el destructor del tesoro.
     */
    ~Tesoro();
};


#endif //TP1_AUX__TESORO_H

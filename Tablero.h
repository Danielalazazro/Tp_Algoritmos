

#ifndef TP2_TABLERO_H
#define TP2_TABLERO_H
#include "Celda.h"
#include "Lista.h"
//#include "Imprimir.h"

class Tablero {

private:
    int cantidadMaximaPosX;

    int cantidadMaximaPosY;

    int cantidadMaximaPosZ;

    Lista<Lista<Lista<Celda*>*>*>* tableroCelda;

    int cantidadCelulaVivasActuales;

    int cantidadCelulasVecinasParaNacer;

    int cantidadCelulasVecinasParaSeguirViva1;

    int cantidadCelulaVecinasParaSeguirViva2;

    int cantidadCelulasMuertasTotales;

    int cantidadCelulasNacidasTotales;

    int cantCelNacidasTurno;

    int cantCelMuertasTurno;

    int cantTurno;

    Lista<char>* listaCaracteresCubo;





public:
    /*
     * pre:-
     * post:Inicializo los atributos de la clase tableroCelda.
     */
    Tablero();
    /*
     * pre: Los argumentos deben ser mayores a  0
     * post: Crea un tableroCelda de dimensiones cantidadFilas por cantidadClumnas por cantidadProfundidad  = cantidad de celdas
     *      Te devulve una excepscion si no cumple con la precondicion.
     */

    Tablero(int cantidadFila,int cantidadClumnas, int cantidadProfundidad);

    /*
     * pre: filaIngresada , columnaIngresada , profundidadIngresada debe ser mayor a cero y debe estar dentro de las dimensione
     *      del tableroCelda
     * post:Retorna la posicion en memoria de la tableroCelda ubicado en las coordenadas introducidas.
     */
    Celda* obtenerCelda(int posicionZ, int posicionX, int poscionY);

    /*
     * pre: tenemos que tener creado el tablero.
     * post: - Destruye la memoria pedida para el tableroCelda , junto con las celdas que lo componen
     *       -y pone todo los cojuntos de punteros a null.
     */
    virtual ~Tablero();
    /*
     * pre: tenemos que tener creado el tablero  con la cantiad de celulas vivas .
     * post: nos devulve el tablero impreso en la terminal.
     */
    void imprimirTableroyResumen();
    /*
     * pre:-
     * post:obtenemos la fila .
     */
    int obtenerFila();
    /*
     *pre:-
     *pos:nos devulve el valor de la columna.
     */
    int obtenerColumna();
    /*
     * pre:-
     * post:nos devulve el valor de la profundidad.
     */
    int obtenerProfundidad();

    /*
    * pre:-
    * post:Nos devuleve las las diemensiones del tablero en forma aleatoria.
    */
    void  asignarValoresAleatoria(int *filaAleatoria, int *columnaAleatoria, int *profundidadAleatoria);
    /*
     * pre: recibimos  el limite inferior que tiene que ser mayor a 0 y ele limite superior.
     * post:Nos verifica el numero ingresado por el usuario este entre el rango de 1 a el limite superior.
     */
    void verificarIngresoUsuario(int limiteSuperior, int* ingresoUsuario);
    /*
     * pre: necesitamos que el modo de juego sea 1 o 3.
     * post: nos devulve las celulas cargadas en el tableroCelda.
     */
    void cargarCelulaUsuario(int modoJuego);
    /*
     * pre: si el modo de juego es 2.
     * post: devuelve el tableroCelda con celulas aleatorias.
     */
    void cargarCelulasVivasyCargaRandom();
    /*
     * pre: recibo como parametros las  cantCelulasParaNacer, cantCelulasParaSeguirViva1, cantCelulasParaSeguirViva2 y modoJuego
     * post:cambio los valores de los atributos cantCelulasParaNacer, cantCelulasParaSeguirViva1, cantCelulasParaSeguirViva2 y modoJuego
     */
    void setearCantidadCelulasVivasParaNacer(int cantCelulasParaNacer , int cantCelulasParaSeguirViva1, int cantCelulasParaSeguirViva2, int modoJuego);
    /*
     * pre: el tablero tiene que estar creado con las celulas vivas
     * pos: lo imprime previamente antes de ejecutar un turno ,actualizo el tablero con las reglas del juego , tambien acumula la cantidadCelulaVivasActuales ,
     *      cantCelMuertasTurno, cantidadCelulasNacidasTotales y la cantidadCelulasMuertasTotales.
     */
    void actualizarTablero();
    /*
     * pre: tiene que estar en el estado de celda procreadora.
     * pos:cambio la cantidad de celulas vivas para nacer.
     */
    void setCantCelulasVivasParaNacer();
    /*
     * pre: las dimensiones del tablero tienen que ser mayor a 3.
     * post:nos devulve el minimo de las dimensiones del tablero.
     */
    int minimoDeLasDimensionesTablero();

    /*
     * pre: el usuario debe ingresar las posicionees de las celdas vivas.
     * post:devulve el analisis de con las celdas adyacentes a la celda que tiene a la celuls viva.
     */

    void asignarCeldasAdayacentes(Celda*unaCelda);
    /*
     * pre: el modo de juego tiene que ser igual a 2.
     * pos:devulve una cantidadCelulasVecinasParaNacer, cantidadCelulasVecinasParaSeguirViva1 y cantidadCelulaVecinasParaSeguirViva2 en forma aleatoria.
     */
    void cargarParametrosRandom();
    /*
     * pre: las dimensiones del tablero tienen que ser cargadas.
     * post:buscamos el minimo entre cantidadMaximaPosX , cantidadMaximaPosY y cantidadMaximaPosZ (son las dimensiones del tablero).
     */
    int minEntreFilaColumnaProfundidad();
    /*
     * pre: -
     * pos:cambiamos la cantidadCelulaVivasActuales.
     */
    void setCantCelulasVivasActuales(int nuevaCantCelulas);
    /*
     * pre: las dimensiones del tablero tienen que estar cargados , las celulas vivas , las celuas necesarias para que una celula siga viva  y para que nazca
     * pos: devolvemos o aplicamos las reglas del juego.
     */
    void aplicarLogicaDelJuego();
    /*
     * pre: se debe ingresar la cantidad de celulas vivas.
     * pos:devulve verdadero si la cantCelVivas se encuentras entre cantidadCelulaVecinasParaSeguirViva1 y cantidadCelulaVecinasParaSeguirViva2 .
     */

    bool puedeMantenerseConVida(int vivas);
    /*
     * pre: recibimos como parametros una una lista de celdaAdyacentes de tipo puntero a esa lista de Celda puntero ,
     * pos: devulve una lista puntero de Celula puntero.
     */

    Lista<Celula*>* obtenerCelulasVivasActuales(Lista<Celda *> *celdaAdyacentes ,Lista<Celula*>* listaCelulas);
    /*
     * pre: el tablero tiene que estar creado.
     * post: recorremos el tablero y le asiganamos un estado aleatorio de 1 al 5.
     */
    void actualizarEstadoDeCeldas();
    /*
     * pre: si el usuario ejecuta otro turno .
     * pos: incrementamos la cantidad de turnos.
     */
    void aumentarTurno();
    /*
     * pre: tiene que estar caragdos sus dimensiones , la cantidad de celulas vivas , necesarias para que viva y  siga viva
     * pos: imprime el tablero con las celulas vivas y las imagenes bmp.
     */
    void imprimirTablero();
    /*
     * pre: tenemos 2 listas nuevaListaCarct y la otra  de caracteresCuboAnt.
     * pos: retorna verdadero  si los caracteres de la nuevaListaCarct   son iguales a  caracteresCuboAnt.
     */

    bool listasCaracteresSonIguales(Lista<char> *nuevaListaCarct, Lista<char> *caracteresCuboAnt);
    /*
     * pre: el tablero tiene que estar cargado con celulas vivas , las mismas se representar con caracteres.
     * pos:recorremos el tablero e insertamos en la lista la celda con sus caracteres.
     */
    void insertarCaracteresEnLista(Lista<char> *listaInsertar);
    /*
     * pre: tenemos dos lista con los caracteres del tablero uno es anterior de ejecutar un turno y la otra posterior .
     * pos:evaluamos si el juego se congelo e imprimimos un mensaje  sobre el mismo.
     */
    void reporteSiseCongeloTablero();

};

#endif //TP2_TABLERO_H

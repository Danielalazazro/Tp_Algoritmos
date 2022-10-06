//
// Created by daniela on 01/10/22.
//

#ifndef TP2_GEN_H
#define TP2_GEN_H

static const unsigned int maximaCargaGenetica = 255;

class Gen {
private:
    unsigned int cargaGenetica;

public:
    /*
     * pre:
     * post:
     */
    Gen();
    Gen(unsigned int cargaGenetica);
    virtual ~Gen();
    /*
     * pre:
     * post:
     */
    unsigned int getCargaGenetica();
    /*
     *pre:
     *post:
     */
    unsigned int getMaximoDeCargaGenetica();
    /*
     * pre:
     * post:
     */
    void setCargaGenetica(unsigned int cargaGenetica);
    /*
     * pre:
     * post:
     */
    bool verificarEnRango(unsigned int cargaGenetica );

};


#endif //TP2_GEN_H

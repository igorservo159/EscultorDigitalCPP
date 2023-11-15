#ifndef FIGURAGEOMETRICA_H
#define FIGURAGEOMETRICA_H
#include "Sculptor.h"

class FiguraGeometrica{
protected:
    float r, g, b, a;
public:
    virtual ~FiguraGeometrica(){}
    /**
    * @brief Método abstrato que servirá para a implementação singular de cada classe concreta.
    * @param s escultor no qual será realizado os desenhos.
    */
    virtual void draw(Sculptor &s) = 0;
};

#endif 
#ifndef PUTBOX_H
#define PUTBOX_H
#include "FiguraGeometrica.h"
#include "Sculptor.h"

class PutBox : public FiguraGeometrica{
protected:
    int x0, x1, y0, y1, z0, z1;
    float r, g, b, a;

public:
    PutBox(int _x0, int _x1, int _y0, int _y1, int _z0, int _z1, float _r, float _g, float _b, float _a);
    /**
    * @brief Método draw para o putBox.
    * @details Cria uma caixa de voxels nos limites x0 a x1, y0 a y1, z0 a z1.
    * @param x0 Coordenada X do limite inferior de criação da caixa.
    * @param y0 Coordenada Y do limite inferior de criação da caixa.
    * @param z0 Coordenada Z do limite inferior de criação da caixa.
    * @param x1 Coordenada X do limite superior de criação da caixa.
    * @param y1 Coordenada Y do limite superior de criação da caixa.
    * @param z1 Coordenada Z do limite superior de criação da caixa.
    */
    void draw(Sculptor &s);
};

#endif
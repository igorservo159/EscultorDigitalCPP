#ifndef CUTBOX_H
#define CUTBOX_H

#include "FiguraGeometrica.h"

class CutBox : public FiguraGeometrica{
    int x0; int x1; int y0; int y1; int z0; int z1;
public:
    CutBox(int x0, int x1, int y0, int y1, int z0, int z1);
    /**
    * @brief Método draw para o cutBox.
    * @details Retira uma caixa de voxels nos limites x0 a x1, y0 a y1, z0 a z1.
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
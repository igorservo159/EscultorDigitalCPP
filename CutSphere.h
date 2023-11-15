#ifndef CUTSPHERE_H
#define CUTSPHERE_H

#include "FiguraGeometrica.h"

class CutSphere : public FiguraGeometrica{
    int x0, y0, z0, raio;
public:
    CutSphere(int _x0, int _y0, int _z0, int _raio);
    /**
    * @brief Método draw para o cutSphere.
    * @details Retira uma esfera de voxels.
    * @param x0 Coordenada X do centro da elipsoide.
    * @param y0 Coordenada Y do centro da elipsoide.
    * @param z0 Coordenada Z do centro da elipsoide.
    * @param raio Raio da esfera.
    */
    void draw(Sculptor &s);
};

#endif
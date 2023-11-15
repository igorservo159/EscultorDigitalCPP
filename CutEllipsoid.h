#ifndef CUTELLIPSOID_H
#define CUTELLIPSOID_H

#include "FiguraGeometrica.h"

class CutEllipsoid : public FiguraGeometrica
{
    int x0; int y0; int z0; int rx; int ry; int rz;
public:
    CutEllipsoid(int _x0, int _y0, int _z0, int _rx, int _ry, int _rz);
    /**
    * @brief Método draw para o cutEpllipsoid.
    * @details Retira uma elipsoide de voxels.
    * @param x0 Coordenada X do centro da elipsoide.
    * @param y0 Coordenada Y do centro da elipsoide.
    * @param z0 Coordenada Z do centro da elipsoide.
    * @param rx Raio X da elipsoide.
    * @param ry Raio Y da elipsoide.
    * @param rz Raio Z da elipsoide.
    */
    void draw(Sculptor &s);
};

#endif
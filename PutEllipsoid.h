#ifndef PUTELLIPSOID_H
#define PUTELLIPSOID_H
#include "FiguraGeometrica.h"
#include "Sculptor.h"

class PutEllipsoid : public FiguraGeometrica{
protected:
    int x0, y0, z0, rx, ry, rz;
    float r, g, b, a;
public:
    PutEllipsoid(int _x0, int _y0, int _z0, int _rx, int _ry, int _rz, float _r, float _g, float _b, float _a);
    /**
    * @brief Método draw para o putEpllipsoid.
    * @details Cria uma elipsoide de voxels.
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
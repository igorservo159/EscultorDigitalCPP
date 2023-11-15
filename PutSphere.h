#ifndef PUTSPHERE_H
#define PUTSPHERE_H
#include "FiguraGeometrica.h"
#include "Sculptor.h"

class PutSphere : public FiguraGeometrica{
protected:
    int x0, y0, z0, raio;
    float r, g, b, a;

public:
    PutSphere(int _x0, int _y0, int _z0, int _raio, float _r, float _g, float _b, float _a);
    /**
    * @brief Método draw para o putSphere.
    * @details Cria uma esfera de voxels.
    * @param x0 Coordenada X do centro da elipsoide.
    * @param y0 Coordenada Y do centro da elipsoide.
    * @param z0 Coordenada Z do centro da elipsoide.
    * @param raio Raio da esfera.
    */
    void draw(Sculptor &s);
};

#endif
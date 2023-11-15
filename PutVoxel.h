#ifndef PUTVOXEL_H
#define PUTVOXEL_H
#include "FiguraGeometrica.h"
#include "Sculptor.h"


class PutVoxel : public FiguraGeometrica{
protected:
    int x, y, z;
    float r, g, b, a;

public:
    PutVoxel(int _x , int _y, int _z, float _r, float _g, float _b , float _a);
    /**
    * @brief Método draw para o cutVoxel.
    * @details Retira um voxel na coordenada (x, y, z).
    * @param x Coordenada X do voxel.
    * @param y Coordenada Y do voxel.
    * @param z Coordenada Z do voxel.
    */
    void draw(Sculptor &s);
};

#endif
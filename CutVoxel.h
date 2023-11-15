#ifndef CUTVOXEL_H
#define CUTVOXEL_H
#include "FiguraGeometrica.h"
#include "Sculptor.h"

class CutVoxel : public FiguraGeometrica{
protected:
    int x, y, z;
public:
    CutVoxel(int _x , int _y, int _z);
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
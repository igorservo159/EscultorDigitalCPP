#include "PutVoxel.h"
#include "Sculptor.h"

PutVoxel::PutVoxel(int _x , int _y, int _z, float _r, float _g, float _b , float _a){
    x = _x;
    y = _y;
    z = _z;
    r = _r;
    g = _g;
    b = _b;
    a = _a;
}

void PutVoxel::draw(Sculptor &s){
    s.setColor(r, g, b, a);
    s.putVoxel(x, y, z);
}
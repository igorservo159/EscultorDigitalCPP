#include "CutVoxel.h"
#include "Sculptor.h"

CutVoxel::CutVoxel(int _x, int _y, int _z){
    x = _x;
    y = _y;
    z = _z;
}

void CutVoxel::draw(Sculptor &s){
    s.cutVoxel(x, y, z);
}
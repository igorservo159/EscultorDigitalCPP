#include "PutEllipsoid.h"
#include "Sculptor.h"
#include <math.h>

PutEllipsoid::PutEllipsoid(int _x0, int _y0, int _z0, int _rx, int _ry, int _rz, float _r, float _g, float _b, float _a){
    x0 = _x0;
    y0 = _y0;
    z0 = _z0;
    rx = _rx;
    ry = _ry;
    rz = _rz;
    r = _r;
    g = _g;
    b = _b;
    a = _a;
}

void PutEllipsoid::draw(Sculptor &s){
    s.setColor(r, g, b, a);
    int x_limit = x0 - rx;
    int y_limit = y0 - ry;
    int z_limit = z0 - rz;

    for (int i = x_limit; i < x_limit + 2 * rx; i++) {
        for (int j = y_limit; j < y_limit + 2 * ry; j++) {
            for (int k = z_limit; k < z_limit + 2 * rz; k++) {
                if ((pow(i - x0, 2) / pow(rx, 2)) +
                        (pow(j - y0, 2) / pow(ry, 2)) +
                        (pow(k - z0, 2) / pow(rz, 2)) <
                    1) {
                s.putVoxel(i, j, k);
                }
            }
        }
    }
    
}
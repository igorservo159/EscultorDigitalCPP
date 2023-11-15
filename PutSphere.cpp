#include "PutSphere.h"
#include "Sculptor.h"
#include <math.h>

PutSphere::PutSphere(int _x0, int _y0, int _z0, int _raio, float _r, float _g, float _b, float _a){
    x0 = _x0;
    y0 = _y0;
    z0 = _z0;
    raio = _raio;
    r = _r;
    g = _g;
    b = _b;
    a = _a;
}

void PutSphere::draw(Sculptor &s){
    s.setColor(r, g, b, a);
    int x_limit = x0 - raio;
    int y_limit = y0 - raio;
    int z_limit = z0 - raio;

    for (int i = x_limit; i < x_limit + 2 * raio; i++) {
        for (int j = y_limit; j < y_limit + 2 * raio; j++) {
            for (int k = z_limit; k < z_limit + 2 * raio; k++) {
                if ((pow((i - x0), 2) + pow((j - y0), 2) +
                    pow((k - z0), 2)) < pow(raio, 2)) {
                    s.putVoxel(i, j, k);
                }
            }
        }
    }
    
}
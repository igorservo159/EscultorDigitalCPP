#include <iostream>
#include <fstream>
#include <string>
#include "Voxel.h"
#include "Sculptor.h"
#include "Interpretador.h"
#include <vector>
#include "PutVoxel.h"
#include "PutBox.h"
#include "PutSphere.h"
#include "PutEllipsoid.h"
#include "CutVoxel.h"
#include "CutBox.h"
#include "CutSphere.h"
#include "CutEllipsoid.h"
#include "FiguraGeometrica.h"
using namespace std;

int main(){
    Sculptor *s;
    Interpretador inter;
    vector<FiguraGeometrica*> fig;

    fig = inter.interpretar("input.txt");

    s = new Sculptor(inter.getdimx(), inter.getdimy(), inter.getdimz());
    for (size_t x=0; x<fig.size(); x++){
        fig[x] -> draw(*s);
    }

    s->writeOFF((char*)"teste.off");

    for (size_t x=0; x<fig.size(); x++){
        delete fig[x];
    }
    
    delete s;

    return 0;
}
#include <iostream>
#include <cstdlib>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include "PutVoxel.h"
#include "PutBox.h"
#include "PutSphere.h"
#include "PutEllipsoid.h"
#include "CutVoxel.h"
#include "CutBox.h"
#include "CutSphere.h"
#include "CutEllipsoid.h"
#include "Interpretador.h"


using namespace std;

Interpretador::Interpretador(){}

vector<FiguraGeometrica*> Interpretador:: interpretar(string filename){

    vector<FiguraGeometrica*> figuras;
    ifstream file;
    string stng,var;
    stringstream ss;

    file.open(filename.c_str());

    if(!file.is_open()){
        exit(0);
    }

    while(getline(file,stng)){

        ss.clear();
        ss.str(stng);
        ss >> var;
        cout << var << " ";

        if(var.compare("dim")==0){
            ss >> dimx >> dimy >> dimz;
        }
        else if(var.compare("putvoxel")==0){
            int x_,y_,z_;
            ss >> x_ >> y_ >> z_ >> r >> g >> b >> a;
            figuras.push_back(new PutVoxel(x_, y_, z_, r, g, b, a));
        }
        else if(var.compare("cutvoxel")==0){
            int x_, y_, z_;
            ss >> x_ >> y_ >> z_;
            figuras.push_back(new CutVoxel(x_, y_, z_));
        }
        else if(var.compare("putbox")==0){
            int x0; int x1; int y0; int y1; int z0; int z1;
            ss >> x0 >> x1 >> y0 >> y1 >> z0 >> z1 >> r >> g >> b >> a;
            figuras.push_back(new PutBox(x0, x1, y0, y1, z0, z1, r, g, b, a));
        }
        else if(var.compare("cutbox")==0){
            int x0; int x1; int y0; int y1; int z0; int z1;
            ss >> x0 >> x1 >> y0 >> y1 >> z0 >> z1;
            figuras.push_back(new CutBox(x0, x1, y0, y1, z0, z1));
        }
        else if(var.compare("putsphere")==0){
            int x0; int y0; int z0; int raio;
            ss >> x0 >> y0 >> z0 >> raio >> r >> g >> b >> a;
            figuras.push_back(new PutSphere(x0, y0, z0, raio, r, g, b, a));
        }
        else if(var.compare("cutsphere")==0){
            int x0; int y0; int z0; int raio;
            ss >> x0 >> y0 >> z0 >> raio;
            figuras.push_back(new CutSphere(x0, y0, z0, raio));
        }
        else if(var.compare("putellipsoid")==0){
            int x0, y0, z0, rx, ry, rz;
            ss >> x0 >> y0 >> z0 >> rx >> ry >> rz >> r >> g >> b >> a;
            figuras.push_back(new PutEllipsoid(x0, y0, z0, rx, ry, rz, r, g, b, a));
        }
        else if(var.compare("cutellipsoid")==0){
            int _x0, _y0, _z0, _rx, _ry, _rz;
            ss >> _x0 >> _y0 >> _z0 >> _rx >> _ry >> _rz;
            figuras.push_back(new CutEllipsoid(_x0, _y0, _z0, _rx, _ry, _rz));
        }
    }

    file.close();
    return(figuras);
}

int Interpretador::getdimx(){
    return dimx;
}

int Interpretador::getdimy(){
    return dimy;
}

int Interpretador::getdimz(){
    return dimz;
}
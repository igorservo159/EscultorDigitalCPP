#include "Sculptor.h"
#include <fstream>
#include <iostream>
#include <math.h>

Sculptor::Sculptor(int _nx, int _ny, int _nz) {
  nx = _nx;
  ny = _ny;
  nz = _nz;

  v = new Voxel **[nx];
  v[0] = new Voxel *[nx * ny];
  v[0][0] = new Voxel[nx * ny * nz];

  for (int i = 0; i < nx; i++) {
    v[i] = v[0] + i * ny;
    for (int j = 0; j < ny; j++) {
      v[i][j] = v[0][0] + (i * ny * nz + j * nz);
    }
  }
}

Sculptor::~Sculptor() {
  delete[] v[0][0];
  delete[] v[0];
  delete[] v;
}

void Sculptor::setColor(float _r, float _g, float _b, float _a) {
  r = _r;
  g = _g;
  b = _b;
  a = _a;
}

void Sculptor::putVoxel(int x, int y, int z) {
  v[x][y][z].r = r;
  v[x][y][z].g = g;
  v[x][y][z].b = b;
  v[x][y][z].a = a;
  v[x][y][z].show = true;
}

void Sculptor::cutVoxel(int x, int y, int z) { v[x][y][z].show = false; }

void Sculptor::writeOFF(const char *filename) {
  std::ofstream fout;

  fixed(fout);

  fout.open(filename);

  if (!fout.is_open()) {
    exit(1);
  }

  int voxel = 0;
  for (int i = 0; i < nx; i++) {
    for (int j = 0; j < ny; j++) {
      for (int k = 0; k < nz; k++) {
        if (v[i][j][k].show) {
          voxel++;
        }
      }
    }
  }

  int nvertices = voxel * 8, nfaces = voxel * 6;

  fout << "OFF\n";
  fout << nvertices << " " << nfaces << " " << 0 << std::endl;
  for (int i = 0; i < nx; i++) {
    for (int j = 0; j < ny; j++) {
      for (int k = 0; k < nz; k++) {
        if (v[i][j][k].show) {
          fout << i - 0.5 << " " << j + 0.5 << " " << k - 0.5 << "\n";
          fout << i - 0.5 << " " << j - 0.5 << " " << k - 0.5 << "\n";
          fout << i + 0.5 << " " << j - 0.5 << " " << k - 0.5 << "\n";
          fout << i + 0.5 << " " << j + 0.5 << " " << k - 0.5 << "\n";
          fout << i - 0.5 << " " << j + 0.5 << " " << k + 0.5 << "\n";
          fout << i - 0.5 << " " << j - 0.5 << " " << k + 0.5 << "\n";
          fout << i + 0.5 << " " << j - 0.5 << " " << k + 0.5 << "\n";
          fout << i + 0.5 << " " << j + 0.5 << " " << k + 0.5 << "\n";
        }
      }
    }
  }

  int cuboV = 0;
  for (int i = 0; i < nx; i++) {
    for (int j = 0; j < ny; j++) {
      for (int k = 0; k < nz; k++) {
        if (v[i][j][k].show) {
          fout << 4 << " " << 0 + cuboV << " " << 3 + cuboV << " " << 2 + cuboV
               << " " << 1 + cuboV << " " << v[i][j][k].r << " " << v[i][j][k].g
               << " " << v[i][j][k].b << " " << v[i][j][k].a << "\n";
          fout << 4 << " " << 4 + cuboV << " " << 5 + cuboV << " " << 6 + cuboV
               << " " << 7 + cuboV << " " << v[i][j][k].r << " " << v[i][j][k].g
               << " " << v[i][j][k].b << " " << v[i][j][k].a << "\n";
          fout << 4 << " " << 0 + cuboV << " " << 1 + cuboV << " " << 5 + cuboV
               << " " << 4 + cuboV << " " << v[i][j][k].r << " " << v[i][j][k].g
               << " " << v[i][j][k].b << " " << v[i][j][k].a << "\n";
          fout << 4 << " " << 0 + cuboV << " " << 4 + cuboV << " " << 7 + cuboV
               << " " << 3 + cuboV << " " << v[i][j][k].r << " " << v[i][j][k].g
               << " " << v[i][j][k].b << " " << v[i][j][k].a << "\n";
          fout << 4 << " " << 3 + cuboV << " " << 7 + cuboV << " " << 6 + cuboV
               << " " << 2 + cuboV << " " << v[i][j][k].r << " " << v[i][j][k].g
               << " " << v[i][j][k].b << " " << v[i][j][k].a << "\n";
          fout << 4 << " " << 1 + cuboV << " " << 2 + cuboV << " " << 6 + cuboV
               << " " << 5 + cuboV << " " << v[i][j][k].r << " " << v[i][j][k].g
               << " " << v[i][j][k].b << " " << v[i][j][k].a << "\n";

          cuboV += 8;
        }
      }
    }
  }

  fout.close();
}
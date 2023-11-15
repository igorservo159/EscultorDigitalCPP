#ifndef INTERPRETADOR_H
#define INTERPRETADOR_H
#include <vector>
#include "FiguraGeometrica.h"
#include <string>
using namespace std;

class Interpretador
{
    int dimx,dimy,dimz;
    float r,g,b,a;
public:
    Interpretador();
    ~Interpretador(){};

    /**
    * @brief Interpretador do input.txt.
    * @details Faz a checkagem de cada linha do input e cria uma imagem correspondente.
    * @param filename Nome do arquivo .txt.
    */
    vector<FiguraGeometrica*> interpretar(string filename);

    /**
    * @brief Método get da dimensão do espaço x.
    * @details Retorna o tamanho da dimensão x.
    */
    int getdimx();
    /**
    * @brief Método get da dimensão do espaço y.
    * @details Retorna o tamanho da dimensão y.
    */
    int getdimy();
    /**
    * @brief Método get da dimensão do espaço z.
    * @details Retorna o tamanho da dimensão z.
    */
    int getdimz();
};

#endif
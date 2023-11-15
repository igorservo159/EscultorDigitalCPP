#ifndef SCULPTOR_H
#define SCULPTOR_H
#include "Voxel.h"

class Sculptor {
private:
  Voxel ***v;
  int nx, ny, nz;   
  float r, g, b, a; 
public:
  /**
   * @brief Construtor da classe Sculptor.
   * @details Inicializa os atributos da classe, alocando um vetor com as
   * dimensões definidas pelas variáveis x, y e z.
   * @param _nx Dimensão X do Sculptor.
   * @param _ny Dimensão Y do Sculptor.
   * @param _nz Dimensão Z do Sculptor.
   */
  Sculptor(int _nx, int _ny, int _nz);
    /**
   * @brief Destrutor da classe Sculptor.
   * @details Libera a memória alocada para o vetor de voxels.
   */
  ~Sculptor();
    /**
   * @brief Estabelece uma cor para o próxim voxel (putVoxel).
   * @param r Valor de red.
   * @param g Valor de green.
   * @param b Valor de blue.
   * @param a Valor de alpha (transparência).
   */
  void setColor(float r, float g, float b, float a);
  /**
   * @brief Cria um voxel na coordenada (x, y, z).
   * @param x Coordenada X do voxel.
   * @param y Coordenada Y do voxel.
   * @param z Coordenada Z do voxel.
   */
  void putVoxel(int x, int y, int z);
  /**
   * @brief Retira um voxel na coordenada (x, y, z).
   * @param x Coordenada X do voxel.
   * @param y Coordenada Y do voxel.
   * @param z Coordenada Z do voxel.
   */
  void cutVoxel(int x, int y, int z);
  /**
   * @brief Escreve em um arquivo de formato .OFF a matriz de voxels com suas
   * respectivas cores.
   * @param filename Nome do arquivo que será escrito.
   */
  void writeOFF(const char* filename);
};

#endif
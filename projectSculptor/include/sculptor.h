#ifndef __SCULPTOR_H__
#define __SCULPTOR_H__

/**
 * @file  sculptor.h
 * @brief  Definição da classe Scultor e seus respectivos
 *      métodos para desenhar figuras geométricas.
 * @author  Thuize Thainá
 * @author  Felipe Lima
 * @since  15/04/2019
 * @date   29/04/2019
 */

#include <iostream>
#include <fstream>
#include <string>
using std::endl;
using std::ofstream;
using std::string;

/**
 * @struct Voxel
 * @brief Struct que representa um Voxel
 * @details Um Voxel é definido como um struct e comporta as propriedades necessárias para permitir armazenar três tipos
 * de informações: a cor do voxel, sua transparência e se ele deverá ser incluído ou não no modelo digital que representa a escultura.
 */
struct Voxel
{
  float red, green, blue;
  float transparency;
  bool isOn;
};

/**
 * @class   Sculptor sculptor.h
 * @brief   Classe que representa um escultor digital
 * @details  Os atributos do escultor são a matriz 3D de voxels, dimensões da matriz e cores. Os métodos definidos na classe
 * sculptor são utilizados para manipular os voxels da matriz, modificando cores, desenhando e apagando voxels, além da criação
 * de figuras geométricas como cubo, esfera e elipsóide, podendo ainda exportar os dados para arquivos VECT e OFF.
 */
class Sculptor
{
protected:
  Voxel ***v;
  int nx, ny, nz;
  float r, g, b, a;

public:
  Sculptor(int, int, int);
  ~Sculptor();
  void setColor(float, float, float, float);
  void putVoxel(int, int, int);
  void cutVoxel(int, int, int);
  void putBox(int, int, int, int, int, int);
  void cutBox(int, int, int, int, int, int);
  void putSphere(int, int, int, int);
  void cutSphere(int, int, int, int);
  void putEllipsoid(int, int, int, int, int, int);
  void cutEllipsoid(int, int, int, int, int, int);
  void writeOFF(string);
  void writeVECT(string);
};

#endif

/**
 * @file  sculptor.h
 * @brief  Definição da classe Scultor e seus respectivos
 *      métodos para desenhar figuras geométricas.
 * @author  Thuize Thainá
 * @author  Felipe Lima
 * @since  15/04/2019
 * @date   29/04/2019
 */

#ifndef SCULPTOR_H
#define SCULPTOR_H
#include<iostream>
#include<fstream>
#include <fstream>
#include<string>
using std::string;
using std::endl;

/**
 * @struct Voxel
 * @brief Struct que representa um Voxel
 * @details Um Voxel é definido como um struct e comporta as propriedades necessárias para permitir armazenar três tipos
 * de informações: a cor do voxel, sua transparência e se ele deverá ser incluído ou não no modelo digital que representa a escultura.
 */
struct Voxel {
  float red,green,blue; // Colors
  float transparency; // Transparency
  bool isOn; // Included or not
};

/**
 * @class   Sculptor sculptor.h
 * @brief   Classe que representa um escultor digital
 * @details  Os atributos do escultor são a matriz 3D de voxels, dimensões da matriz e cores. Os métodos definidos na classe
 * sculptor são utilizados para manipular os voxels da matriz, modificando cores, desenhando e apagando voxels, além da criação
 * de figuras geométricas como cubo, esfera e elipsóide, podendo ainda exportar os dados para arquivos VECT e OFF.
 */
class Sculptor{
protected:
    Voxel ***v; // 3D matrix
    int nx,ny,nz; // Dimensions
    float r,g,b,a; // Current drawing color
public:
    Sculptor(int _nx, int _ny, int _nz);
    ~Sculptor();
    void setColor(float _r, float _g, float _b, float _a);
    void putVoxel(int x, int y, int z);
    void cutVoxel(int x, int y, int z);
    void putBox(int x0, int x1, int y0, int y1, int z0, int z1);
    void cutBox(int x0, int x1, int y0, int y1, int z0, int z1);
    void putSphere(int xcenter, int ycenter, int zcenter, int radius);
    void cutSphere(int xcenter, int ycenter, int zcenter, int radius);
    void putEllipsoid(int xcenter, int ycenter, int zcenter, int rx, int ry, int rz);
    void cutEllipsoid(int xcenter, int ycenter, int zcenter, int rx, int ry, int rz);
    //void writeOFF(string filename);
    void writeVECT(string filename);

};

#endif // SCULPTOR_H

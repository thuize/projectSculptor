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

/**
 *	@file		sculptor.h
 *	@brief		Classe Sculptor
 *	@author		Thuize Thainá
 *  @author     Felipe Lima
 *	@date		18/05/2019
 *	@since		18/05/2019
 */

#include<iostream>
#include<fstream>
#include<string>
#include <cstdlib>
#include <sstream>
using std::string;
using std::endl;
using std::ofstream;
using std::ifstream;
/**
 * @struct Voxel
 * @brief Struct que representa um Voxel
 * @details Um Voxel é definido como um struct e comporta as propriedades necessárias para permitir armazenar três tipos
 * de informações: a cor do voxel, sua transparência e se ele deverá ser incluído ou não no modelo digital que representa a escultura.
 */
struct Voxel {
  float red,green,blue;
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
class Sculptor{
protected:
    Voxel ***v;
    int nx,ny,nz;
    float r,g,b,a;
public:
    Sculptor(int _nz, int _ny, int _nx);
    ~Sculptor();
    void setColor(float _r, float _g, float _b, float _a);
    void putVoxel(int x, int y, int z);
    void cutVoxel(int x, int y, int z);
    void writeOFF(string filename);
    void writeVECT(string filename);


};

#endif // SCULPTOR_H

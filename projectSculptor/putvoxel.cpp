/**
 * @file	putvoxel.cpp
 * @brief	Definição dos métods da classe putVoxel
 * @author	Thuize Thainá
 * @author  Felipe Lima
 * @since	15/04/2019
 * @date	01/05/2019
 */
#include "putvoxel.h"
/**
 * @brief putVoxel::putVoxel
 * @param _x
 * @param _y
 * @param _z
 * @param _r
 * @param _g
 * @param _b
 * @param _a
 * @details Método construtor de putVoxel que passa os valores obtidos dos parâmetros informados para os parâmetros da classe
 */
putVoxel::putVoxel(int _x, int _y, int _z,float _r, float _g, float _b, float _a){

    x = _x; y = _y; z = _z; r = _r; g = _g; b=_b; a = _a;

}

/**
 * @brief putVoxel::draw
 * @param s
 * @details Método draw que desenha um voxel na escultura 3D a partir das coordenadas e parâmetros de cor informadas
 */
void putVoxel::draw(Sculptor &s){
    s.setColor(r,g,b,a);
    s.putVoxel(x,y,z);

}

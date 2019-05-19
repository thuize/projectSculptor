/**
 * @file	cutvoxel.cpp
 * @brief	Definição dos métods da classe cutVoxel
 * @author	Thuize Thainá
 * @author  Felipe Lima
 * @since	15/04/2019
 * @date	01/05/2019
 */
#include "cutvoxel.h"
/**
 * @brief cutVoxel::cutVoxel
 * @param _x
 * @param _y
 * @param _z
 * @details Método construtor de cutVoxel que passa os valores obtidos dos parâmetros informados para os parâmetros da classe
 */
cutVoxel::cutVoxel(int _x, int _y, int _z){
    x = _x;y = _y;z = _z;
}
/**
 * @brief cutVoxel::draw
 * @param s
 * @details Método draw da classe cutVoxel que apaga um voxel na matriz 3D de acordo com a localização informada.
 */
void cutVoxel::draw(Sculptor &s){
    s.cutVoxel(x, y, z);
}

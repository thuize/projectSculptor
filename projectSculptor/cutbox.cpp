/**
 * @file	cutsphere.cpp
 * @brief	Definição dos métods da classe cutSphere
 * @author	Thuize Thainá
 * @author  Felipe Lima
 * @since	15/04/2019
 * @date	01/05/2019
 */
#include "cutbox.h"
/**
 * @brief cutBox::cutBox
 * @param _x0
 * @param _x1
 * @param _y0
 * @param _y1
 * @param _z0
 * @param _z1
 * @details Método construtor de cutBox que passa os valores obtidos dos parâmetros informados para os parâmetros da classe
 */
cutBox::cutBox(int _x0, int _x1, int _y0 , int _y1, int _z0, int _z1){
    x0 = _x0; x1 = _x1;
    y0 = _y0; y1 = _y1;
    z0 = _z0; z1 = _z1;


}
/**
 * @brief cutBox::draw
 * @param s
 *  * @details Método draw apaga um cubo de acordo com os valores de sua localização. Para isso,
 * os intervalos informados são percorridos para "excluir" os voxels na matriz 3D correspondente as dimensões do cubo.
 */
void cutBox::draw(Sculptor &s){
    for (int k=z0;k<z1;k++) {
        for (int i=y0; i<y1 ; i++){
            for (int j=x0; j<x1; j++) {
                s.cutVoxel(k,i,j);
            }
        }
    }
}

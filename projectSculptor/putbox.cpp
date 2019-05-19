/**
 * @file	putbox.cpp
 * @brief	Definição dos métodos da classe putBox
 * @author	Thuize Thainá
 * @author  Felipe Lima
 * @since	15/04/2019
 * @date	01/05/2019
 */
#include "putBox.h"
/**
 * @brief putBox::putBox
 * @param _x0
 * @param _x1
 * @param _y0
 * @param _y1
 * @param _z0
 * @param _z1
 * @param _r
 * @param _g
 * @param _b
 * @param _a
 * @details Construtor da classe putBox que passa os valores obtidos por parâmetro para os parâmetros da classe putBox
 */
putBox::putBox(int _x0, int _x1, int _y0 , int _y1, int _z0, int _z1,float _r, float _g, float _b, float _a){

    x0 = _x0;y0 = _y0;z0 = _z0; x1 = _x1;y1 = _y1;z1 = _z1; r = _r;g = _g;b = _b;a = _a;
}
/**
 * @brief putBox::draw
 * @param s
 * @details Método draw desenha um cubo de acordo com os valores de sua localização e cor. Para isso,
 * os intervalos informados são percorridos para desenhar os voxels na matriz 3D correspondente as dimensões do cubo.
 */
void putBox::draw(Sculptor &s){

    for (int k=z0;k<z1;k++) {
        for (int i=y0; i<y1 ; i++){
            for (int j=x0; j<x1; j++) {
                s.setColor(r,g,b,a);
                s.putVoxel(j,i,k);
            }
        }
    }
}


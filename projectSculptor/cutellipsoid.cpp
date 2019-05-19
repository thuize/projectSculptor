/**
 * @file	cutsphere.cpp
 * @brief	Definição dos métods da classe cutSphere
 * @author	Thuize Thainá
 * @author  Felipe Lima
 * @since	15/04/2019
 * @date	01/05/2019
 */
#include "cutellipsoid.h"
/**
 * @brief cutEllipsoid::cutEllipsoid
 * @param _xcenter
 * @param _ycenter
 * @param _zcenter
 * @param _rx
 * @param _ry
 * @param _rz
 * @details Método construtor de cutEllipsoid que passa os valores obtidos dos parâmetros informados para os parâmetros da classe
 */
cutEllipsoid::cutEllipsoid(int _xcenter, int _ycenter, int _zcenter, int _rx, int _ry, int _rz){
    xcenter = _xcenter;
    ycenter = _ycenter;
    zcenter = _zcenter;
    rx = _rx;
    ry = _ry;
    rz = _rz;
}
/**
 * @brief cutEllipsoid::draw
 * @param s
 * @details Método draw apaga uma elipsoide de acordo com os valores de sua localização. Para isso,
 * é verificado se as coordenadas informadas estão dentro do raio da elipsoide para assim "excluir" os voxels dentro do espaço
 * correspondente as suas dimensões na matriz 3D.
 */
void cutEllipsoid::draw(Sculptor &s){
    float n;

    for (int k=(zcenter-rz); k<=(zcenter+rz); k++){
        for (int i=(ycenter-ry); i<=(ycenter+ry); i++) {
            for (int j=(xcenter-rx); j<=(xcenter+rx); j++) {

                n=((((i-ycenter)/(float)ry)*((i-ycenter)/(float)ry))+
                   (((j-xcenter)/(float)rx)*((j-xcenter)/(float)rx))+
                   (((k-zcenter)/(float)rz)*((k-zcenter)/(float)rz)));

                if (n<=1){
                    s.cutVoxel(k,i,j);
                }
            }
        }
    }
}

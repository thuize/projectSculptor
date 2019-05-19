/**
 * @file	cutsphere.cpp
 * @brief	Definição dos métods da classe cutSphere
 * @author	Thuize Thainá
 * @author  Felipe Lima
 * @since	15/04/2019
 * @date	01/05/2019
 */
#include "cutsphere.h"
/**
 * @brief cutSphere::cutSphere
 * @param _xcenter
 * @param _ycenter
 * @param _zcenter
 * @param _radius
 * @details Método construtor de cutSphere que passa os valores obtidos dos parâmetros informados para os parâmetros da classe
 */
cutSphere::cutSphere(int _xcenter, int _ycenter, int _zcenter, int _radius){
    xcenter = _xcenter;
    ycenter = _ycenter;
    zcenter = _zcenter;
    radius = _radius;
}
/**
 * @brief cutSphere::draw
 * @param s
 * @details Método draw apaga partes de uma esfera de acordo com os valores de sua localização. Para isso,
 * é verificado se as coordenadas informadas estão dentro do raio da esfera para assim "excluir" os voxels dentro do espaço
 * correspondente as suas dimensões na matriz 3D.
 */
void cutSphere::draw(Sculptor &s){
    float esfera;

    for (int k=(zcenter-radius); k<=(zcenter+radius); k++){
        for (int i=(ycenter-radius); i<=(ycenter+radius); i++) {
            for (int j=(xcenter-radius); j<=(xcenter+radius); j++) {
                esfera= (((i-ycenter)*(i-ycenter)) + ((j-xcenter)*(j-xcenter)) + ((k-zcenter)*(k-zcenter)));

                if (esfera<= (radius*radius)){
                    s.cutVoxel(k,i,j);
                }
            }
        }
    }
}

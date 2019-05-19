/**
 * @file	putsphere.cpp
 * @brief	Definição dos métodos da classe putSphere
 * @author	Thuize Thainá
 * @author  Felipe Lima
 * @since	15/04/2019
 * @date	01/05/2019
 */
#include "putsphere.h"
/**
 * @brief putSphere::putSphere
 * @param _xcenter
 * @param _ycenter
 * @param _zcenter
 * @param _radius
 * @param _r
 * @param _g
 * @param _b
 * @param _a
 * @details Construtor da classe putSphere que passa os valores obtidos por parâmetro para os parâmetros da classe putSphere
 */
putSphere::putSphere(int _xcenter, int _ycenter, int _zcenter, int _radius,float _r, float _g, float _b, float _a){

    xcenter = _xcenter;  ycenter = _ycenter;  zcenter = _zcenter; radius = _radius;
    r = _r;   b = _b;  g = _g;  a = _a;

}
/**
 * @brief putSphere::draw
 * @param s
 * @details Método draw desenha uma esfera de acordo com os valores de sua localização e cor. Para isso,
 * é verificado se as coordenadas informadas estão dentro do raio da esfera para assim "pintar" os voxels dentro do espaço
 * correspondente as suas dimensões na matriz 3D.
 */
void putSphere::draw(Sculptor &s){
    float esfera;

    for (int k=(zcenter-radius); k<=(zcenter+radius); k++){
        for (int i=(ycenter-radius); i<=(ycenter+radius); i++) {
            for (int j=(xcenter-radius); j<=(xcenter+radius); j++) {
                esfera= (((i-ycenter)*(i-ycenter)) + ((j-xcenter)*(j-xcenter)) + ((k-zcenter)*(k-zcenter)));
                if (esfera<= (radius*radius)){  

                    s.putVoxel(k,i,j);
                    s.setColor(r,g,b,a);
                }
            }
        }
    }
}

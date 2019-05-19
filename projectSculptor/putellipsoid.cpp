/**
 * @file	putellipsoid.cpp
 * @brief	Definição dos métodos da classe putEllipsoid
 * @author	Thuize Thainá
 * @author  Felipe Lima
 * @since	15/04/2019
 * @date	01/05/2019
 */
#include "putellipsoid.h"
/**
 * @brief putEllipsoid::putEllipsoid
 * @param _xcenter
 * @param _ycenter
 * @param _zcenter
 * @param _rx
 * @param _ry
 * @param _rz
 * @param _r
 * @param _g
 * @param _b
 * @param _a
 * @details Construtor da classe putEllipsoid que passa os valores obtidos por parâmetro para os parâmetros da classe putEllipsoid
 */
putEllipsoid::putEllipsoid(int _xcenter, int _ycenter, int _zcenter, int _rx, int _ry, int _rz, float _r, float _g, float _b, float _a){

    xcenter = _xcenter; ycenter = _ycenter;zcenter = _zcenter;
    rx = _rx; ry = _ry; rz = _rz;
    r = _r;b = _b; g = _g; a = _a;

}
/**
 * @brief putEllipsoid::draw
 * @param s
 * @details Método draw desenha uma elipsoide de acordo com os valores de sua localização e cor. Para isso,
 * é verificado se as coordenadas informadas estão dentro do raio da elipsoide para assim "pintar" os voxels dentro do espaço
 * correspondente as suas dimensões na matriz 3D.
 */
void putEllipsoid::draw(Sculptor &s){
    float n;

    for (int k=(zcenter-rz); k<=(zcenter+rz); k++){
        for (int i=(ycenter-ry); i<=(ycenter+ry); i++) {
            for (int j=(xcenter-rx); j<=(xcenter+rx); j++) {

                n=((((i-ycenter)/(float)ry)*((i-ycenter)/(float)ry))+
                   (((j-xcenter)/(float)rx)*((j-xcenter)/(float)rx))+
                   (((k-zcenter)/(float)rz)*((k-zcenter)/(float)rz)));

                if (n<=1){
                    s.putVoxel(k,i,j);
                    s.setColor(r,g,b,a);
                }
            }
        }
    }
}

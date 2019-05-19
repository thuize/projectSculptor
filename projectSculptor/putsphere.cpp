#include "putsphere.h"

putSphere::putSphere(int _xcenter, int _ycenter, int _zcenter, int _radius,float _r, float _g, float _b, float _a){

    xcenter = _xcenter;  ycenter = _ycenter;  zcenter = _zcenter; radius = _radius;
    r = _r;   b = _b;  g = _g;  a = _a;

}

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

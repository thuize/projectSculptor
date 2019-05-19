#include "cutsphere.h"

cutSphere::cutSphere(int _xcenter, int _ycenter, int _zcenter, int _radius){
    xcenter = _xcenter;
    ycenter = _ycenter;
    zcenter = _zcenter;
    radius = _radius;
}

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

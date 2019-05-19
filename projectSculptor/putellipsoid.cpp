#include "putellipsoid.h"

putEllipsoid::putEllipsoid(int _xcenter, int _ycenter, int _zcenter, int _rx, int _ry, int _rz,
                           float _r, float _g, float _b, float _a){
    xcenter = _xcenter;
    ycenter = _ycenter;
    zcenter = _zcenter;
    rx = _rx;
    ry = _ry;
    rz = _rz;
    r = _r;
    b = _b;
    g = _g;
    a = _a;
}

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

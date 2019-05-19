#include "putBox.h"

putBox::putBox(int _x0, int _x1, int _y0 , int _y1, int _z0, int _z1, float _r, float _g, float _b, float _a){
    x0 = _x0;y0 = _y0;z0 = _z0; x1 = _x1;y1 = _y1;z1 = _z1;
    r = _r;b = _b;g = _g;a = _a;
}

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


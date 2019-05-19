#include "cutbox.h"

cutBox::cutBox(int _x0, int _x1, int _y0 , int _y1, int _z0, int _z1){
    x0 = _x0; x1 = _x1;
    y0 = _y0; y1 = _y1;
    z0 = _z0; z1 = _z1;


}

void cutBox::draw(Sculptor &s){
    for (int k=z0;k<z1;k++) {
        for (int i=y0; i<y1 ; i++){
            for (int j=x0; j<x1; j++) {
                s.cutVoxel(k,i,j);
            }
        }
    }
}

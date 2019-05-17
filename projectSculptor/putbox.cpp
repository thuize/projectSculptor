#include "putbox.h"

putBox::putBox(int x0, int x1, int y0 , int y1, int z0, int z1, float _r, float _g, float _b, float _a){

    bx0=x0; by0=y0; bz0=z0;
    bx1=x1; by1=y1; bz1=z1;
    br=_r; bg=_g; bb=_b; ba=_a;

}
void putBox::draw(Sculptor &s){

    for (int k=bz0;k<bz1;k++) {
        for (int i=by0; i<by1 ; i++){
            for (int j=bx0; j<bx1; j++) {
                s.setColor(br,bg,bb,ba);
                s.putVoxel(k,i,j);

            }
        }
    }

}

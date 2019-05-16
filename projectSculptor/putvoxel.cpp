#include "putvoxel.h"

putVoxel::putVoxel(int mx, int my, int mz,
                   float _r, float _g, float _b, float _a){
    x=mx; y=my; z=mz;
    r=_r; g=_g; b=_b; a=_a;
}

void putVoxel::draw(Sculptor &s){
    s.putVoxel(x,y,z);
    s.setColor(r,g,b,a);
}

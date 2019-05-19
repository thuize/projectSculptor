#include "putvoxel.h"

putVoxel::putVoxel(int _x, int _y, int _z,
                   float _r, float _g, float _b, float _a){
    x = _x;
    y = _y;
    z = _z;
    r = _r;
    g = _g;
    a = _a;
}

void putVoxel::draw(Sculptor &s){
    s.putVoxel(x,y,z);
    s.setColor(r,g,b,a);
}

#include "cutvoxel.h"


cutVoxel::cutVoxel(int _x, int _y, int _z){
    x = _x;
    y = _y;
    z = _z;
}

void cutVoxel::draw(Sculptor &s){
    s.cutVoxel(x, y, z);
}

#include "cutvoxel.h"


cutVoxel::cutVoxel(int mx, int my, int mz){
    x=mx; y=my; z=mz;
}

void cutVoxel::draw(Sculptor &s){
    s.cutVoxel(x, y, z);
}

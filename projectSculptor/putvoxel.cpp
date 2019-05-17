#include "putvoxel.h"

putVoxel::putVoxel(int mx, int my, int mz,
                   float _r, float _g, float _b, float _a){
    nx=mx; ny=my; nz=mz;
    nr=_r; ng=_g; nb=_b; na=_a;
}

void putVoxel::draw(Sculptor &s){
    s.putVoxel(nx,ny,nz);
    s.setColor(nr,ng,nb,na);
}

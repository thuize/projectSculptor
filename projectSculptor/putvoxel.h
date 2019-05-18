#ifndef PUTVOXEL_H
#define PUTVOXEL_H
#include "sculptor.h"
#include "figurageometrica.h"


class putVoxel : public FiguraGeometrica
{
    int nx, ny, nz;
    float nr,ng,nb,na;
public:
    putVoxel(int mx, int my, int mz, float r, float g, float b, float a);
    void draw(Sculptor &s);
};

#endif // PUTVOXEL_H

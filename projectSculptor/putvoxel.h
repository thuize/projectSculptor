#ifndef PUTVOXEL_H
#define PUTVOXEL_H
#include "sculptor.h"


class putVoxel : public FiguraGeometrica
{
    int x, y, z;
    float r,g,b,a;
public:
    putVoxel(int mx, int my, int mz, float r, float g, float b, float a);
    void draw(Sculptor &s);
};

#endif // PUTVOXEL_H

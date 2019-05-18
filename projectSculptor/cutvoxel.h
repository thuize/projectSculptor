#ifndef CUTVOXEL_H
#define CUTVOXEL_H
#include "sculptor.h"
#include "figurageometrica.h"

class cutVoxel : public FiguraGeometrica
{
    int x, y, z;
public:
    cutVoxel(int mx, int my, int mz);
    void draw(Sculptor &s);
};

#endif // CUTVOXEL_H

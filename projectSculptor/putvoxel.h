#ifndef PUTVOXEL_H
#define PUTVOXEL_H
#include "figurageometrica.h"


class putVoxel : public FiguraGeometrica
{
    int x, y, z;
    float r,g,b,a;
public:
    putVoxel(int _x, int _y, int _z, float _r, float _g, float _b, float _a);
    void draw(Sculptor &s);
};

#endif // PUTVOXEL_H

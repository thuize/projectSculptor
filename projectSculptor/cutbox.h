#ifndef CUTBOX_H
#define CUTBOX_H
#include "figurageometrica.h"

class cutBox : public FiguraGeometrica
{
    int x0,y0,z0;
    int x1,y1,z1;
public:
    cutBox(int _x0, int _x1, int _y0 , int _y1, int _z0, int _z1);
    void draw(Sculptor &s);
};

#endif // CUTBOX_H

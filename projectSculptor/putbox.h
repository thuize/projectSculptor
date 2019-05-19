#ifndef PUTBOX_H
#define PUTBOX_H
#include "figurageometrica.h"
#include "sculptor.h"

class putBox : public FiguraGeometrica
{
    int x0,y0,z0;
    int x1,y1,z1;
    float r,g,b,a;
public:
    putBox(int _x0, int _x1, int _y0 , int _y1, int _z0, int _z1, float _r, float _g, float _b, float _a);
    void draw(Sculptor &s);
};

#endif // PUTBOX_H

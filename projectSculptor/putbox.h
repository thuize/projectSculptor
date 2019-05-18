#ifndef PUTBOX_H
#define PUTBOX_H
#include "figurageometrica.h"
#include "sculptor.h"

class putBox : public FiguraGeometrica
{
    int bx0,by0,bz0;
    int bx1,by1,bz1;
    float br,bg,bb,ba;
public:
    putBox(int x0, int x1, int y0 , int y1, int z0, int z1, float _r, float _g, float _b, float _a);
    void draw(Sculptor &s);

};

#endif // PUTBOX_H

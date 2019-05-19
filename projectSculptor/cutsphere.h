#ifndef CUTSPHERE_H
#define CUTSPHERE_H
#include "figurageometrica.h"

class cutSphere : public FiguraGeometrica
{
    int xcenter, ycenter, zcenter, radius;
public:
    cutSphere(int _xcenter, int _ycenter, int _zcenter, int _radius);
    void draw(Sculptor &s);
};

#endif // CUTSPHERE_H

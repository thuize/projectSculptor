#ifndef CUTBOX_H
#define CUTBOX_H
#include "sculptor.h"
#include "figurageometrica.h"

class cutBox : public FiguraGeometrica
{
public:
    cutBox();
    void draw(Sculptor &s);

};

#endif // CUTBOX_H

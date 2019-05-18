#include "cutbox.h"

cutBox::cutBox(int x0, int y0, int z0, int x1, int y1, int z1)
    : x0(x0),
      y0(x1),
      z0(y0),
      x1(x1),
      y1(y1),
      z1(z1)
{
}

void cutBox::draw(Sculptor &s)
{

    for (int k = z0; k < z1; k++)
    {
        for (int i = y0; i < y1; i++)
        {
            for (int j = x0; j < x1; j++)
            {
                s.cutVoxel(k, i, j);
            }
        }
    }
}

#include "putbox.h"

putBox::putBox(int x0, int x1,
               int y0, int y1,
               int z0, int z1,
               float r, float g, float b, float a)
    : x0(x0),
      y0(y0),
      z0(z0),
      x1(x1),
      y1(y1),
      z1(z1),
      r(r),
      g(g),
      b(b),
      a(a)
{
}

void putBox::draw(Sculptor &box)
{
    for (int k = z0; k < z1; k++)
    {
        for (int i = y0; i < y1; i++)
        {
            for (int j = x0; j < x1; j++)
            {
                box.setColor(r, g, b, a);
                box.putVoxel(k, i, j);
            }
        }
    }
}

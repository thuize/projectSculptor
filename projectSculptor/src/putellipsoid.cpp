#include "putellipsoid.h"

putEllipsoid::putEllipsoid(int xcenter, int ycenter, int zcenter, int radius,
                           int x, int y, int z,
                           float r, float g, float b, float a)
    : xcenter(xcenter),
      ycenter(ycenter),
      zcenter(zcenter),
      radius(radius),
      x(x),
      y(y),
      z(z),
      r(r),
      g(g),
      b(b),
      a(a)
{
}

void putEllipsoid::draw(Sculptor &s)
{
  s.setColor(r, g, b, a);
  float n;

  for (int k = (zcenter - z); k <= (zcenter + z); k++)
  {
    for (int i = (ycenter - y); i <= (ycenter + y); i++)
    {
      for (int j = (xcenter - x); j <= (xcenter + x); j++)
      {

        n = ((((i - ycenter) / (float)y) * ((i - ycenter) / (float)y)) +
             (((j - xcenter) / (float)x) * ((j - xcenter) / (float)x)) +
             (((k - zcenter) / (float)z) * ((k - zcenter) / (float)z)));

        if (n <= 1)
        {
          s.putVoxel(k, i, j);
        }
      }
    }
  }
}
#include "putsphere.h"

putSphere::putSphere(int xcenter, int ycenter, int zcenter, int radius,
                     float r, float g, float b, float a)
    : xcenter(xcenter),
      ycenter(ycenter),
      zcenter(zcenter),
      radius(radius),
      r(r),
      g(g),
      b(b),
      a(a)
{
}

void putSphere::draw(Sculptor &sphere)
{

  float esfera;

  for (int k = (zcenter - radius); k <= (zcenter + radius); k++)
  {
    for (int i = (ycenter - radius); i <= (ycenter + radius); i++)
    {
      for (int j = (xcenter - radius); j <= (xcenter + radius); j++)
      {
        esfera = (((i - ycenter) * (i - ycenter)) + ((j - xcenter) * (j - xcenter)) + ((k - zcenter) * (k - zcenter)));

        if (esfera <= (radius * radius))
        {
          sphere.setColor(r, g, b, a);
          sphere.putVoxel(k, i, j);
        }
      }
    }
  }
}
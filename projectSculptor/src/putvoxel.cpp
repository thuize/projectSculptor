#include "putvoxel.h"

putVoxel::putVoxel(int x, int y, int z,
                   float r, float g, float b, float a)
    : x(x),
      y(y),
      z(z),
      r(r),
      g(g),
      b(b),
      a(a)
{
}

void putVoxel::draw(Sculptor &voxel)
{
  voxel.putVoxel(x, y, z);
  voxel.setColor(r, g, b, a);
}

#include "cutvoxel.h"

cutVoxel::cutVoxel(int x, int y, int z)
    : x(x),
      y(y),
      z(z)
{
}

void cutVoxel::draw(Sculptor &s)
{
    s.cutVoxel(x, y, z);
}

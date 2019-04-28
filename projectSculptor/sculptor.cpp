#include "sculptor.h"

Sculptor::Sculptor(int _nx, int _ny, int _nz){
    nx = _nx; ny = _ny; nz = _nz;

    if(nx <= 0 || ny <= 0 || nz <= 0){
        nx = ny = nz = 0;
    }
}

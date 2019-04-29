#include "sculptor.h"
#include <cstdlib>

Sculptor::Sculptor(int _nx, int _ny, int _nz){
    nx = _nx; ny = _ny; nz = _nz;

    if(nx <= 0 || ny <= 0 || nz <= 0){
        nx = ny = nz = 0;
    }

     //Solicita o bloco de memoria
     v = new Voxel**[nx];
     if(v == nullptr){
         exit(0);
     }

     v[0] = new Voxel*[nx*ny];
     if(v[0] == nullptr){
         exit(0);
     }

     v[0][0] = new Voxel[nx*ny*nz];
     if(v[0][0] == nullptr){
         exit(0);
     }

     //Ajusta os enderecos das linhas da matriz
     for(int i=1; i<nx; ++i){
         v[i] = v[i-1] + ny;
     }

     for(int i=0; i<nx*ny; i++){
         v[0][i] = 0;
     }
}

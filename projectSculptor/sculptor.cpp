#include "sculptor.h"
#include <iostream>
#include <cstring>

Sculptor::Sculptor(int _nx, int _ny, int _nz)
{
    if(_nx>0 && _ny>0 && _nz>0){
        nx=_nx; ny=_ny; nz=_nz;

        v = new Voxel ** [_nx];                      // Alocação da matriz

        v[0] = new Voxel * [_nx*_ny];

        v[0][0] = new Voxel [_nx*_ny*_nz];

        int i,j,k;

        for( i = 0; i < _nx; i++) {

            if (i < _nx -1 ) {

                v[0][(i+1)*_ny] = &(v[0][0][(i+1)*_nz*_ny]);

                v[i+1] = &(v[0][(i+1)*_ny]);

            }

            for( j = 0; j < _ny; j++) {
                if (j > 0) v[i][j] = v[i][j-1] + _nz;
            }

        }

        for (int k=0;k<nx;k++) {                    // Inicializa a matriz
            for(int i=0; i< ny; i++){
                for(int j=0; j<nz;j++){
                    v[k][i][j].isOn=false;
                    v[k][i][j].red   = 0;
                    v[k][i][j].green = 0;
                    v[k][i][j].blue  = 0;
                    v[k][i][j].transparency = 0;
                }
            }
        }
    }
    else{
        std::cout<<"Tamanho Invalido. " << std::endl;
    }
}

Sculptor::~Sculptor(){
    delete[] v[0][0];
    delete[] v[0];
    delete[] v;

}


void Sculptor::setColor(float _r, float _g, float _b, float _a)
{
    if (_r>0 && _r<1){r=_r;}
    else{r=0;};

    if (_g>0 && _g<1){g=_g;}
    else{g=0;};

    if (_b>0 && _b<1){b=_b;}
    else{b=0;};

    if (_a>0 && _a<1){a=_a;}
    else{a=0;};

}

void Sculptor::putVoxel(int x, int y, int z)
{
    v[x][y][z].isOn  = true;
    v[x][y][z].red   = r;
    v[x][y][z].green = g;
    v[x][y][z].blue  = b;
    v[x][y][z].transparency = a;
}

void Sculptor::cutVoxel(int x, int y, int z)
{
    v[x][y][z].isOn  = false;

}

void Sculptor::putBox(int x0, int x1, int y0, int y1, int z0, int z1)
{

}

void Sculptor::cutBox(int x0, int x1, int y0, int y1, int z0, int z1)
{

}

void Sculptor::putSphere(int xcenter, int ycenter, int zcenter, int radius)
{

}

void Sculptor::cutSphere(int xcenter, int ycenter, int zcenter, int radius)
{

}

void Sculptor::putEllipsoid(int xcenter, int ycenter, int zcenter, int rx, int ry, int rz)
{

}

void Sculptor::cutEllipsoid(int xcenter, int ycenter, int zcenter, int rx, int ry, int rz)
{

}




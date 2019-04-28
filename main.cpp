#include <iostream>
#include "sculptor.h"

using namespace std;

template <class T> T ***Create3D(int N1, int N2, int N3)
{
    T *** array = new T ** [N1];

    array[0] = new T * [N1*N2];

    array[0][0] = new T [N1*N2*N3];

    int i,j,k;

    for( i = 0; i < N1; i++) {

        if (i < N1 -1 ) {

            array[0][(i+1)*N2] = &(array[0][0][(i+1)*N3*N2]);

            array[i+1] = &(array[0][(i+1)*N2]);

        }

        for( j = 0; j < N2; j++) {
            if (j > 0) array[i][j] = array[i][j-1] + N3;
        }

    }

    std::cout << std::endl;
    return array;
};

template <class T> void Delete3D(T ***array) {
    delete[] array[0][0];
    delete[] array[0];
    delete[] array;
};


int main()
{
    int linhas=3,colunas=4,profundidade=5;
    Voxel ***matriz3d = Create3D<Voxel>(profundidade,linhas,colunas);

    Delete3D(matriz3d);

}

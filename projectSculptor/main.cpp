#include <iostream>
#include "sculptor.h"
using namespace std;

int main()
{
    int camadas=11,linhas=21,colunas=21;
    Sculptor a(linhas,colunas,camadas);
    a.setColor(1,0,0,0);
    a.putEllipsoid(11,11,5,5,5,5);

    return 0;
}

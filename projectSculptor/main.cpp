#include <iostream>
#include "sculptor.h"
using namespace std;

int main()
{
    int camadas=11,linhas=21,colunas=41;
    Sculptor a(camadas, linhas, colunas);
    a.setColor(1,0,0,0);
    a.putEllipsoid(10,21,5,10,20,5);
    //a.cutEllipsoid(10,21,5,10,20,5);
    // a.cutEllipsoid(10,10,5,5,5,5);
  //  a.putBox(5,15,5,10,3,6);
    // a.cutBox(5,10,5,10,3,6);
    // a.putSphere(15,15,10,5);

    return 0;
}

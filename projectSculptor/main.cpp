/**
 * @file	main.cpp
 * @brief	Demonstração da implementação do escultor digital
 * @author	Thuize Thainá
 * @author  Felipe Lima
 * @since	15/04/2019
 * @date	01/05/2019
 */

#include <iostream>
#include "sculptor.h"
using namespace std;

int main()
{
    int kk=15,xx=21,yy=41;
    Sculptor a(kk, xx, yy);
    a.setColor(1,1,0,0.5);
    //a.putEllipsoid(5,25,5,3,7,5);
    //a.cutEllipsoid(5,21,5,3,3,5);
    //a.putEllipsoid(11,3,3,10,3,3);
    //a.putSphere(16,35,6,3);
    //a.cutSphere(5,30,6,3);
    //a.cutEllipsoid(10,21,5,10,20,5);
    a.putBox(3,19,5,10,6,11);
    a.putSphere(15,25,7,5);
    a.putBox(13,18,5,25,6,11);
    a.cutBox(14,17,5,35,7,10);
    a.putEllipsoid(15,3,7,5,2,3);
    //a.putSphere(15,15,10,5);
    //a.writeVECT("teste.vect");
    a.writeOFF("t4.off");

    return 0;
}

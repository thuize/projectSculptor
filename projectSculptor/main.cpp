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
    a.putBox(3,5,3,5,3,5);

    return 0;
}

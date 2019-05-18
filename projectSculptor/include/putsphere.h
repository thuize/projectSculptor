#ifndef __PUTSPHERE_H__
#define __PUTSPHERE_H__

/**
 *	@file		putSphere.h
 *	@brief		Classe putSphere
 *	@author		Thuize Thainá
 *	@date		18/05/2019
 *	@since		18/05/2019
 */

//! Includes

#include "figurageometrica.h"
#include "sculptor.h"

/*!
 *	@class		putSphere putsphere.h
 *	@brief		Class putVoxel
 *	@details	
 */
class putSphere : public figuraGeometrica
{
    int xcenter, ycenter, zcenter, radius;
    int x, y, z;
    float r, g, b, a;

public:
    putSphere(int, int, int, int, float, float, float, float);
    void draw(Sculptor &);
};

#endif

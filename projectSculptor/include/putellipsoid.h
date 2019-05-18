#ifndef __PUTELLIPSOID_H__
#define __PUTELLIPSOID_H__

/**
 *	@file		putEllipsoid.h
 *	@brief		Classe putEllipsoid
 *	@author		Thuize Thainá
 *	@date		18/05/2019
 *	@since		18/05/2019
 */

//! Includes

#include "figurageometrica.h"
#include "sculptor.h"

/*!
 *	@class		putEllipsoid putellipsoid.h
 *	@brief		Class putEllipsoid
 *	@details	
 */
class putEllipsoid : public figuraGeometrica
{
private:
    int xcenter, ycenter, zcenter, radius;
    int x, y, z;
    float r, g, b, a;

public:
    putEllipsoid(int, int, int, int, int, int, int, float, float, float, float);
    void draw(Sculptor &);
};

#endif

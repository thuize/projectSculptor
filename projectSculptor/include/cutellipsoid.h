#ifndef __CUTELLIPSOID_H__
#define __CUTELLIPSOID_H__

/**
 *	@file		cutEllipsoid.h
 *	@brief		Classe cutEllipsoid
 *	@author		Thuize Thainá
 *	@date		18/05/2019
 *	@since		18/05/2019
 */

//! Includes

#include "sculptor.h"
#include "figurageometrica.h"

/*!
 *	@class		cutEllipsoid cutellipsoid.h
 *	@brief		Class cutEllipsoid
 *	@details	
 */
class cutEllipsoid : public figuraGeometrica
{
private:
    int xcenter, ycenter, zcenter, radius;
    int x, y, z;

public:
    cutEllipsoid(int, int, int, int, int, int, int);
    void draw(Sculptor &);
};

#endif

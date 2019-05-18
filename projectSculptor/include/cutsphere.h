#ifndef __CUTSPHERE_H__
#define __CUTSPHERE_H__

/**
 *	@file		cutSphere.h
 *	@brief		Classe cutSphere
 *	@author		Thuize Thainá
 *	@date		18/05/2019
 *	@since		18/05/2019
 */

//! Includes

#include "sculptor.h"
#include "figurageometrica.h"

/*!
 *	@class		cutSphere cutsphere.h
 *	@brief		Class cutSphere
 *	@details	
 */
class cutSphere : public figuraGeometrica
{
private:
    int xcenter, ycenter, zcenter, radius;

public:
    cutSphere(int, int, int, int);
    void draw(Sculptor &);
};

#endif

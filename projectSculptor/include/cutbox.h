#ifndef __CUTBOX_H__
#define __CUTBOX_H__

/**
 *	@file		cutbox.h
 *	@brief		Classe cutBox
 *	@author		Thuize Thainá
 *	@date		18/05/2019
 *	@since		18/05/2019
 */

//! Includes

#include "sculptor.h"
#include "figurageometrica.h"

/*!
 *	@class		cutBox cutbox.h
 *	@brief		Class cutBox
 *	@details	
 */
class cutBox : public figuraGeometrica
{
private:
    int x0, y0, z0;
    int x1, y1, z1;

public:
    cutBox(int, int, int, int, int, int);
    void draw(Sculptor &);
};

#endif

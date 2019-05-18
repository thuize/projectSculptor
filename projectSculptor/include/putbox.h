#ifndef __PUTBOX_H__
#define __PUTBOX_H__

/**
 *	@file		putBox.h
 *	@brief		Classe putBox
 *	@author		Thuize Thainá
 *	@date		18/05/2019
 *	@since		18/05/2019
 */

//! Includes

#include "figurageometrica.h"
#include "sculptor.h"

/*!
 *	@class		putBox putbox.h
 *	@brief		Class putBox
 *	@details	
 */
class putBox : public figuraGeometrica
{
    int x0, y0, z0;
    int x1, y1, z1;
    float r, g, b, a;

public:
    putBox(int, int, int, int, int, int, float, float, float, float);
    void draw(Sculptor &);
};

#endif

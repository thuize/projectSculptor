#ifndef __PUTVOXEL_H__
#define __PUTVOXEL_H__

/**
 *	@file		putBox.h
 *	@brief		Classe putBox
 *	@author		Thuize Thainá
 *	@date		18/05/2019
 *	@since		18/05/2019
 */

//! Includes

#include "sculptor.h"
#include "figurageometrica.h"

/*!
 *	@class		putVoxel putvoxel.h
 *	@brief		Class putVoxel
 *	@details	
 */
class putVoxel : public figuraGeometrica
{
    int x, y, z;
    float r, g, b, a;

public:
    putVoxel(int, int, int, float, float, float, float);
    void draw(Sculptor &);
};

#endif

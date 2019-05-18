#ifndef __CUTVOXEL_H__
#define __CUTVOXEL_H__

/**
 *	@file		cutvoxel.h
 *	@brief		Classe cutVoxel
 *	@author		Thuize Thainá
 *	@date		18/05/2019
 *	@since		18/05/2019
 */

//! Includes
#include "sculptor.h"
#include "figurageometrica.h"

/*!
 *	@class		cutVoxel cutvoxel.h
 *	@brief		Class cutVoxel
 *	@details	
 */
class cutVoxel : public figuraGeometrica
{
    int x, y, z;

public:
    cutVoxel(int mx, int my, int mz);
    void draw(Sculptor &s);
};

#endif

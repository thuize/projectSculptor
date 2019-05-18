#ifndef __FIGURAGEOMETRICA_H__
#define __FIGURAGEOMETRICA_H__

/**
 *	@file		figuraGeometrica.h
 *	@brief		Classe figuraGeometrica
 *	@author		Thuize Thainá
 *	@date		18/05/2019
 *	@since		18/05/2019
 */

//! Includes

#include "sculptor.h"

/*!
 *	@class		figuraGeometrica figuraGeometrica.h
 *	@brief		Class figuraGeometrica
 *	@details	
 */
class figuraGeometrica
{
public:
    figuraGeometrica();
    virtual ~figuraGeometrica();
    virtual void draw(Sculptor &);
};

#endif

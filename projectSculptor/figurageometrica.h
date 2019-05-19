#ifndef FIGURAGEOMETRICA_H
#define FIGURAGEOMETRICA_H

/**
 *	@file		figurageometrica.h
 *	@brief		Classe FiguraGeometrica
 *	@author		Thuize Thainá
 *  @author     Felipe Lima
 *	@date		18/05/2019
 *	@since		18/05/2019
 */

#include "sculptor.h"

/*!
 *	@class		FiguraGeometrica figurageometrica.h
 *	@brief		Class FiguraGeometrica
 *	@details    A classe abstrata Figura Geometrica é definida com métodos virtuais nos quais as subclasses herdam
 */

class FiguraGeometrica
{
public:
    FiguraGeometrica();
    virtual ~FiguraGeometrica();
    virtual void draw(Sculptor& t) = 0;
};

#endif // FIGURAGEOMETRICA_H

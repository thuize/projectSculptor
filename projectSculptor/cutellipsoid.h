#ifndef CUTELLIPSOID_H
#define CUTELLIPSOID_H

/**
 *	@file		cutellipsoid.h
 *	@brief		Classe cutEllipsoid
 *	@author		Thuize Thainá
 *  @author     Felipe Lima
 *	@date		18/05/2019
 *	@since		18/05/2019
 */

#include "figurageometrica.h"

/*!
 *	@class		cutEllipsoid cutellipsoid.h
 *	@brief		Class cutEllipsoid
 *	@details A classe cutEllipsoid é capaz de apagar uma elipsoide no espaço 3D a partir da localização informada.
 */

class cutEllipsoid : public FiguraGeometrica
{
    /**
     * @brief Parâmetros xcenter, ycenter, zcenter, rx, ry, rz
     * @details Parâmetros para determinar a localização da elipsoide na matriz 3D.
     */
    int xcenter, ycenter, zcenter, rx, ry, rz;
public:
    /**
     * @brief cutEllipsoid
     * @param _xcenter
     * @param _ycenter
     * @param _zcenter
     * @param _rx
     * @param _ry
     * @param _rz
     * @details Construtor da classe cutEllipsoid
     */
    cutEllipsoid(int _xcenter, int _ycenter, int _zcenter, int _rx, int _ry, int _rz);
    /**
     * @brief draw
     * @param s
     * @details Método draw capaz de apagar uma elipsoide na matriz 3D.
     */
    void draw(Sculptor &s);
};

#endif // CUTELLIPSOID_H

#ifndef PUTELLIPSOID_H
#define PUTELLIPSOID_H

/**
 *	@file		putellipsoid.h
 *	@brief		Classe putEllipsoid
 *	@author		Thuize Thainá
 *  @author     Felipe Lima
 *	@date		18/05/2019
 *	@since		18/05/2019
 */

#include "figurageometrica.h"

/*!
 *	@class		putEllipsoid putellipsoid.h
 *	@brief		Class putEllipsoid
 *	@details A classe putEllipsoid é capaz de desenhar uma elipsoide no espaço 3D a partir da localização e cor informadas
 */

class putEllipsoid : public FiguraGeometrica
{
    /**
     * @brief Parâmetros xcenter, ycenter, zcenter, rx, ry, rz
     * @details Parâmetros para determinar a localização da elipsoide na matriz 3D.
     */
    int xcenter, ycenter, zcenter, rx, ry, rz;
    /**
     * @brief Parâmetros r, g, b, a
     * @details Parâmetros para determinar a cor e transparência da esfera
     */
    float r,g,b,a;
public:
    /**
     * @brief putEllipsoid
     * @param _xcenter
     * @param _ycenter
     * @param _zcenter
     * @param _rx
     * @param _ry
     * @param _rz
     * @param _r
     * @param _g
     * @param _b
     * @param _a
     * @details Construtor da classe putEllipsoid
     */
    putEllipsoid(int _xcenter, int _ycenter, int _zcenter, int _rx, int _ry, int _rz, float _r, float _g, float _b, float _a);
    /**
     * @brief draw
     * @param s
     * @details Método draw capaz de desenhar uma elipsoide na matriz 3D
     */
    void draw(Sculptor &s);
};

#endif // PUTELLIPSOID_H

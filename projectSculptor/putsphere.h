#ifndef PUTSPHERE_H
#define PUTSPHERE_H

/**
 *	@file		putsphere.h
 *	@brief		Classe putSphere
 *	@author		Thuize Thainá
 *  @author     Felipe Lima
 *	@date		18/05/2019
 *	@since		18/05/2019
 */

#include "figurageometrica.h"

/*!
 *	@class		putSphere putSphere.h
 *	@brief		Class putSphere
 *	@details A classe putSphere é capaz de desenhar uma esfere no espaço 3D a partir da localização e cor informadas
 */

class putSphere : public FiguraGeometrica
{
    /**
     * @brief Parâmetros xcenter, ycenter, zcenter, radius
     * @details Parâmetros para determinar a localização da esfera na matriz 3D.
     */
    int xcenter, ycenter, zcenter, radius;
    /**
     * @brief Parâmetros r, g, b, a
     * @details Parâmetros para determinar a cor e transparência da esfera
     */
    float r,g,b,a;
public:
    /**
     * @brief putSphere
     * @param _xcenter
     * @param _ycenter
     * @param _zcenter
     * @param _radius
     * @param _r
     * @param _g
     * @param _b
     * @param _a
     * @details Construtor da classe putSphere
     */
    putSphere(int _xcenter, int _ycenter, int _zcenter, int _radius, float _r, float _g, float _b, float _a);
    /**
     * @brief draw
     * @param s
     * @details Método draw capaz de desenhar uma esfera na matriz 3D
     */
    void draw(Sculptor &s);
};

#endif // PUTSPHERE_H

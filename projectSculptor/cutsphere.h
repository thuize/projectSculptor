#ifndef CUTSPHERE_H
#define CUTSPHERE_H

/**
 *	@file		cutsphere.h
 *	@brief		Classe cutSphere
 *	@author		Thuize Thainá
 *  @author     Felipe Lima
 *	@date		18/05/2019
 *	@since		18/05/2019
 */

#include "figurageometrica.h"

/*!
 *	@class		cutSphere cutSphere.h
 *	@brief		Class cutSphere
 *	@details A classe cutSphere é capaz de apagar uma elipsoide no espaço 3D a partir da localização informada.
 */

class cutSphere : public FiguraGeometrica
{
    /**
     * @brief Parâmetros xcenter, ycenter, zcenter, radius
     * @details Parâmetros para determinar a localização da esfera na matriz 3D.
     */
    int xcenter, ycenter, zcenter, radius;
public:
    /**
     * @brief cutSphere
     * @param _xcenter
     * @param _ycenter
     * @param _zcenter
     * @param _radius
     * @details Método construtor da classe cutShepere
     */
    cutSphere(int _xcenter, int _ycenter, int _zcenter, int _radius);
    /**
     * @brief draw
     * @param s
     * @details Método draw capax de apagar uma esfera na matriz 3D.
     */
    void draw(Sculptor &s);
};

#endif // CUTSPHERE_H

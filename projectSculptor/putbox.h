#ifndef PUTBOX_H
#define PUTBOX_H

/**
 *	@file		putbox.h
 *	@brief		Classe putBox
 *	@author		Thuize Thainá
 *  @author     Felipe Lima
 *	@date		18/05/2019
 *	@since		18/05/2019
 */

#include "figurageometrica.h"
/*!
 *	@class		putBox putbox.h
 *	@brief		Class putBox
 *	@details A classe putBox é capaz de desenhar uma esfere no espaço 3D a partir da localização e cor informadas
 */

class putBox : public FiguraGeometrica
{
    /**
     * @brief Parâmetros x0, y0, z0, x1, y1, z1
     * @details Parâmetros para determinar a localização do cubo na matriz 3D.
     */
    int x0,y0,z0;
    int x1,y1,z1;
    /**
     * @brief Parâmetros r, g, b, a
     * @details Parâmetros para determinar a cor e transparência do cubo
     */
    float r,g,b,a;
public:
    /**
     * @brief putBox
     * @param _x0
     * @param _x1
     * @param _y0
     * @param _y1
     * @param _z0
     * @param _z1
     * @param _r
     * @param _g
     * @param _b
     * @param _a
     * @details Construtor da classe putBox
     */
    putBox(int _x0, int _x1, int _y0 , int _y1, int _z0, int _z1, float _r, float _g, float _b, float _a);
    /**
     * @brief draw
     * @param s
     * @details Método draw capaz de desenhar um cubo na matriz 3D
     */
    void draw(Sculptor &s);
};

#endif // PUTBOX_H

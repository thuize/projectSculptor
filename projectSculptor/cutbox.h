#ifndef CUTBOX_H
#define CUTBOX_H

/**
 *	@file		cutbox.h
 *	@brief		Classe cutBox
 *	@author		Thuize Thainá
 *  @author     Felipe Lima
 *	@date		18/05/2019
 *	@since		18/05/2019
 */

#include "figurageometrica.h"
/*!
 *	@class		cutBox cutbox.h
 *	@brief		Class cutBox
 *	@details A classe cutBox é capaz de apagar uma esfere no espaço 3D a partir da localização e cor informadas
 */
class cutBox : public FiguraGeometrica
{
    /**
     * @brief Parâmetros x0, y0, z0, x1, y1, z1
     * @details Parâmetros para determinar a localização do cubo na matriz 3D.
     */
    int x0,y0,z0;
    int x1,y1,z1;
public:
    /**
     * @brief cutBox
     * @param _x0
     * @param _x1
     * @param _y0
     * @param _y1
     * @param _z0
     * @param _z1
     * @details Construtor da classe cutBox
     */
    cutBox(int _x0, int _x1, int _y0 , int _y1, int _z0, int _z1);
    /**
     * @brief draw
     * @param s
     * @details Método draw capaz de apagar um cubo na matriz 3D
     */
    void draw(Sculptor &s);
};

#endif // CUTBOX_H

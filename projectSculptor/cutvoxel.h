#ifndef CUTVOXEL_H
#define CUTVOXEL_H

/**
 *	@file		cutvoxel.h
 *	@brief		Classe cutVoxel
 *	@author		Thuize Thainá
 *  @author     Felipe Lima
 *	@date		18/05/2019
 *	@since		18/05/2019
 */

#include "sculptor.h"
#include "figurageometrica.h"

/*!
 *	@class		cutVoxel cutvoxel.h
 *	@brief		Class cutVoxel
 *	@details    A classe cutVoxel é capaz de apagar um voxel a partir da sua localização (x,y,z).
 */


class cutVoxel : public FiguraGeometrica
{
    /**
     * @brief Parâmetros x, y, z
     * @details Parâmetros para determinar a localização do voxel na matriz 3D.
     */
    int x, y, z;
public:
    /**
     * @brief cutVoxel
     * @param _x
     * @param _y
     * @param _z
     * @details Método construtor da classe cutVoxel
     */
    cutVoxel(int _x, int _y, int _z);
    /**
     * @brief draw
     * @param s
     * @details Método draw capaz de apagar um voxel na matriz 3D
     */
    void draw(Sculptor &s);
};

#endif // CUTVOXEL_H

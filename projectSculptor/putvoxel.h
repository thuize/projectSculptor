#ifndef PUTVOXEL_H
#define PUTVOXEL_H

/**
 *	@file		putvoxel.h
 *	@brief		Classe putVoxel
 *	@author		Thuize Thainá
 *  @author     Felipe Lima
 *	@date		18/05/2019
 *	@since		18/05/2019
 */
#include "figurageometrica.h"

/*!
 *	@class		putVoxel putvoxel.h
 *	@brief		Class putVoxel
 *	@details A classe putVoxel é capaz de desenhar um voxel a partir da sua localização (x,y,z)
 * no espaço 3D e com uma cor atribuída pelos parâmetros r,g,b e sua transparência a.
 */

class putVoxel : public FiguraGeometrica
{
    /**
     * @brief Parâmetros x, y, z
     * @details Parâmetros para determinar a localização do voxel na matriz 3D.
     */
    int x, y, z;
    /**
     * @brief Parâmetros r, g, b, a
     * @details Parâmetros para determinar a cor e transparência do voxel
     */
    float r,g,b,a;
public:
    /**
     * @brief putVoxel
     * @param _x
     * @param _y
     * @param _z
     * @param _r
     * @param _g
     * @param _b
     * @param _a
     * @details Construtor da classe putVoxel
     */
    putVoxel(int _x, int _y, int _z, float _r, float _g, float _b, float _a);
    /**
     * @brief draw
     * @param s
     * @details Método para desenhar um voxel
     */
    void draw(Sculptor &s);
};

#endif // PUTVOXEL_H

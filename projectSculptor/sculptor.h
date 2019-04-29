#ifndef SCULPTOR_H
#define SCULPTOR_H
#include <iostream>

/**
 * @file  sculptor.h
 * @brief  Definição da classe Scultor e seus respectivos
 *      métodos para desenhar figuras geométricas.
 * @author  Thuize Thainá
 * @author  Felipe Lima
 * @since  15/04/2019
 * @date  29/04/2019
 */
struct Voxel {
  float red,green,blue; // Colors
  float transparency; // Transparency
  bool isOn; // Included or not
};
class Sculptor{
protected:
    Voxel ***v; // 3D matrix
    int nx,ny,nz; // Dimensions
    float r,g,b,a; // Current drawing color
public:
    Sculptor(int _nx, int _ny, int _nz);
    ~Sculptor();
    void setColor(float _r, float _g, float _b, float _a);
    void putVoxel(int x, int y, int z);
    void cutVoxel(int x, int y, int z);
    void putBox(int x0, int x1, int y0, int y1, int z0, int z1);
    void cutBox(int x0, int x1, int y0, int y1, int z0, int z1);
    void putSphere(int xcenter, int ycenter, int zcenter, int radius);
    void cutSphere(int xcenter, int ycenter, int zcenter, int radius);
    void putEllipsoid(int xcenter, int ycenter, int zcenter, int rx, int ry, int rz);
    void cutEllipsoid(int xcenter, int ycenter, int zcenter, int rx, int ry, int rz);
    //void writeOFF(string filename);
    //void writeVECT(string filename);

};

#endif // SCULPTOR_H

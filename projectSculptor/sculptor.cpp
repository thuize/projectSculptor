/**
 * @file	sculptor.cpp
 * @brief	Implementação do construtor, destrutor, métodos de manipulação dos voxels
 * e escrita em arquivos .vect e .off
 * @author	Thuize Thainá
 * @author  Felipe Lima
 * @since	15/04/2019
 * @date	01/05/2019
 */
#include "sculptor.h"
#include <iostream>
#include <fstream>
#include <string>
using std::ofstream;

/**
 * @details	Construtor da classe "sculptor".
 */
Sculptor::Sculptor(int _nz, int _nx, int _ny){

    if(_nz>0 && _nx>0 && _ny>0){
        nz=_nz; nx=_nx; ny=_ny;

        //Alocação da matriz
        v = new Voxel ** [nz];
        v[0] = new Voxel * [nz*nx];
        v[0][0] = new Voxel [nz*nx*ny];

        int i,j,k;

        for(k=0; k<nz; k++){
            if (k < nz - 1){
                v[0][(k+1)*nx] = &(v[0][0][(k+1)*ny*nx]);
                v[k+1] = &(v[0][(k+1)*nx]);
            }

            for(i=0; i<nx; i++){
                if (i>0) v[k][i] = v[k][i-1] + ny;
            }
        }

        //Inicialização de valores
        for (k=0; k<nz; k++){
            for(i=0; i<nx; i++){
                for(j=0; j<ny; j++){

                    v[k][i][j].isOn=false;
                    v[k][i][j].red   = 0;
                    v[k][i][j].green = 0;
                    v[k][i][j].blue  = 0;
                    v[k][i][j].transparency = 0;
                }
            }
        }
    }else{
        std::cout<<"Tamanho Invalido. " << std::endl;
    }
}

/**
 * @details	Destrutor da classe "sculptor".
 */
Sculptor::~Sculptor(){
    delete[] v[0][0];
    delete[] v[0];
    delete[] v;
}

/**
 * @details Método que define uma cor atual para o desenho.
 */
void Sculptor::setColor(float _r, float _g, float _b, float _a){    
    if (_r>=0 && _r<=1){r=_r;}
    else{r=0;};

    if (_g>=0 && _g<=1){g=_g;}
    else{g=0;};

    if (_b>=0 && _b<=1){b=_b;}
    else{b=0;};

    if (_a>=0 && _a<=1){a=_a;}
    else{a=0;};
}

/**
 * @details	Ativa um voxel na posição (x,y,z) e atribui ao mesmo a cor atual do desenho.
 */
void Sculptor::putVoxel(int x, int y, int z){    
    v[x][y][z].isOn  = true;
    v[x][y][z].red   = r;
    v[x][y][z].green = g;
    v[x][y][z].blue  = b;
    v[x][y][z].transparency = a;
}

/**
 * @details	Desativa o voxel na posição (x,y,z).
 */
void Sculptor::cutVoxel(int x, int y, int z){
    v[x][y][z].isOn  = false;
}

/**
 * @details	Método que desenha um cubo. Ativa todos os voxels pertencentes ao intervalo correspondente
 * aos parâmetros do método, atribuindo aos mesmos a cor atual do desenho.
 */
void Sculptor::putBox(int x0, int x1, int y0, int y1, int z0, int z1)
{
    if ((x0>=0 && x1<=nx) && (y0>=0 && y1<=ny) && (z0>=0 && z1<=nz)){
        for (int k=z0-1;k<z1;k++) {
            for (int i=x0-1; i<x1 ; i++){
                for (int j=y0-1; j<y1; j++) {

                    v[k][i][j].isOn  = true;
                    v[k][i][j].red   = r;
                    v[k][i][j].green = g;
                    v[k][i][j].blue  = b;
                    v[k][i][j].transparency = a;
                }
            }

        }
        /*for (int k=0; k<nz; k++){
            for (int i=0; i<nx; i++) {
                for (int j=0; j<ny; j++) {
                    std::cout<< v[k][i][j].red;
                }
                std::cout << std::endl;
            }
            std::cout << std::endl;
        }*/
    }else{
        std::cout << " Tamanho Invalido! " << std::endl;
    }
}

/**
 * @details	Método que corta um cubo. Desativa todos os voxels pertencentes ao intervalo correspondente
 * aos parâmetros do método.
 */
void Sculptor::cutBox(int x0, int x1, int y0, int y1, int z0, int z1)
{
    if ((x0>=0 && x1<=nx) && (y0>=0 && y1<=ny) && (z0>=0 && z1<=nz)){
        for (int k=z0-1;k<z1;k++){
            for (int i=x0-1; i<x1 ; i++){
                for (int j=y0-1; j<y1; j++){
                    v[k][i][j].isOn  = false;
                }
            }
        }
    }else{
        std::cout << " Tamanho Invalido! " << std::endl;
    }
}

/**
 * @details	Método que desenha uma esfera. Ativa todos os voxels que satisfazem à equação da esfera, 
 * atribuindo aos mesmos a cor atual do desenho
 */
void Sculptor::putSphere(int xcenter, int ycenter, int zcenter, int radius)
{
    float esfera;

    if((zcenter>=radius) && (xcenter>=radius) && (ycenter>= radius)){
        if(((xcenter+radius)<=nx) && ((ycenter+radius)<=ny) && ((zcenter+radius)<=nz)){
            for (int k=zcenter-radius; k<zcenter+radius; k++) {
                for (int i=ycenter-radius; i< ycenter+radius; i++) {
                    for (int j=xcenter-radius; j<xcenter+radius; j++){

                        esfera= (((i-ycenter)*(i-ycenter)) + ((j-xcenter)*(j-xcenter)) + ((k-zcenter)*(k-zcenter)));

                        if (esfera<= (radius*radius)){
                            v[k][i][j].isOn  = true;
                            v[k][i][j].red   = r;
                            v[k][i][j].green = g;
                            v[k][i][j].blue  = b;
                            v[k][i][j].transparency = a;
                        }
                    }
                }
            }

            /*for (int k=0; k<nz; k++){
                for (int i=0; i<nx; i++) {
                    for (int j=0; j<ny; j++) {
                        std::cout<< v[k][i][j].red;
                    }
                    std::cout << std::endl;
                }
                std::cout << std::endl;
            }*/
        }else{
            std::cout << "Raio muito grande!" << std::endl;
        }
    }
    else{
        std::cout << "Os centros devem ser maiores que o raio! " << std::endl;
    }
}

/**
 * @details	Método que corta uma esfera. Desativa todos os voxels que satisfazem à equação da esfera
 */
void Sculptor::cutSphere(int xcenter, int ycenter, int zcenter, int radius)
{
    float esfera;
    if((zcenter>=radius) && (xcenter>=radius) && (ycenter>= radius)){
        if(((xcenter+radius)<=nx) && ((ycenter+radius)<=ny) && ((zcenter+radius)<=nz)){
            for (int k=zcenter-radius; k<zcenter+radius; k++){
                for (int i=ycenter- radius; i< ycenter+radius; i++) {
                    for (int j=xcenter-radius; j<xcenter+radius; j++){

                        esfera= (((i-xcenter)*(i-xcenter)) + ((j-ycenter)*(j-ycenter)) + ((k-zcenter)*(k-zcenter)));

                        if (esfera<= (radius*radius)){
                            v[k][i][j].isOn  = false;
                        }
                    }
                }
            }
        }else{
            std::cout << "Raio muito grande!" << std::endl;
        }
    }else{
        std::cout << "Os centros devem ser maiores que o raio! " << std::endl;
    }
}

/**
 * @details	Método que desenha uma elipsóide. Ativa todos os voxels que satisfazem à equação da elipsóide, 
 * atribuindo aos mesmos a cor atual do desenho
 */
void Sculptor::putEllipsoid(int xcenter, int ycenter, int zcenter, int rx, int ry, int rz)
{
    if((zcenter>=rz) && (xcenter>=rx) && (ycenter>= ry)){
        if(((xcenter+rx)<=ny) && ((ycenter+ry)<=nx) && ((zcenter+rz)<=nz)){
            float n;

            for (int k=(zcenter-rz); k<=(zcenter+rz); k++){
                for (int i=(ycenter-ry); i<=(ycenter+ry); i++) {
                    for (int j=(xcenter-rx); j<=(xcenter+rx); j++) {

                        n=((((i-ycenter)/(float)ry)*((i-ycenter)/(float)ry))+
                           (((j-xcenter)/(float)rx)*((j-xcenter)/(float)rx))+
                           (((k-zcenter)/(float)rz)*((k-zcenter)/(float)rz)));

                        if (n<=1){
                            v[k][i][j].isOn  = true;
                            v[k][i][j].red   = r;
                            v[k][i][j].green = g;
                            v[k][i][j].blue  = b;
                            v[k][i][j].transparency = a;
                        }
                    }
                }
            }

            /*for (int k=0; k<nz; k++){             // teste desenha matriz
                for (int i=0; i<nx; i++) {
                    for (int j=0; j<ny; j++) {
                        std::cout<< v[k][i][j].red;
                    }
                    std::cout << std::endl;
                }
                std::cout << std::endl;
            }*/
        }else{
            std::cout << "Raio muito grande!" << std::endl;
        }
    }else{
        std::cout << "Os centros devem ser maiores que o raio! " << std::endl;
    }
}

/**
 * @details	Método que corta uma elipsóide. Desativa todos os voxels que satisfazem à equação da elipsóide
 */
void Sculptor::cutEllipsoid(int xcenter, int ycenter, int zcenter, int rx, int ry, int rz)
{
    if((zcenter>=rz) && (xcenter>=rx) && (ycenter>= ry)){
        if(((xcenter+rx)<=nx) && ((ycenter+ry)<=ny) && ((zcenter+rz)<=nz)){
            float n;

            for (int k=(zcenter-rz); k<=(zcenter+rz); k++){
                for (int i=(xcenter-rx); i<=(xcenter+rx); i++){
                    for (int j=(ycenter-ry); j<=(ycenter+ry); j++){

                        n=((((i-xcenter)/(float)rx)*((i-xcenter)/(float)rx))+
                           (((j-ycenter)/(float)ry)*((j-ycenter)/(float)ry))+
                           (((k-zcenter)/(float)rz)*((k-zcenter)/(float)rz)));

                        if (n<=1){
                            v[k][i][j].isOn  = false;
                            v[k][i][j].red = 0;
                        }
                    }
                }
            }
        }else{
            std::cout << "Raio muito grande!" << std::endl;
        }
    }else{
        std::cout << "Os centros devem ser maiores que o raio! " << std::endl;
    }
}

/**
 * @details	Método que grava a escultura em um arquivo VECT para permetir a visualização do desenho
 */
void Sculptor::writeVECT(string filename)
{
    int nVoxel = 0;//contador de voxels
    ofstream outfile(filename);

    //Verifica se o arquivo foi aberto
    if (!outfile.is_open()){
		std::cout << "Erro ao abrir o arquivo \n";
		return;
	}

    outfile << "VECT" << endl;

    //Quantidade de voxels ativos
    for (int k = 0; k < nz; k++){
        for (int i = 0; i < nx; i++){
            for (int j = 0; j < ny; j++){
                if (v[k][i][j].isOn == true){
                    nVoxel++;
                }
            }
        }
    }

    //Escrevendo o número de poligonos, vertices e cores
    outfile << nVoxel << " " << nVoxel << " " << nVoxel << endl;

    //Número de vertices por poligono
    for (int i = 0; i < nVoxel; i++){
        outfile << "1" << " ";
    }

    outfile << endl;

    //Número de cores por poligono
    for (int i = 0; i < nVoxel; i++){
        outfile << "1" << " ";
    }

    outfile << endl;

    //Coordenadas do número de vertices
    for (int k = 0; k < nz; k++){
        for (int i = 0; i < nx; i++){
            for (int j = 0; j < ny; j++){
                if (v[k][i][j].isOn == 0){
                    outfile << i << " " << j << " " << k << endl;
                }
            }
        }
    }

    //Cores e transparência
    for (int k = 0; k < nz; k++){
        for (int i = 0; i < nx; i++){
		    for (int j = 0; j < ny; j++){
				if (v[k][i][j].isOn){ 
					outfile << v[k][i][j].red << " " << v[k][i][j].green << " " << v[k][i][j].blue 
                    << " " << v[k][i][j].transparency << "\n";
                }
            }
        }
    }

    outfile.close();
    std::cout << "Arquivo VECT criado\n";
}

/**
 * @details	Método que grava a escultura em um arquivo OFF para permetir a visualização do desenho
 */
void Sculptor::writeOFF(string filename)
{
    ofstream outfile(filename);

	int nVoxel = 0;//contador de voxel
	int f = 0;//face

    //Verificar se o arquivo foi aberto
	if (!outfile.is_open()) {
		std::cout << "Erro ao abrir o arquivo \n";
		return;
	}

    //Escreve a primeira linha contendo o formato do arquivo
	outfile << "OFF\n";

    //Percorre a matriz para saber a quantidade de voxels ativos
    for (int k = 0; k < nz; k++){
	    for (int i = 0; i < nx; i++){
	    	for (int j = 0; j < ny; j++){
				if (v[k][i][j].isOn){ 
					nVoxel++;
                }
            }
        }
    }

    //Escrevendo o número de vértices, faces e arestas(padrão como 0)
	outfile << 8 * nVoxel << " " << 6 * nVoxel << " 0\n";

    //Escrevendo as coordenadas dos vértices
	for (int k = 0; k < nz; k++){
		for (int j = 0; j < ny; j++){
			for (int i = 0; i < nx; i++){
				if (v[k][j][i].isOn){
				  outfile << i-0.5 << " " << j+0.5 << " " << k-0.5 << "\n"
						<< i-0.5 << " " << j-0.5 << " " << k-0.5 << "\n"
						<< i+0.5 << " " << j-0.5 << " " << k-0.5 << "\n"
						<< i+0.5 << " " << j+0.5 << " " << k-0.5 << "\n"
						<< i-0.5 << " " << j+0.5 << " " << k+0.5 << "\n"
						<< i-0.5 << " " << j-0.5 << " " << k+0.5 << "\n"
						<< i+0.5 << " " << j-0.5 << " " << k+0.5 << "\n"
						<< i+0.5 << " " << j+0.5 << " " << k+0.5 << "\n";
				}
			}
		}
	}
	
	for (int k = 0; k < nz; k++){
        for (int i = 0; i < nx; i++){
		    for (int j = 0; j < ny; j++){
				if (v[k][i][j].isOn){
					f = 8*f;
					outfile << "4 " << f+0 << " " << f+3 << " " << f+2 << " " << f+1 << " " << v[k][i][j].red << " " << v[k][i][j].green << " " << v[k][i][j].blue << " " << v[k][i][j].transparency << "\n"
						<< "4 " << f+4 << " " << f+5 << " " << f+6 << " " << f+7 << " " << v[k][i][j].red << " " << v[k][i][j].green << " " << v[k][i][j].blue << " " << v[k][i][j].transparency << "\n"
						<< "4 " << f+0 << " " << f+1 << " " << f+5 << " " << f+4 << " " << v[k][i][j].red << " " << v[k][i][j].green << " " << v[k][i][j].blue << " " << v[k][i][j].transparency << "\n"
						<< "4 " << f+0 << " " << f+4 << " " << f+7 << " " << f+3 << " " << v[k][i][j].red << " " << v[k][i][j].green << " " << v[k][i][j].blue << " " << v[k][i][j].transparency << "\n"
						<< "4 " << f+3 << " " << f+7 << " " << f+6 << " " << f+2 << " " << v[k][i][j].red << " " << v[k][i][j].green << " " << v[k][i][j].blue << " " << v[k][i][j].transparency << "\n"
						<< "4 " << f+1 << " " << f+2 << " " << f+6 << " " << f+5 << " " << v[k][i][j].red << " " << v[k][i][j].green << " " << v[k][i][j].blue << " " << v[k][i][j].transparency << "\n";
					f = f/8+1;
				}
			}
		}
	}
	
	outfile.close();
	std::cout << "Arquivo OFF criado\n";
}

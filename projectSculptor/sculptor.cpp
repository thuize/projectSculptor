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
#include <string>
using std::fstream;

/**
 * @details	Construtor da classe "sculptor".
 */
Sculptor::Sculptor(int _nz, int _ny, int _nx){

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
    if (x>=0 && x<nx && y>=0 && y<ny && z>=0 && z<nz ){

        v[x][y][z].isOn  = true;
        v[x][y][z].red   = r;
        v[x][y][z].green = g;
        v[x][y][z].blue  = b;
        v[x][y][z].transparency = a;
    }
}

/**
 * @details	Desativa o voxel na posição (x,y,z).
 */
void Sculptor::cutVoxel(int x, int y, int z){
    v[x][y][z].isOn  = false;
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
    ofstream fout;


    fout.open("./"+filename+".off");
    if(fout.is_open() == false)
    {
        std::cout << "Nao foi possivel abrir o arquivo! \n";
        exit(0);
    }

    fout<<"OFF"<<endl;

    int nvoxels = 0;
    for(int i = 0; i<nz; i++){
        for(int j = 0; j<ny; j++){
            for(int k = 0; k<nx; k++){
                if(v[i][j][k].isOn){
                    nvoxels = nvoxels+1;
                }
            }
        }
    }
    fout<<nvoxels*8<<" "<<nvoxels*6<<" 0"<<endl;
    float R=0.5f;
    for(int i = 0; i<nz; i++){
        for(int j = 0; j<ny; j++){
            for(int k = 0; k<nx; k++){
                if(v[i][j][k].isOn){

                    fout<<(float)i-R<<" "<<(float)j+R<<" "<<(float)k-R<<endl;
                    fout<<(float)i-R<<" "<<(float)j-R<<" "<<(float)k-R<<endl;
                    fout<<(float)i+R<<" "<<(float)j-R<<" "<<(float)k-R<<endl;
                    fout<<(float)i+R<<" "<<(float)j+R<<" "<<(float)k-R<<endl;
                    fout<<(float)i-R<<" "<<(float)j+R<<" "<<(float)k+R<<endl;
                    fout<<(float)i-R<<" "<<(float)j-R<<" "<<(float)k+R<<endl;
                    fout<<(float)i+R<<" "<<(float)j-R<<" "<<(float)k+R<<endl;
                    fout<<(float)i+R<<" "<<(float)j+R<<" "<<(float)k+R<<endl;
                }
            }
        }
    }



    int nv = 0;
    for(int i = 0; i<nz; i++){
        for(int j = 0; j<ny; j++){
            for(int k = 0; k<nx; k++){
                if(v[i][j][k].isOn){


                    fout<<"4 "<<nv+0<<" "<<nv+3<<" "<<nv+2<<" "<<nv+1<<" "<<v[i][j][k].red<<" "<<v[i][j][k].green<<" "<<v[i][j][k].blue<<" "<<v[i][j][k].transparency<<endl;
                    fout<<"4 "<<nv+4<<" "<<nv+5<<" "<<nv+6<<" "<<nv+7<<" "<<v[i][j][k].red<<" "<<v[i][j][k].green<<" "<<v[i][j][k].blue<<" "<<v[i][j][k].transparency<<endl;
                    fout<<"4 "<<nv+0<<" "<<nv+1<<" "<<nv+5<<" "<<nv+4<<" "<<v[i][j][k].red<<" "<<v[i][j][k].green<<" "<<v[i][j][k].blue<<" "<<v[i][j][k].transparency<<endl;
                    fout<<"4 "<<nv+0<<" "<<nv+4<<" "<<nv+7<<" "<<nv+3<<" "<<v[i][j][k].red<<" "<<v[i][j][k].green<<" "<<v[i][j][k].blue<<" "<<v[i][j][k].transparency<<endl;
                    fout<<"4 "<<nv+3<<" "<<nv+7<<" "<<nv+6<<" "<<nv+2<<" "<<v[i][j][k].red<<" "<<v[i][j][k].green<<" "<<v[i][j][k].blue<<" "<<v[i][j][k].transparency<<endl;
                    fout<<"4 "<<nv+1<<" "<<nv+2<<" "<<nv+6<<" "<<nv+5<<" "<<v[i][j][k].red<<" "<<v[i][j][k].green<<" "<<v[i][j][k].blue<<" "<<v[i][j][k].transparency<<endl;

                    nv = nv+8;
                }
            }
        }
    }
}



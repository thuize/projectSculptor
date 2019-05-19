/**
 * @file	main.cpp
 * @brief	Demonstração da implementação do escultor digital
 * @author	Thuize Thainá
 * @author  Felipe Lima
 * @since	15/04/2019
 * @date	01/05/2019
 */

#include "sculptor.h"
#include "figurageometrica.h"
#include <vector>
#include "putbox.h"
#include "putvoxel.h"
#include "cutvoxel.h"
#include "cutbox.h"
#include "putsphere.h"
#include "cutsphere.h"
#include "putellipsoid.h"
#include "cutellipsoid.h"

using namespace std;

int main()
{  
    Sculptor *array;
    vector<FiguraGeometrica*> fig;
    fstream fin;
    string s, filename;
    stringstream ss;

    int xx, yy, zz;
    int x0, y0, z0;
    int x1, y1, z1;
    int raio, raiox, raioy, raioz;
    float r, g, b, a;


    fin.open("b.txt");
    if(!fin.is_open()){
        cout << "Nao foi possivel abrir o arquivo!" << endl;
        exit(0);
    }

    while(fin.good()){
        getline(fin, s);
        ss.clear();
        ss.str(s);
        ss >> s;

        std::cout << s << endl;
        if(s.compare("dim") == 0){
            ss >> xx >> yy >> zz;
            std::cout << xx << "x" << yy << "x" << zz << std::endl;
            array= new Sculptor(zz,yy,xx);
        }

        else if(s.compare("putvoxel") == 0){
            ss >> x0 >> y0 >> z0 >> r >> g >> b >> a;
            fig.push_back(new putVoxel(x0,y0,z0,r,g,b,a));

        }

       else if(s.compare("cutvoxel") == 0){
            ss >> x0 >> y0 >> z0 ;
            fig.push_back(new cutVoxel(x0,y0,z0));
        }

       else if(s.compare("putbox") == 0){
            int   xbox,ybox,zbox,x1box,y1box,z1box;
            float rbox,gbox,bbox,abox;

            ss >>xbox >> x1box >> ybox >> y1box >> zbox >> z1box >> rbox >> gbox >> bbox >> abox;
            fig.push_back(new putBox(xbox,x1box,ybox,y1box,zbox,z1box,rbox,gbox,bbox,abox));
        }

        else if(s.compare("cutbox")){

            ss >> x0 >> x1 >> y0 >> y1 >> z0 >> z1;
            fig.push_back(new cutBox(x0,x1,y0,y1,z0,z1));
        }

       else if(s.compare("putsphere")== 0){
            std::cout << "ALOOOOO " ;
            int xsphere, ysphere, zsphere, raiosphere;
            float rsphere, gsphere, bsphere, asphere;

            ss >> xsphere >> ysphere >> zsphere >> raiosphere >> rsphere >> gsphere >> bsphere >> asphere;
            fig.push_back(new putSphere(xsphere,ysphere,zsphere,raiosphere,rsphere,gsphere,bsphere,asphere));
        }

       else if(s.compare("cutsphere")== 0){
            ss >> x0 >> y0 >> z0 >> raio >> r >> g >> b >> a;
            fig.push_back(new cutSphere(x0,y0,z0,raio));
        }

       else if(s.compare("putellipsoid") == 0){
            int xelli,yelli,zelli,xraioelli,yraioelli,zraioelli;
            float relli,gelli,belli,aelli;

            ss >> xelli >> yelli >> zelli >> xraioelli >> yraioelli >> zraioelli >> relli >> gelli >> belli >> aelli;
            fig.push_back(new putEllipsoid(xelli,yelli,zelli,xraioelli,yraioelli,zraioelli,relli,gelli,belli,aelli));
        }

       else if(s.compare("cutellipsoid") == 0){
            ss >> x0 >> y0 >> z0 >> raiox >> raioy >> raioz;
            fig.push_back(new cutEllipsoid(x0,y0,z0,raiox,raioy,raioz));

        }

        else{
            cout << "Arquivo escrito errado ! " << endl;
        }

        for(int i = 0; i< fig.size(); i++){
            fig[i]->draw(*array);
        }
    }

    (*array).writeOFF("DesenhoOFF");


    return 0;
}

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
/**
 * @brief main
 * @return Arquivo OFF
 * @details No arquivo main é realizada a leitura do arquivo contendo as especificações do desenho a ser criado,
 * além de, após executadas as devidas operações, é retonado o arquivo OFF que permite visualizar o desenho por meio
 * de um software externo de visualização 3D.
 */
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

            ss >> xbox >> x1box >> ybox >> y1box >> zbox >> z1box >> rbox >> gbox >> bbox >> abox;
            fig.push_back(new putBox(xbox,x1box,ybox,y1box,zbox,z1box,rbox,gbox,bbox,abox));
        }

        else if(s.compare("cutbox")==0){
            int   cxbox,cybox,czbox,cx1box,cy1box,cz1box;

            ss >> cxbox >> cx1box >> cybox >> cy1box >> czbox >> cz1box;
            fig.push_back(new cutBox(cxbox,cx1box,cybox,cy1box,czbox,cz1box));
        }

       else if(s.compare("putsphere")== 0){

            int xsphere, ysphere, zsphere, raiosphere;
            float rsphere, gsphere, bsphere, asphere;

            ss >> xsphere >> ysphere >> zsphere >> raiosphere >> rsphere >> gsphere >> bsphere >> asphere;
            fig.push_back(new putSphere(zsphere,ysphere,xsphere,raiosphere,rsphere,gsphere,bsphere,asphere));
        }

       else if(s.compare("cutsphere")== 0){
            int cxsphere, cysphere, czsphere, craiosphere;

            ss >> cxsphere >> cysphere >>czsphere >> craiosphere;
            fig.push_back(new cutSphere(czsphere,cysphere,cxsphere,craiosphere));
        }

       else if(s.compare("putellipsoid") == 0){
            int xelli,yelli,zelli,xraioelli,yraioelli,zraioelli;
            float relli,gelli,belli,aelli;

            ss >> xelli >> yelli >> zelli >> xraioelli >> yraioelli >> zraioelli >> relli >> gelli >> belli >> aelli;
            fig.push_back(new putEllipsoid(zelli,yelli,xelli,zraioelli,yraioelli,xraioelli,relli,gelli,belli,aelli));
        }

       else if(s.compare("cutellipsoid") == 0){
            int cxelli,cyelli,czelli,cxraioelli,cyraioelli,czraioelli;


            ss >> cxelli >> cyelli >> czelli >> cxraioelli >> cyraioelli >> czraioelli;
            fig.push_back(new cutEllipsoid(czelli,cyelli,cxelli,czraioelli,cyraioelli,cxraioelli));
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

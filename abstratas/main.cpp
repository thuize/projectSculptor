#include <iostream>
#include <vector>
#include "figurageometrica.h"
#include "putBox.h"
#include "putSphere.h"
#include "cutbox.h"

using namespace std;

int main(){
    figuraGeometrica *pfg;//não precisa executar o draw nesse classe abstrata
    //INVALIDA
    //figuraGeometrica fg;
    putBox *pbx, bx;
    putSphere *psph, sph;
    cutBox *pcb, cb;
    vector<figuraGeometrica*> figs;//com o ponteiro guarda os endereços da classes filhas(box, sphere...)

    figs.push_back(new putBox());//uso de alocação dinâmica(aloca e chama o construtor nos parametros, e retorna um endereço; ex: limites para desenhar a figura)
    //pfg = &bx;//armazena o endereço de uma caixa;
    figs.push_back(new cutBox());
    figs.push_back(new putBox());
    figs.push_back(new cutBox());

    for(int i=0; i < figs.size(); i++){ //fazer um método para desenhar
        figs[i]->draw();//usa setinha para executar o método por ter endereços armazenados
    }

    for(int i=0; i < figs.size(); i++){ //fazer um método para desalocar
         delete figs[i]->draw();//usa setinha para executar o método por ter endereços armazenados
    }

    //pfg = &sph;
    //Polimorfismo: várias formas(permite que as classes filhas herdem métodos da classe principal)
    //pfg->draw();//como na classe filha está virtual, o método chamado é o dela

    return 0;
}

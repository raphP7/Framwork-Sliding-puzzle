#include"FramPlateauLand.hpp"
#include"2048/Case2048.hpp"
#include"2048/Plateau2048.hpp"
#include"2048/Case2048Destroy/Case2048Destroy.hpp"
#include"Takin/PlateauTakin.hpp"

void takin(){

	PlateauTakin<int> pTakinInt(2,2);
    vector<int> v { 2,7,0,10 };
    pTakinInt.initPlateau(v);
    pTakinInt.setBlank(1,0);
    pTakinInt.setBlankCaseAtTheEnd();
    pTakinInt.setModeJeux(true);
    pTakinInt.startGame();
}

void play2048(){

	Plateau2048 pl2048(3,3);
	pl2048.initPlateau();
	pl2048.setModeJeux(true);
/*
	Case2048Destroy *a = new Case2048Destroy(0,0);
		a->valeur=9;

	pl2048.plateau[0][0]=a;

	pl2048.plateau[1][0]->valeur=12;

	pl2048.affiche();

	pl2048.doDirectionalSWIPE('i',false);

	pl2048.affiche();

*/
	pl2048.startGame();
}

int main() {
    std::cout<<"bonjour2"<<std::endl;

    class mama:public CaseGeneric{
    public:
    mama(int t,int v):CaseGeneric(t,v,true){

        }
    };

    play2048();
    //FramPlateauLand<int>* fr; //INTERDIT

    //FramPlateauLand<mama>* fr;
    //fr = new FramPlateauLand<mama>(8, 8);

    /*
	FramPlateauLand<Case2048>* fram;

    fram = new FramPlateauLand<Case2048>(8, 8);//interdit
	fram->affiche();

	Case2048Destroy *a = new Case2048Destroy(0,0);
	a->valeur=9;

	fram->plateau[0][0]=a;

	fram->plateau[1][0]->valeur=12;

	fram->affiche();

	fram->doDirectionalSWIPE('i',false);
	delete fram;
	*/



}

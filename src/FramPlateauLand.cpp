/*
 * FramPlateauLand.cpp
 *
 *  Created on: 1 déc. 2016
 *      Author: raphael
 */

#include"FramPlateauLand.hpp"
#include"2048/Case2048.hpp"
#include"2048/Plateau2048.hpp"
#include"2048/Case2048Destroy/Case2048Destroy.hpp"
#include"Takin/PlateauTakin.hpp"

int main() {
    std::cout<<"bonjour"<<std::endl;

    class mama:public CaseGeneric{
    public:
    mama(int t,int v):CaseGeneric(t,v){

        }
    };


    //FramPlateauLand<int>* fr; //INTERDIT

    //FramPlateauLand<mama>* fr;
    //fr = new FramPlateauLand<mama>(8, 8);

/*
	FramPlateauLand<Case2048>* fram;

    fram = new FramPlateauLand<Case2048>(8, 8);
	fram->affiche();
*/
/*
	Case2048Destroy *a = new Case2048Destroy(0,0);
	a->valeur=9;

	fram->plateau[0][0]=a;
*/
/*
	fram->affiche();
	delete fram;

	Plateau2048 pl2048(3,3);

	pl2048.initPlateau();
	pl2048.setModeJeux(true);
	pl2048.startGame();
*/




	PlateauTakin<int> pTakinInt(2,2);
    vector<int> v { 2,7,0,10 };
    pTakinInt.initPlateau(v);
    pTakinInt.setBlank(1,0);
    pTakinInt.setBlankCaseAtTheEnd();
    pTakinInt.setModeJeux(true);
    pTakinInt.startGame();
}

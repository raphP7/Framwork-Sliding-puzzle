/*
 * FramPlateauLand.cpp
 *
 *  Created on: 1 déc. 2016
 *      Author: raphael
 */

#include"FramPlateauLand.hpp"
#include"2048/Case2048.hpp"
#include"2048/Plateau2048.hpp"
#include"Takin/PlateauTakin.hpp"



template<typename T> FramPlateauLand<T>::FramPlateauLand(
		vector<vector<T> > _pla) :
		plateau(_pla) {}



int main() {
    std::cout<<"bonjour"<<std::endl;

    class mama:public CaseGeneric{
    public:
    mama(int t,int v):CaseGeneric(t,v){

        }
    };


    //FramPlateauLand<int>* fr; //INTERDIT

    FramPlateauLand<mama>* fr;
    //fr = new FramPlateauLand<mama>(8, 8);



	FramPlateauLand<Case2048>* fram;

    fram = new FramPlateauLand<Case2048>(8, 8); // INTERDIT
	fram->affiche();
	fram->plateau[0][0]->valeur=2;
	fram->affiche();
	delete fram;



	Plateau2048 pl2048(3,3);
	pl2048.affiche();
	pl2048.initPlateau();
	pl2048.setModeJeux(true);
	pl2048.startGame();


	/*
	PlateauTakin<char> pTakin(3,3);
	pTakin.plateau[0][0]->valeur='a';
	pTakin.plateau[0][1]->valeur='b';
	pTakin.plateau[0][2]->valeur='c';
	pTakin.plateau[1][0]->valeur='d';
	pTakin.plateau[1][1]->valeur='e';
	pTakin.plateau[1][2]->valeur='f';
	pTakin.plateau[2][0]->valeur='g';
	pTakin.plateau[2][1]->valeur='h';
	pTakin.plateau[2][2]->valeur='-';


	pTakin.affiche();

    iterDoubleVector< CaseTakin<char > > monIter(pTakin.plateau);
    cout<<"modification avec iterateur"<<endl;
    while(monIter.hasnext()){
        monIter.next()->valeur='P';

    }
	pTakin.affiche();
*/
	/*
	PlateauTakin<int> pTakinInt(2,2);
    pTakinInt.affiche();

    vector<int> v { 2,7,0,10 };
    pTakinInt.initPlateau(v);
    pTakinInt.setBlank(1,0);
    pTakinInt.setModeJeux(true);
    //pTakinInt.startGame();
*/
}

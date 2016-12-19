/*
 * Plateau2048.cpp
 *
 *  Created on: 1 déc. 2016
 *      Author: raphael
 */

#include "Plateau2048.hpp"
#include "Case2048.hpp"

Plateau2048::Plateau2048(int sizeI, int sizeJ) :
		FramPlateauLand<Case2048>(sizeI, sizeJ,false) {
	recursive = false;
}

bool Plateau2048::isFusionnable(Case2048 * case1, Case2048 * case2)const {
	return case1->FusionWith(*case2,true);
}

bool Plateau2048::isCaseEmpty(Case2048 const* case1) {
	return case1->empty;
}

void Plateau2048::applyFusion(Case2048 * case1, Case2048 * case2) {
	//cout<<"fusion de "<<case1->i<<" "<<case1->j<<" et "<<case2->i<<" "<<case2->j<<endl;
	case1->FusionWith(*case2,false);
}
bool Plateau2048::performAction(int xArriv,int yArriv,char direction){

	char *commande = new char();
	bool Notdone = true;
	while (Notdone) {

		if(modeJoeur){
			this->getInputDirectionFromConsole(commande);
		}else{
			*commande=this->getRandomDirection();
			//cout<<"direction choisi : "<<*commande<<endl;
		}
		if (doDirectionalSWIPE(*commande, recursive)) {
			Notdone = false;
		} else {
			if(modeJoeur){
				cout << "MOUVEMENT INEFICASSE" << endl;
			}
		}
	}
	addNewValue();
	delete commande;
	return true;
}

void Plateau2048::addNewValue() {

	Case2048 * tmp=this->getRandomEmptyCase();

	//select by random the case with a new value
	random_device seeder;
	mt19937 engine(seeder());

	//10 % chance of add a 4
	uniform_int_distribution<int> dist2(0, 10);
	int random2or4 = dist2(engine);
	tmp->empty=false;
	if (random2or4 > 8) {
		tmp->valeur = 4;
	} else {
		tmp->valeur = 2;
	}
	cout<<"nouvelle valeur : "<<tmp->valeur<< " Position x:"<<tmp->i<<"|y:"<<tmp->j<<endl;

}

void Plateau2048::initPlateau(vector<int> contenuJeu) {

		iterDoubleVector<Case2048> monIter(this->plateau);

		//for good random
		random_device seeder;
		mt19937 engine(seeder());
		uniform_int_distribution<int> dist(0, monIter.getSizeMax() - 1);
		int randomPosition = dist(engine);

		int i = randomPosition / plateau.size();
		int j = randomPosition % plateau.size();

		plateau[i][j]->valeur = 2;
		plateau[i][j]->empty = false;

	}

bool Plateau2048::gameEnd() {
	/*
	cout<<"i possible ?"<<doDirectionalSWIPE('i',false ,true) <<endl;
	cout<<"j possible ?"<<doDirectionalSWIPE('j',false ,true) <<endl;
	cout<<"k possible ?"<<doDirectionalSWIPE('k',false ,true) <<endl;
	cout<<"l possible ?"<<doDirectionalSWIPE('l',false ,true) <<endl;
	*/
	return !(doDirectionalSWIPE('i',false ,true) || doDirectionalSWIPE('j',false ,true) ||
			doDirectionalSWIPE('k',false ,true) || doDirectionalSWIPE('l',false ,true));
}

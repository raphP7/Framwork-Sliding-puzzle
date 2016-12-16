/*
 * Plateau2048.cpp
 *
 *  Created on: 1 déc. 2016
 *      Author: raphael
 */

#include "Plateau2048.hpp"
#include "Case2048.hpp"

Plateau2048::Plateau2048(int sizeI, int sizeJ) :
		FramPlateauLand<Case2048>(sizeI, sizeJ) {
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
void Plateau2048::performAction() {

	char *commande = new char();
	bool Notdone = true;
	while (Notdone) {
		this->getInputDirectionFromConsole(commande);

		if (*commande == 'i' || *commande == 'j' || *commande == 'k'
				|| *commande == 'l') {
			if (doDirectionalSWIPE(*commande, recursive)) {
				Notdone = false;
			} else {
				cout << "MOUVEMENT INEFICASSE" << endl;
			}

		} else {
			cout << "BAD INPUT , i -> UP | j -> LEFT | k -> DOWN | l -> RIGHT"
					<< endl;
		}
	}
	delete commande;
	addNewValue();
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

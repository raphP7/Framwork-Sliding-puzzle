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

bool Plateau2048::isFusionnable(Case2048 const& case1, Case2048 const& case2) {
	return operator==(case1, case2);
}

bool Plateau2048::isCaseEmpty(Case2048 const& case1) {
	return case1.valeur == 0;
}

void Plateau2048::applyFusion(Case2048 & case1, Case2048 & case2) {
	case1 > case2;

	//cout<<"fusion de "<<case1->i<<" "<<case1->j<<" dans "<<case2->i<<" "<<case2->j<<endl;

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
	iterDoubleVector<Case2048> monIter(this->plateau);

	//list all the empty cases
	vector<Case2048*> vecFreeCase;
	Case2048 * tmp;
	while (monIter.hasnext()) {
		tmp = monIter.next();
		if (tmp->valeur == 0) {
			vecFreeCase.push_back(tmp);
		}
	}
	int sizeMax = vecFreeCase.size();

	if (sizeMax == 0) {
		return;
	}
	//select by random the case with a new value
	random_device seeder;
	mt19937 engine(seeder());
	uniform_int_distribution<int> dist(0, sizeMax - 1);
	int randomPosition = dist(engine);

	//10 % chance of add a 4
	uniform_int_distribution<int> dist2(0, 10);
	int random2or4 = dist2(engine);
	if (random2or4 > 8) {
		vecFreeCase[randomPosition]->valeur = 4;
	} else {
		vecFreeCase[randomPosition]->valeur = 2;
	}

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

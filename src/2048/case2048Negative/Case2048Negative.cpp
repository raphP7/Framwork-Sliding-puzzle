/*
 * Case2048Negative.cpp
 *
 *  Created on: 1 déc. 2016
 *      Author: raphael
 */

#include "Case2048Negative.hpp"

Case2048Negative::Case2048Negative(int _i, int _j) :
		Case2048(_i, _j) {
	//std::cout << "appel constructeur Case2048 : "<<i<<" "<<j << std::endl;
}

Case2048Negative::~Case2048Negative() {
	std::cout<<"delete 2048 NEGATIVE de "<<i<<" "<<j<<std::endl;
}

void Case2048Negative::Print(std::ostream& O) const {
	O <<"-"<<valeur << " ";
}

std::string Case2048Negative::toString() const {
	if(empty){
		return std::string();
	}else{
		return "-"+std::to_string(valeur);
	}
}

char Case2048Negative::testFusion(Case2048 * case2, bool firstCall) {
	Case2048* v;
	if (typeid(*case2) == typeid(Case2048)) {
		v = dynamic_cast<Case2048*>(case2);
	} else if ((typeid(*case2) == typeid(Case2048))) {
		v = dynamic_cast<Case2048Negative*>(case2);
	} else {
		std::cout << "un inconnu 2048 dans 2048" << std::endl;
		if (firstCall && case2->testFusion(this, false) == 'l') {
			return 'r';
		} else {
			return ' ';
		}
	}
	if (this->empty && v->empty) {
		return ' ';
	}
	if (v->empty || (this->valeur == v->valeur)) {
		return 'l';
	} else {
		return ' ';
	}

}

DoublePointer<Case2048>* Case2048Negative::performFusion(Case2048 *case2,char direction) {
	if (typeid(*case2) == typeid(Case2048)) {
		//Case2048* v = dynamic_cast<Case2048*>(case2);

		if (direction == 'l') {
			case2->valeur =0;
			case2->empty = true;
			case2->i = this->i;
			case2->j = this->j;
			this->valeur = 0;
			this->empty = true;
		} else {
			this->valeur += case2->valeur;
			this->empty = false;
			this->i = case2->i;
			this->j = case2->j;
			case2->valeur = 0;
			case2->empty = true;
		}
		return nullptr;

	} else {
		if (direction == 'r') {
			//TODO
			std::cout << "probleme performFusion" << std::endl;
			return nullptr;
		} else {
			return case2->performFusion(this, 'r');
		}

	}
}

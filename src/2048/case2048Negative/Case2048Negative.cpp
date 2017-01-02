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
	//std::cout<<"delete 2048 NEGATIVE de "<<i<<" "<<j<<std::endl;
}

char Case2048Negative::testFusion(Case2048 * case2, bool firstCall) {

	if (typeid(*case2) == typeid(Case2048) || (typeid(*case2) == typeid(Case2048Negative))) {
		if (this->empty && case2->empty) {
				return ' ';
			}
			if (case2->empty || (this->valeur == case2->valeur)) {
				return 'l';
			} else {
				return ' ';
			}
	}
	else {
		//std::cout << "un inconnu 2048 dans 2048Negative" << std::endl;
		if (firstCall && case2->testFusion(this, false) == 'l') {
			return 'r';
		} else {
			return ' ';
		}
	}
}

DoublePointer<Case2048>* Case2048Negative::performFusion(Case2048 *case2,char direction) {

	Case2048 * caseVide = new Case2048(this->i, this->j);
	Case2048 * caseVide2 = new Case2048(case2->i, case2->j);
	Case2048 * caseThis = new Case2048Negative(case2->i,case2->j);
	caseThis->valeur=this->valeur;
	caseThis->empty=false;

	if (case2->empty) {
		//cout << "Negative se deplace sur une empty" << endl;
		return new DoublePointer<Case2048>(caseVide, caseThis);
	}

	if (typeid(*case2) == typeid(Case2048Negative)) {
		caseThis->valeur+=case2->valeur;
		//cout << "Negative FUSIONNE" << endl;
		return new DoublePointer<Case2048>(caseVide, caseThis);

	} else {
		if (direction == 'r') {
			//TODO
			//std::cout << "probleme performFusion" << std::endl;
			return nullptr;
		} else {
			return case2->performFusion(this, 'r');
		}

	}
}

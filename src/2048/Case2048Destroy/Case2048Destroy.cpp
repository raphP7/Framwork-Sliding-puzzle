/*
 * Case2048Destroy.cpp
 *
 *  Created on: 1 déc. 2016
 *      Author: raphael
 */

#include "Case2048Destroy.hpp"

Case2048Destroy::Case2048Destroy(int _i, int _j) :
		Case2048(_i, _j, false) {

	//std::cout << "appel constructeur Case2048 : "<<i<<" "<<j << std::endl;

}

Case2048Destroy::~Case2048Destroy() {
	std::cout<<"delete 2048 DESTROY de "<<i<<" "<<j<<std::endl;
}

void Case2048Destroy::Print(std::ostream& O) const {
	O << "#" << " ";
}

std::string Case2048Destroy::toString() const {
	return "#";
}

char Case2048Destroy::testFusion(Case2048 * case2,bool firstCall) {

	return 'l';

}

DoublePointer<Case2048>* Case2048Destroy::performFusion(Case2048 *case2,
		char direction) {

	Case2048 * caseVide = new Case2048(this->i, this->j);
	Case2048 * caseVide2 = new Case2048(case2->i, case2->j);
	Case2048 * caseThis = new Case2048Destroy(case2->i,case2->j);
	caseThis->empty=false;

	if (case2->empty) {
		cout << "destroy se deplace sur une empty" << endl;
		return new DoublePointer<Case2048>(caseVide, caseThis);
	} else {
		cout << "destroy detruit" << endl;
		return new DoublePointer<Case2048>(caseVide,caseVide2);
	}
}

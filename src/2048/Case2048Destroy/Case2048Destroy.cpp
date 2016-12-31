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

	if (typeid(*case2) == typeid(Case2048Destroy)
			|| typeid(*case2) == typeid(Case2048)) {
			return 'l';
	} else {
		cout << "un inconnu 2048 dans Case2048Destroy" << endl;
		if(firstCall && case2->testFusion(this,false)!=' '){
			return 'r';
		}else{
			return ' ';
		}
	}
}

DoublePointer<Case2048>* Case2048Destroy::performFusion(Case2048 *case2,
		char direction) {

	Case2048 * caseVide = new Case2048(this->i, this->j);
	Case2048 * caseVide2 = new Case2048(case2->i, case2->j);
	Case2048 * caseThis = new Case2048Destroy(this->i,this->j);

	if (case2->empty) {
		cout << "destroy se deplace sur une empty" << endl;
		if(direction=='l'){
			cout<<"l"<<endl;
			return new DoublePointer<Case2048>(caseVide, caseThis);
		}else{
			cout<<"r"<<endl;
			this->i=case2->i;
			this->j=case2->j;
			return new DoublePointer<Case2048>(caseThis, caseVide);
		}

	} else {
		//cout << "une valeur SE DEPLACE SUR DESTROY" << endl;
		if(direction=='l'){
			cout<<"l"<<endl;
			return new DoublePointer<Case2048>(caseVide,caseVide2);
		}else{

			return new DoublePointer<Case2048>(caseVide2, caseVide);
		}


	}
}

/*
 * Case2048.cpp
 *
 *  Created on: 1 déc. 2016
 *      Author: raphael
 */

#include "Case2048.hpp"

Case2048::Case2048(int _i, int _j,bool empty2) :
		CaseGeneric(_i, _j),empty(empty2),valeur(0) {

	//std::cout << "appel constructeur Case2048 : "<<i<<" "<<j << std::endl;

}

Case2048::~Case2048() {
	std::cout<<"delete 2048 de "<<i<<" "<<j<<std::endl;
}

std::string Case2048::toString() const {
	if(empty){
		return std::string();
	}else{
		return std::to_string(valeur);
	}

}


void Case2048::Print(std::ostream& O) const {
	O << valeur << " ";
}


DoublePointer<Case2048>* Case2048::performFusion(Case2048 * case2,char direction) {

	if (typeid(*case2) == typeid(Case2048)) {
		//Case2048* v = dynamic_cast<Case2048*>(case2);

		if(direction=='l'){
			case2->valeur += this->valeur;
			case2->empty = false;
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

	}else{
		if(direction=='r'){
			//TODO
			std::cout<<"probleme performFusion"<<std::endl;
			return nullptr;
		}else{
			return case2->performFusion(this,'r');
		}

	}

}


char Case2048::testFusion(Case2048 * case2,bool firstCall) {

	if (typeid(*case2) == typeid(Case2048)) {
		Case2048* v = dynamic_cast<Case2048*>(case2);

		if (this->empty && v->empty) {
			return ' ';
		}
		if (v->empty || (this->valeur == v->valeur)) {
			return 'l';
		} else {
			return ' ';
		}
	} else {
		std::cout << "un inconnu 2048 dans 2048" << std::endl;
		if(firstCall && case2->testFusion(this,false)=='l'){
			return 'r';
		}else{
			return ' ';
		}
	}
}

/*
 * Case2048Operator.cpp
 *
 *  Created on: 1 déc. 2016
 *      Author: raphael
 */

#include "Case2048Operator.hpp"

Case2048Operator::Case2048Operator(int _i, int _j,char _oper) :
		oper(_oper) ,Case2048(_i, _j)  {
	//std::cout << "appel constructeur Case2048 : "<<i<<" "<<j << std::endl;
}

Case2048Operator::~Case2048Operator() {
	//std::cout<<"delete 2048 OPERATOR de "<<i<<" "<<j<<std::endl;
}


void Case2048Operator::Print(std::ostream& O) const {
	O <<this->oper<< " ";
}

std::string Case2048Operator::toString() const {
	if(empty){
		return std::string();
	}else{
		string s(1, oper);

		return std::string("|")+s+std::to_string(valeur);
	}
}

char Case2048Operator::testFusion(Case2048 * case2, bool firstCall) {

	if (typeid(*case2) == typeid(Case2048) || (typeid(*case2) == typeid(Case2048Negative))) {
		if (this->empty && case2->empty) {
				return ' ';
			}
		return 'l';
	}
	else {
		//std::cout << "un inconnu 2048 dans 2048Operator" << std::endl;
		if (firstCall && case2->testFusion(this, false) == 'l') {
			return 'r';
		} else {
			return ' ';
		}
	}
}

DoublePointer<Case2048>* Case2048Operator::performFusion(Case2048 *case2,char direction) {

	Case2048 * caseVide = new Case2048(this->i, this->j);


	if (case2->empty) {
		Case2048 * caseThis = new Case2048Operator(case2->i,case2->j,this->oper);
		caseThis->valeur=this->valeur;
		caseThis->empty=false;
		//cout << "OPERATOR se deplace sur une empty" << endl;
		return new DoublePointer<Case2048>(caseVide, caseThis);
	}

	if (typeid(*case2) == typeid(Case2048) || (typeid(*case2) == typeid(Case2048Negative))) {

		int valutmp=case2->valeur;

		switch (oper)
		{
		case '+':
			valutmp = valutmp + this->valeur;
			break;
		case '-':
			valutmp = valutmp - this->valeur;
			break;
		case '*':
			valutmp = valutmp * this->valeur;
			break;
		case '/':
			valutmp = valutmp / this->valeur;
			break;
		}
		Case2048 * caseResult;
		if(valutmp==0){
			caseResult=new Case2048(case2->i, case2->j);
		}else if(valutmp<0){
			caseResult=new Case2048Negative(case2->i, case2->j);
			caseResult->valeur=valutmp;
			caseResult->empty=false;
		}else{
			caseResult= new Case2048(case2->i, case2->j);
			caseResult->valeur=valutmp;
			caseResult->empty=false;
		}

		//cout << "operator FUSIONNE" << endl;
		return new DoublePointer<Case2048>(caseVide, caseResult);

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

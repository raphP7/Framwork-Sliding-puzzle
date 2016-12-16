/*
 * Case2048.hpp
 *
 *  Created on: 1 déc. 2016
 *      Author: raphael
 */

#ifndef CASE2048_HPP_
#define CASE2048_HPP_
#include "../CaseGeneric.hpp"
#include <typeinfo>

using namespace std;
#include <iostream>

class Case2048: public CaseGeneric {

public:
	const Case2048 operator+(const Case2048 &other) const;

	int valeur;
	virtual void Print(std::ostream& O) const;
	Case2048(int _i, int _j,bool empty=true);
	virtual ~Case2048();

	/**
	 * Renvoi true si les deux cases peuvent FUSIONNER
	 */

	virtual bool FusionWith(CaseGeneric & case2, bool justTest) {

		if (typeid(case2) == typeid(Case2048)) {
			Case2048* v = dynamic_cast<Case2048*>(&case2);

			bool result = isFusionableWith(*v);

			if (justTest) {
				return result;
			} else {
				this->operator >(*v);
				return result;
			}

		} else {
			cout << "un inconnu 2048" << endl;
			return case2.FusionWith(*this, justTest);
		}
	}

	virtual CaseGeneric* ApplyFusion(CaseGeneric * case2) {
		if (typeid(&case2) == typeid(Case2048)) {
			Case2048* v = dynamic_cast<Case2048*>(case2);
			this->operator >(*v);
		}
		return nullptr;
	}


	virtual bool isFusionableWith( Case2048& case2){
			//cout<<"DANS D2048 == avec "<<this->valeur<<"vide ?"<<this->empty<<" et "<<case2.valeur<<"vide ?"<<case2.empty<<endl;

			if (this->empty && case2.empty ) {
				return false;
			}
			if (case2.empty || (this->valeur == case2.valeur)) {
				return true;
			} else {
				return false;
			}
	 }

	virtual bool operator>(Case2048& case2){
		if(isFusionableWith(case2)){
			//cout<<"DANS D2048 >  avec "<<this->valeur<<" et "<<case2.valeur<<endl;
			case2.valeur+=this->valeur;
			case2.empty=false;
			this->valeur=0;
			this->empty=true;
			return true;
		}else{
			return false;
		}
	}
};

#endif /* CASE2048_HPP_ */

/*
 * Case2048.hpp
 *
 *  Created on: 1 déc. 2016
 *      Author: raphael
 */

#ifndef CASE2048_HPP_
#define CASE2048_HPP_
#include "../CaseGeneric.hpp"

using namespace std;
#include <iostream>

class Case2048: public CaseGeneric {

public:
	int valeur;
	virtual void Print(std::ostream& O) const;
	Case2048(int _i, int _j);
	~Case2048();

	/**
	 * Renvoi true si les deux cases peuvent FUSIONNER
	 */

	virtual bool operator==( CaseGeneric& case2){
		return false;
	}
	virtual bool operator==( Case2048& case2){
			cout<<"DANS D2048 == avec "<<this->valeur<<" et "<<case2.valeur<<endl;

			if (this->valeur == 0 && case2.valeur == 0) {
				return false;
			}
			if (case2.valeur == 0 || (this->valeur == case2.valeur)) {
				return true;
			} else {
				return false;
			}
	 }

	virtual bool operator>( Case2048& case2){
		if(*this==case2){
			cout<<"DANS D2048 >  avec "<<this->valeur<<" et "<<case2.valeur<<endl;
			case2.valeur+=this->valeur;
			case2.empty=false;
			this->valeur=0;
			this->empty=true;
			return true;
		}else{
			return false;
		}
	}
	virtual bool operator<( Case2048& case2){
		return *this>case2;
	}


};

#endif /* CASE2048_HPP_ */

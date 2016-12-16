/*
 * Case2048Destroy.hpp
 *
 *  Created on: 1 déc. 2016
 *      Author: raphael
 */

#ifndef CASE2048DESTROY_HPP_
#define CASE2048DESTROY_HPP_
#include "../Case2048.hpp"
#include "unistd.h"

using namespace std;
#include <iostream>

class Case2048Destroy: public Case2048 {

private:


public:
	virtual void Print(std::ostream& O) const;
	Case2048Destroy(int _i, int _j);
	virtual ~Case2048Destroy();

	virtual bool FusionWith(CaseGeneric & case2,bool justTest) {

		if (typeid(case2) == typeid(Case2048Destroy)
				|| typeid(case2) == typeid(Case2048)) {
			if(justTest){
				return true;
			} else {
				if (Case2048* v = dynamic_cast<Case2048*>(&case2)) {
					v->valeur = 0;
					v->empty = true;
					this->valeur = 0;
					this->empty = true;
				}
			}
		} else {
			cout << "un inconnu 2048" << endl;
			return case2.FusionWith(*this,justTest);
		}
	}

	virtual CaseGeneric* ApplyFusion(CaseGeneric *case2) {
		if (typeid(case2) == typeid(Case2048Destroy)
				|| typeid(case2) == typeid(Case2048)) {

			CaseGeneric * tmp =case2;
			case2=new Case2048(case2->i,case2->j);
			delete tmp;
			return new Case2048(this->i,this->j);
		}else{
			return nullptr;
		}
	}

	virtual bool operator>(Case2048& case2) {

		cout << "DANS DESTROY > avec " << this->valeur << " et " << case2.valeur<< endl;
		case2.valeur = 0;
		case2.empty = true;
		this->valeur = 0;
		this->empty = true;
		return true;

		return false;
	}
	virtual bool operator<(Case2048& case2) {
		return *this>case2;
	}

};

#endif /* CASE2048DESTROY_HPP_ */

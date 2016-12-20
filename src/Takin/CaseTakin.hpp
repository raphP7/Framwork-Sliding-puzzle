/*
 * CaseTakin.hpp
 *
 *  Created on: 1 déc. 2016
 *      Author: raphael
 */

#ifndef CASETakin_HPP_
#define CASETakin_HPP_
#include "../CaseGeneric.hpp"

using namespace std;
#include <iostream>

template<class T>class CaseTakin: public CaseGeneric
{

public:
	T valeur;
	bool EmptyCase;

	CaseTakin(int _i, int _j);

	virtual ~CaseTakin();

	virtual char testFusion(CaseGeneric * case2){
		return false;
	}
	virtual CaseGeneric* performFusion(CaseGeneric * case2,char direction){
			return nullptr;
	}

	virtual std::string toString() const {
		stringstream ss;
		string s;
		ss << valeur;
		ss >> s;
		return s;
	}

	virtual void Print(std::ostream& O) const {
		O << valeur << " ";
	}

    bool getEmptyCase(){
    	return EmptyCase;
    }

	friend bool operator<(CaseTakin<T> const &a, CaseTakin<T> const& b) {
		if (a.EmptyCase || b.EmptyCase) {
			return true;
		} else {
			return a.valeur < b.valeur;
		}
	}
};

#include "CaseTakin.tpp"

#endif /* CASETakin_HPP_ */

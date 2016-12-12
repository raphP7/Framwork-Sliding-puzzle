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
	friend bool operator==(Case2048 const& case1, Case2048 const& case2) {

		if (case1.valeur == 0 && case2.valeur == 0) {
			return false;
		}
		if (case2.valeur == 0 || (case1.valeur == case2.valeur)) {
			return true;
		} else {
			return false;
		}

	}

	/*
	 * deplace case1 sur case2 et les fusionne sur case2
	 */
	friend bool operator>(Case2048 & case1, Case2048 & case2)
	{
		case2.valeur+=case1.valeur;
		case1.valeur=0;

		return true;
	}
};

#endif /* CASE2048_HPP_ */

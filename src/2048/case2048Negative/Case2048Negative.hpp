/*
 * Case2048Negative.hpp
 *
 *  Created on: 1 déc. 2016
 *      Author: raphael
 */

#ifndef CASE2048NEGATIVE_HPP_
#define CASE2048NEGATIVE_HPP_
#include "../CaseGeneric.hpp"

using namespace std;
#include <iostream>

class Case2048Negative: public Case2048 {

public:
	int valeur;
	virtual void Print(std::ostream& O) const;
	Case2048Negative(int _i, int _j);
	~Case2048Negative();

};

#endif /* CASE2048NEGATIVE_HPP_ */

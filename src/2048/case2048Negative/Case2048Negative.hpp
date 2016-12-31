/*
 * Case2048Negative.hpp
 *
 *  Created on: 1 déc. 2016
 *      Author: raphael
 */

#ifndef CASE2048NEGATIVE_HPP_
#define CASE2048NEGATIVE_HPP_
#include "../Case2048.hpp"

using namespace std;
#include <iostream>

class Case2048Negative: public Case2048 {

public:
	Case2048Negative(int _i, int _j);
	virtual ~Case2048Negative();
	std::string toString() const;
	virtual void Print(std::ostream& O) const;
	virtual char testFusion(Case2048 * case2,bool firstCall);
	virtual DoublePointer<Case2048>* performFusion(Case2048 *case2,char direction);
};

#endif /* CASE2048NEGATIVE_HPP_ */

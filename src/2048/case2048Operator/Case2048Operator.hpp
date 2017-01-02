/*
 * Case2048Operator.hpp
 *
 *  Created on: 1 déc. 2016
 *      Author: raphael
 */

#ifndef CASE2048OPERATOR_HPP_
#define CASE2048OPERATOR_HPP_
#include "../Case2048.hpp"
#include "../case2048Negative/Case2048Negative.hpp"
using namespace std;
#include <iostream>

class Case2048Operator: public Case2048 {

public:
	char oper;
	Case2048Operator(int _i, int _j,char _oper);
	virtual ~Case2048Operator();
	std::string toString() const;
	virtual void Print(std::ostream& O) const;
	virtual char testFusion(Case2048 * case2,bool firstCall);
	virtual DoublePointer<Case2048>* performFusion(Case2048 *case2,char direction);
};

#endif /* CASE2048OPERATOR_HPP_ */

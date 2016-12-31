/*
 * Case2048.hpp
 *
 *  Created on: 1 déc. 2016
 *      Author: raphael
 */

#ifndef CASE2048_HPP_
#define CASE2048_HPP_
#include "../CaseGeneric.hpp"
#include "../DoublePointer.hpp"
#include <typeinfo>

class Case2048: public CaseGeneric {

public:
	bool empty;
	int valeur;

	Case2048(int _i, int _j,bool empty=true);
	virtual ~Case2048();
	virtual void Print(std::ostream& O) const;

	virtual std::string toString() const;

	virtual char testFusion(Case2048 * case2,bool firstCall);
	virtual DoublePointer<Case2048>* performFusion(Case2048 * case2,char direction);

};

#endif /* CASE2048_HPP_ */

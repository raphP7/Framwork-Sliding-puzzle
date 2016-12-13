/*
 * CaseGeneric.hpp
 *
 *  Created on: 1 déc. 2016
 *      Author: raphael
 */

#ifndef CASEGENERIC_HPP_
#define CASEGENERIC_HPP_

#include <iostream>
#include <vector>

class CaseGeneric {
public:
	int i;
	int j;
	bool empty;
	friend std::ostream& operator <<(std::ostream& O, const CaseGeneric& B);
	CaseGeneric(int _i, int _j,bool _empty);
	virtual void Print(std::ostream& O) const;
	virtual ~CaseGeneric();
};

#endif /* CASEGENERIC_HPP_ */

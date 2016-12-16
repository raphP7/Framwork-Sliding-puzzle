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

	CaseGeneric(int _i, int _j,bool _empty);
	virtual ~CaseGeneric();
	virtual void Print(std::ostream& O) const = 0;

	friend std::ostream& operator <<(std::ostream& O, const CaseGeneric& B);

	virtual bool FusionWith(CaseGeneric & case2,bool justTest)=0;


};

#endif /* CASEGENERIC_HPP_ */

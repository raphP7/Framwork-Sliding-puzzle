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
#include <string>


class CaseGeneric {

public:
	//only for debug
	int i;
	int j;


	CaseGeneric(int _i, int _j);
	virtual ~CaseGeneric();
	//virtual char testFusion(CaseGeneric * case2)=0;
	//virtual CaseGeneric* performFusion(CaseGeneric * case2,char direction)=0;
	virtual std::string toString() const =0;

protected:
	CaseGeneric(CaseGeneric const &) = delete;
	void operator=(CaseGeneric const &x) = delete;
	virtual void Print(std::ostream& O) const = 0;

	friend std::ostream& operator <<(std::ostream& O, const CaseGeneric& B);

};

#endif /* CASEGENERIC_HPP_ */

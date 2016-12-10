/*
 * Case2048.hpp
 *
 *  Created on: 1 déc. 2016
 *      Author: raphael
 */

#ifndef CASE2048_HPP_
#define CASE2048_HPP_
#include "../CaseGeneric.hpp"
#include "../FramPlateauLand.hpp"

using namespace std;
#include <iostream>


class Case2048 :public CaseGeneric{

public:
	int valeur;
	 virtual void Print(std::ostream& O) const
	    {
	        O <<valeur<<" ";
	    }
	Case2048(int _i,int _j);

};



#endif /* CASE2048_HPP_ */

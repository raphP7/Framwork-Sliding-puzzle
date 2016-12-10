/*
 * CaseGeneric.cpp
 *
 *  Created on: 1 déc. 2016
 *      Author: raphael
 */

#include "CaseGeneric.hpp"
#include "FramPlateauLand.hpp"

CaseGeneric::CaseGeneric(int _i, int _j) :
		i(_i), j(_j) {

	//std::cout << "appel constructeur CaseGeneric : "<<i<<" "<<j << std::endl;

}

CaseGeneric::~CaseGeneric(){

}


std::ostream& operator << (std::ostream& O, const CaseGeneric& B)
{
    B.Print(O);
    return O;
}

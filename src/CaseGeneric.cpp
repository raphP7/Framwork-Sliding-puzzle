/*
 * CaseGeneric.cpp
 *
 *  Created on: 1 déc. 2016
 *      Author: raphael
 */

#include "CaseGeneric.hpp"
#include "FramPlateauLand.hpp"

CaseGeneric::CaseGeneric(int _i, int _j,bool _empty) :
		i(_i), j(_j),empty(_empty) {

	//std::cout << "appel constructeur CaseGeneric : "<<i<<" "<<j << std::endl;

}

CaseGeneric::~CaseGeneric() {
	//std::cout<<"delete de "<<i<<" "<<j<<std::endl;
}

void CaseGeneric::Print(std::ostream& O) const {
	O << "?";
}

std::ostream& operator <<(std::ostream& O, const CaseGeneric& B) {
	B.Print(O);
	return O;
}

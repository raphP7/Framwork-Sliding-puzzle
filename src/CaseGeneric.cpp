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

	std::cout << "appel constructeur CaseGeneric : "<<i<<" "<<j << std::endl;

}


int main() {

	FramPlateauLand * fram;
	fram= new FramPlateauLand(4,8);

}

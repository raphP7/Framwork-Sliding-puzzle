/*
 * Case2048.cpp
 *
 *  Created on: 1 déc. 2016
 *      Author: raphael
 */

#include "Case2048.hpp"

Case2048::Case2048(int _i, int _j) :
		CaseGeneric(_i, _j,true), valeur(0) {

	//std::cout << "appel constructeur Case2048 : "<<i<<" "<<j << std::endl;

}

Case2048::~Case2048() {
	//std::cout<<"delete 2048 de "<<i<<" "<<j<<std::endl;
}

void Case2048::Print(std::ostream& O) const {
	O << valeur << " ";
}


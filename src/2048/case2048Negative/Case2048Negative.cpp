/*
 * Case2048Negative.cpp
 *
 *  Created on: 1 déc. 2016
 *      Author: raphael
 */

#include "Case2048Negative.hpp"

Case2048Negative::Case2048Negative(int _i, int _j) :
		Case2048(_i, _j), valeur(0) {
	//std::cout << "appel constructeur Case2048 : "<<i<<" "<<j << std::endl;
}

Case2048Negative::~Case2048Negative() {
	//std::cout<<"delete 2048 de "<<i<<" "<<j<<std::endl;
}

void Case2048Negative::Print(std::ostream& O) const {
	O << valeur << " ";
}
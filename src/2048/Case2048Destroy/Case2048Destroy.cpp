/*
 * Case2048Destroy.cpp
 *
 *  Created on: 1 déc. 2016
 *      Author: raphael
 */

#include "Case2048Destroy.hpp"

Case2048Destroy::Case2048Destroy(int _i, int _j) :
	Case2048(_i, _j) {

	//std::cout << "appel constructeur Case2048 : "<<i<<" "<<j << std::endl;

}

Case2048Destroy::~Case2048Destroy() {
	//std::cout<<"delete 2048 de "<<i<<" "<<j<<std::endl;
}

void Case2048Destroy::Print(std::ostream& O) const {
	O << "#" << " ";
}

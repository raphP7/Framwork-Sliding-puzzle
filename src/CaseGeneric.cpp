/*
 * CaseGeneric.cpp
 *
 *  Created on: 1 déc. 2016
 *      Author: raphael
 */

#include "CaseGeneric.hpp"

CaseGeneric::CaseGeneric(int _i, int _j) :
		i(_i), j(_j) {

	std::cout << "appel constructeur "<<i<<" "<<j << std::endl;

}


int main() {

	std::vector<std::vector<CaseGeneric> > tab;

	for (int i = 0; i < 5; i++) {
		std::vector<CaseGeneric> tabb;
		tab.push_back(tabb);

		for (int j = 0; j < 5; j++) {
			CaseGeneric *a = new CaseGeneric(i,j);
			tabb.push_back(*a);

		}
	}

	std::cout << "test" << std::endl;
}

/*
 * FramPlateauLand.cpp
 *
 *  Created on: 1 déc. 2016
 *      Author: raphael
 */

#include"FramPlateauLand.hpp"

FramPlateauLand::FramPlateauLand(int sizeI, int sizeJ){

	for (int i = 0; i < sizeI; i++) {
		std::vector<CaseGeneric> tabb;
		this->plateau.push_back(tabb);

		for (int j = 0; j < sizeJ; j++) {
			CaseGeneric *a = new CaseGeneric(i,j);
			tabb.push_back(*a);

		}
	}
}
FramPlateauLand::FramPlateauLand(vector<vector<CaseGeneric> >_pla):plateau(_pla){

}

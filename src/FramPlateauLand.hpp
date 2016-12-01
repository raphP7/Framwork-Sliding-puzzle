/*
 * FramPlateauLand.hpp
 *
 *  Created on: 1 déc. 2016
 *      Author: raphael
 */

#ifndef FRAMPLATEAULAND_HPP_
#define FRAMPLATEAULAND_HPP_
#include "CaseGeneric.hpp"
using namespace std;

class FramPlateauLand {
public:
	FramPlateauLand(int sizeI, int sizeJ);
	FramPlateauLand(vector<vector<CaseGeneric> > _pla);
	vector<vector<CaseGeneric> > plateau;

};

#endif /* FRAMPLATEAULAND_HPP_ */

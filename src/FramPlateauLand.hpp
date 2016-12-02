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
template<class T> class FramPlateauLand {
public:
	vector<vector<T> > plateau;
	FramPlateauLand(int sizeI, int sizeJ);
	FramPlateauLand(vector<vector<T> > _pla);


};

#endif /* FRAMPLATEAULAND_HPP_ */

/*
 * Plateau2048.hpp
 *
 *  Created on: 1 déc. 2016
 *      Author: raphael
 */

#ifndef PLATEAU2048_HPP_
#define PLATEAU2048_HPP_
#include "Case2048.hpp"
#include "../FramPlateauLand.hpp"
#include <random>
#include <sstream>

static vector<int> DEFAULT_VECTOR;
class Plateau2048: public FramPlateauLand<Case2048> {


public:
	bool recursive;
	Plateau2048(int sizeI, int sizeJ);
	virtual void initPlateau(vector<int> contenuJeu = DEFAULT_VECTOR);

private:
	virtual bool isFusionnable(Case2048 * case1, Case2048 * case2)const;
	virtual bool isCaseEmpty(Case2048 const* case1);
	virtual void applyFusion(Case2048 * case1, Case2048 * case2);

	virtual bool performAction(int xArriv=0,int yArriv=0,char direction=0);

	virtual void addNewValue();
	virtual bool gameEnd();

};

#endif /* PLATEAU2048_HPP_ */

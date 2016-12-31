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

static vector<int> DEFAULT_VECTOR;

class Plateau2048: public FramPlateauLand<Case2048> {

public:

	Plateau2048(int sizeI, int sizeJ);
	virtual void initPlateau(vector<int> contenuJeu = DEFAULT_VECTOR);

private:
	virtual bool performAction(int xArriv=0,int yArriv=0,char direction=0);
	virtual void afterAction(Case2048 * newCase=nullptr);
	virtual bool isGameEnd();

	virtual char isFusionnable(Case2048 * case1, Case2048 * case2)const;
	virtual bool isCaseEmpty(Case2048 const* case1);
	virtual DoublePointer<Case2048>* applyFusion(Case2048 * case1, Case2048 * case2,char direction);

};

#endif /* PLATEAU2048_HPP_ */

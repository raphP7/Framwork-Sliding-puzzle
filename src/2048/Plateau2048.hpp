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
	Plateau2048(int sizeI, int sizeJ);
	bool recursive;

	virtual bool isFusionnable(Case2048 * case1, Case2048 * case2)const;
	virtual bool isCaseEmpty(Case2048 const* case1);
	virtual void applyFusion(Case2048 * case1, Case2048 * case2);

	virtual void performAction();

	virtual void addNewValue();

	virtual bool gameEnd();
	virtual void initPlateau(vector<int> contenuJeu = DEFAULT_VECTOR) {

		iterDoubleVector<Case2048> monIter(this->plateau);

		//for good random
		random_device seeder;
		mt19937 engine(seeder());
		uniform_int_distribution<int> dist(0, monIter.getSizeMax() - 1);
		int randomPosition = dist(engine);

		int i = randomPosition / plateau.size();
		int j = randomPosition % plateau.size();

		plateau[i][j]->valeur = 2;
		plateau[i][j]->empty = false;

	}

};

#endif /* PLATEAU2048_HPP_ */

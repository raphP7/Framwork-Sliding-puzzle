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


class Plateau2048: public FramPlateauLand<Case2048> {
public:
	Plateau2048(int sizeI, int sizeJ);
};

#endif /* PLATEAU2048_HPP_ */

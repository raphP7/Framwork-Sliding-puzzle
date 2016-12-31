/*
 * Plateau2048Plugin.hpp
 *
 *  Created on: 1 déc. 2016
 *      Author: raphael
 */

#ifndef PLATEAU2048PLUGIN_HPP_
#define PLATEAU2048PLUGIN_HPP_
#include "Case2048.hpp"
#include "Case2048Destroy/Case2048Destroy.hpp"
#include "case2048Negative/Case2048Negative.hpp"
#include "Plateau2048.hpp"

class Plateau2048Plugin:public Plateau2048{

public:
	Plateau2048Plugin(int sizeI, int sizeJ);
private:
	virtual void afterAction(Case2048 * newCase=nullptr);
};

#endif /* PLATEAU2048PLUGIN_HPP_ */

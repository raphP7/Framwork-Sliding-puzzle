/*
 * Case2048Destroy.hpp
 *
 *  Created on: 1 déc. 2016
 *      Author: raphael
 */

#ifndef CASE2048DESTROY_HPP_
#define CASE2048DESTROY_HPP_
#include "../Case2048.hpp"

using namespace std;
#include <iostream>

class Case2048Destroy: public Case2048 {

public:
	virtual void Print(std::ostream& O) const;
	Case2048Destroy(int _i, int _j);
	~Case2048Destroy();


	friend bool operator>(Case2048 & case1, Case2048Destroy & case2)
	{
		case2.valeur=0;
		case1.valeur=0;
	    return true;
	}

	friend bool operator>(Case2048Destroy & case1, Case2048 & case2)
	{

	    return true;
	}

	friend bool operator==(Case2048 const& case1, Case2048Destroy const& case2) {
		return true;

	}

	friend bool operator==(Case2048Destroy const& case1, Case2048 const& case2) {
		return true;
	}

};




#endif /* CASE2048DESTROY_HPP_ */

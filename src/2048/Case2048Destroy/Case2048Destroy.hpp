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

private:


public:
	virtual void Print(std::ostream& O) const;
	Case2048Destroy(int _i, int _j);
	~Case2048Destroy();

	virtual bool operator==( Case2048& case2){
		cout<<"DANS DESTROY == avec "<<this->valeur<<" et "<<case2.valeur<<endl;
		return true;
	 }

	virtual bool operator>(Case2048& case2) {
		if (*this == case2) {
			cout<<"DANS DESTROY > avec "<<this->valeur<<" et "<<case2.valeur<<endl;
			case2.valeur = 0;
			this->valeur = 0;
			return true;

		}
		return false;
	}
	virtual bool operator<(Case2048& case2) {
		return *this>case2;
	}

};

#endif /* CASE2048DESTROY_HPP_ */

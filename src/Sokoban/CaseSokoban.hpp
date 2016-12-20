/*
 * CaseSokoban.hpp
 *
 *  Created on: 1 déc. 2016
 *      Author: raphael
 */

#ifndef CASESokoban_HPP_
#define CASESokoban_HPP_
#include "../CaseGeneric.hpp"

class CaseSokoban: public CaseGeneric
{

public:
	char valeur;

	virtual char testFusion(CaseGeneric * case2){
		return false;
	}

	virtual CaseGeneric* performFusion(CaseGeneric * case2,char direction){
		return nullptr;
	}

    virtual void Print(std::ostream& O) const
    {
        O << valeur << " ";
    }

    virtual std::string toString() const{
    	return std::string(1,valeur);
    }

    CaseSokoban(int _i, int _j) :
        CaseGeneric(_i, _j), valeur(0)
    {
        //std::cout << "appel constructeur CaseSokoban : "<<i<<" "<<j << std::endl;

    }
    virtual ~CaseSokoban(){}

	char getValeur() {
		return valeur;
	}
	char setValeur(char val2) {
		return valeur=val2;
	}
};


#endif /* CASESokoban_HPP_ */

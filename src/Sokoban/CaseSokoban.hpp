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

	virtual bool FusionWith(CaseGeneric & case2,bool justTest){
		return false;
	}

    virtual void Print(std::ostream& O) const
    {
        O << valeur << " ";
    }

    CaseSokoban(int _i, int _j) :
        CaseGeneric(_i, _j,false), valeur(0)
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

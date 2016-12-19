/*
 * CaseSokoban.hpp
 *
 *  Created on: 1 déc. 2016
 *      Author: raphael
 */

#ifndef CASESokoban_HPP_
#define CASESokoban_HPP_
#include "../CaseGeneric.hpp"

using namespace std;
#include <iostream>

template<class T>class CaseSokoban: public CaseGeneric
{

public:
	T valeur;
	bool EmptyCase;

	virtual bool FusionWith(CaseGeneric & case2,bool justTest){
		return true;
	}

	virtual bool operator==(CaseGeneric& case2){
		return false;
	}

    virtual void Print(std::ostream& O) const
    {
        O << valeur << " ";
    }
    CaseSokoban(int _i, int _j) :
        CaseGeneric(_i, _j,false), valeur(0),EmptyCase(false)
    {
        //std::cout << "appel constructeur CaseSokoban : "<<i<<" "<<j << std::endl;

    }
    ~CaseSokoban()
    {
        //std::cout<<"delete Sokoban de "<<i<<" "<<j<<std::endl;
    }

    bool getEmptyCase(){
    	return EmptyCase;
    }

    friend bool operator<(CaseSokoban<T> const &a, CaseSokoban<T> const& b){
    	if(a.EmptyCase || b.EmptyCase){
    			return true;
    		}else{
    			return a.valeur<b.valeur;
    		}
    }
};


#endif /* CASESokoban_HPP_ */

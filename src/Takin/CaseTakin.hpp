/*
 * CaseTakin.hpp
 *
 *  Created on: 1 déc. 2016
 *      Author: raphael
 */

#ifndef CASETakin_HPP_
#define CASETakin_HPP_
#include "../CaseGeneric.hpp"

using namespace std;
#include <iostream>

template<class T>class CaseTakin: public CaseGeneric
{

public:
	T valeur;
	bool EmptyCase;

	virtual bool operator==( CaseGeneric& case2){
			return false;
		}

    virtual void Print(std::ostream& O) const
    {
        O << valeur << " ";
    }
    CaseTakin(int _i, int _j) :
        CaseGeneric(_i, _j,false), valeur(0),EmptyCase(false)
    {
        //std::cout << "appel constructeur CaseTakin : "<<i<<" "<<j << std::endl;

    }
    ~CaseTakin()
    {
        //std::cout<<"delete Takin de "<<i<<" "<<j<<std::endl;
    }

    bool getEmptyCase(){
    	return EmptyCase;
    }

    friend bool operator<(CaseTakin<T> const &a, CaseTakin<T> const& b){
    	if(a.EmptyCase || b.EmptyCase){
    			return true;
    		}else{
    			return a.valeur<b.valeur;
    		}
    }
};


#endif /* CASETakin_HPP_ */

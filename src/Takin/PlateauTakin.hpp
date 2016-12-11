/*
 * PlateauTakin.hpp
 *
 *  Created on: 1 déc. 2016
 *      Author: raphael
 */

#ifndef PLATEAUTakin_HPP_
#define PLATEAUTakin_HPP_
#include "CaseTakin.hpp"
#include "../FramPlateauLand.hpp"


template<class T>class PlateauTakin: public FramPlateauLand<CaseTakin <T> >
{
public:

    PlateauTakin(int sizeI, int sizeJ):FramPlateauLand<CaseTakin<T> >(sizeI, sizeJ)
    {

    }
    virtual void initPlateau(vector<T> contenuJeu){

        typename vector<T>::iterator col(contenuJeu.begin());

        iterDoubleVector< CaseTakin<T > > monIter(this->plateau);

        bool notFinish=1;
        while(monIter.hasnext() && notFinish){
            if(col != contenuJeu.end()){
                monIter.next()->valeur=*col;
                col++;
            }else{
                //TODO
                cout<<"pas assez d'elements !"<<endl;
                notFinish=0;
            }
        }

        if(col != contenuJeu.end()){
            //TODO
            cout<<"TROP d'elements !"<<endl;
        }
    }
};

#endif /* PLATEAUTakin_HPP_ */

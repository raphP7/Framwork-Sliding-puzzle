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

    virtual void performAction(){

        int *commande = new int[4];
        this->getInputFromConsole(commande,4,2);


        int i1=commande[0];
        int j1=commande[1];
        int i2=commande[2];
        int j2=commande[3];

        int sizeMaxI=this->plateau.size()-1;
        int sizeMaxJ=this->plateau[0].size()-1;
        if(i1<0 || j1<0 || i2<0 || j2<0 ||
            i1>sizeMaxI || i2>sizeMaxI || j1>sizeMaxJ || j2>sizeMaxJ ||
            ( i1==i2 && j1==j2)
            ){
            cout<<"valeur INCORRECT"<<endl;
        }else{

            this->doSwap(i1,j1,i2,j2);
        }

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

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
#include <random>
static vector<int> DEFAULT_VECTOR;

class Plateau2048: public FramPlateauLand<Case2048> {

public:
	Plateau2048(int sizeI, int sizeJ);

	virtual void performAction(){


	}

	virtual void initPlateau(vector<int> contenuJeu=DEFAULT_VECTOR){

        iterDoubleVector<Case2048> monIter(this->plateau);

        //for good random
        random_device seeder;
        mt19937 engine(seeder());
        uniform_int_distribution<int> dist(0, monIter.sizeMax-1);
        int randomPosition = dist(engine);

        cout<<"POSITION CHOIS "<<randomPosition<<"   size MAx :"<<monIter.sizeMax<<endl;
        int compteur=0;
        bool notFinish=1;
        while(monIter.hasnext() && notFinish){

            if(compteur==randomPosition){
                monIter.next()->valeur=2;
                notFinish=0;
            }else{
                monIter.next();
            }
            compteur++;
        }
	}
};

#endif /* PLATEAU2048_HPP_ */

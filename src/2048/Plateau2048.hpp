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
	bool recursive;

	virtual bool isFusionnable(Case2048* case1, Case2048* case2){

		cout<<"case "<<case1->i<<" "<<case1->j<<"  ET "<<case2->i<<" "<<case2->j<<endl;

		if(case1->valeur==0 && case2->valeur==0){
			return false;
		}

		if(case1->valeur==0 || (case1->valeur==case2->valeur)){
			return true;
		}else{
		return false;
		}
	}

	virtual bool isCaseEmpty(Case2048* case1){
		return case1->valeur==0;
	}


	virtual void applyFusion(Case2048* case1,Case2048* case2){
		case2->valeur+=case1->valeur;
		case1->valeur=0;

		cout<<"fusion de "<<case1->i<<" "<<case1->j<<" dans "<<case2->i<<" "<<case2->j<<endl;

	}

	virtual void performAction(){

		char *commande=new char();
		bool Notdone=true;
		while(Notdone){
			this->getInputDirectionFromConsole(commande);

			if(*commande=='i' || *commande=='j' || *commande=='k' || *commande=='l'){
				doDirectionalSWIPE(*commande,recursive);
				Notdone=false;
			}
			else{
				cout<<"BAD INPUT , i -> UP | j -> LEFT | k -> DOWN | l -> RIGHT"<<endl;
			}
		}
		delete commande;
		addNewValue();

	}

	virtual void addNewValue(){
		iterDoubleVector<Case2048> monIter(this->plateau);

		//list all the empty cases
		vector<Case2048*> vecFreeCase;
		Case2048 * tmp;
		while(monIter.hasnext()){
			tmp=monIter.next();
			if(tmp->valeur==0){
				vecFreeCase.push_back(tmp);
			}
		}
		int sizeMax=vecFreeCase.size();

		//select by random the case with a new value
		random_device seeder;
		mt19937 engine(seeder());
		uniform_int_distribution<int> dist(0, monIter.sizeMax-1);
		int randomPosition = dist(engine);


		//10 % chance of add a 4
		uniform_int_distribution<int> dist2(0,10);
		int random2or4 = dist2(engine);
		if(random2or4>8){
			vecFreeCase[randomPosition]->valeur=4;
		}else{
			vecFreeCase[randomPosition]->valeur=2;
		}

	}

	virtual bool gameEnd(){
		return false;
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

/*
 * Plateau2048Plugin.cpp
 *
 *  Created on: 1 déc. 2016
 *      Author: raphael
 */


#include "Plateau2048Plugin.hpp"

Plateau2048Plugin::Plateau2048Plugin(int sizeI, int sizeJ) :
	Plateau2048(sizeI, sizeJ) {
}

void Plateau2048Plugin::afterAction(){

	//cout<<"afterAction"<<endl;
	Case2048 * tmp;

	//select by random the case with a new value
	random_device seeder;
	mt19937 engine(seeder());
	//10 % chance of add a 4
	uniform_int_distribution<int> dist2(0, 10);
	int randomSelect = dist2(engine);

	int randomSelect2 = dist2(engine);

	int valeurSelect=2;

	if (randomSelect > 8) {
		valeurSelect = 4;
	}

	bool normalValue=false;

	if(randomSelect==0){
		tmp=new Case2048Destroy(0,0);
	}
	else if(randomSelect==1){
		tmp=new Case2048Negative(0,0);
		tmp->valeur=valeurSelect*(-1);
	}
	else if(randomSelect==2){


		if(randomSelect2<=2){
			tmp=new Case2048Operator(0,0,'*');
		}else if(randomSelect2<=4){
			tmp=new Case2048Operator(0,0,'/');
		}else if(randomSelect2<=6){
			tmp=new Case2048Operator(0,0,'+');
		}else{
			tmp=new Case2048Operator(0,0,'-');
		}

		tmp->valeur=valeurSelect;
	}
	else{
		tmp=new Case2048(0,0);
		tmp->valeur=valeurSelect;
	}

	tmp->empty=false;
	setRandomEmptyCase(tmp);
}


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

	cout<<"afterAction"<<endl;
	Case2048 * tmp;

	//select by random the case with a new value
	random_device seeder;
	mt19937 engine(seeder());
	//10 % chance of add a 4
	uniform_int_distribution<int> dist2(0, 10);
	int random2or4 = dist2(engine);

	int valeurSelect=2;

	if (random2or4 > 8) {
		valeurSelect = 4;
	}

	bool normalValue=false;

	if(random2or4==0){
		tmp=new Case2048Destroy(0,0);
	}
	else if(random2or4==1){
		tmp=new Case2048Negative(0,0);
		tmp->valeur=valeurSelect*(-1);
	}else{
		tmp=new Case2048(0,0);
		tmp->valeur=valeurSelect;
	}

	tmp->empty=false;
	setRandomEmptyCase(tmp);
}

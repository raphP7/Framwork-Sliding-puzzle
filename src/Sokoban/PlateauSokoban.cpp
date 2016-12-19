/*
 * PlateauSokoban.cpp
 *
 *  Created on: 1 déc. 2016
 *      Author: raphael
 */

#include"PlateauSokoban.hpp"


PlateauSokoban::PlateauSokoban(int sizeI, int sizeJ) :
		FramPlateauLand<CaseSokoban>(sizeI, sizeJ, true) {
}


PlateauSokoban::~PlateauSokoban() {
}
bool PlateauSokoban::gameEnd() {

	iterDoubleVector<CaseSokoban > monIter(this->plateau);

	CaseSokoban *tmpActual = monIter.next();

	if (tmpActual == nullptr) {
		cerr << "GameEnd with an empty plateau" << endl;
		return false;
	}

	//TODO
	while (monIter.hasnext()) {

		if (tmpActual->valeur == '.') {
			return false;
			//une case but est vide ( sans caisse dessus);
		}

		tmpActual = monIter.next();

	}
	return true;
}

void PlateauSokoban::initPlateau(vector<char> contenuJeu){

    	vector<char>::iterator iterContenuJeu(contenuJeu.begin());

    	int cmp=0;
    	int position =-1;

    	bool personnageFind=false;

    	while (iterContenuJeu!=contenuJeu.end()){
    		if(*iterContenuJeu=='@'){
    			if(personnageFind){
    				cerr<<"attention il y a 2 personnage !! en case "<<cmp<<endl;
    			}
    			position=cmp;
    			personnageFind=true;
    		}
    		cmp++;
    		iterContenuJeu++;
    	}

    	if(position==-1){
    		cout<<"Aucun personnage "<<endl;
    	}
    	PositionXPersonnage=position/PlateauSizeJ;

    	PositionYPersonnage=position%PlateauSizeJ;

    	cout<<"personnage en case "<<PositionXPersonnage<<" : "<<PositionYPersonnage<<endl;

    	this->applyInitPlateau(contenuJeu);
}

bool PlateauSokoban::performAction(int xArriv, int yArriv, char direction) {

	CaseSokoban * nextPersonnage = plateau[xArriv][yArriv];

		//a wall
	if (nextPersonnage->valeur == '#') {
		return false;

		//a box
	} else if (nextPersonnage->valeur == '$' || nextPersonnage->valeur == '*') {

		int xAfterCaisse = -1;
		int yAfterCaisse = -1;

		this->getArrival_from_Position_and_Direction(xArriv, yArriv, direction,
				&xAfterCaisse, &yAfterCaisse);

		CaseSokoban * FuturPositionCaisse = plateau[xAfterCaisse][yAfterCaisse];


		//an available case for a BOXE
		if (FuturPositionCaisse->valeur == ' ' || FuturPositionCaisse->valeur == '.') {

			if(nextPersonnage->valeur=='*'){
				nextPersonnage->valeur='.';
			}else{
				nextPersonnage->valeur=' ';
			}

			if(FuturPositionCaisse->valeur == '.'){
				FuturPositionCaisse->valeur='*';
			}else{
				FuturPositionCaisse->valeur='$';
			}

		}
		else {
			return false; // next to the box is a WALL
		}
	}

	CaseSokoban * oldCase = plateau[PositionXPersonnage][PositionYPersonnage];

	if(oldCase->valeur=='+'){
		oldCase->valeur='.';
	}else{
		oldCase->valeur=' ';
	}

	if (nextPersonnage->valeur== '.') {
		nextPersonnage->valeur = '+';
	}else{
		nextPersonnage->valeur='@';
	}

	this->PositionXPersonnage = xArriv;
	this->PositionYPersonnage = yArriv;
	return true;
}

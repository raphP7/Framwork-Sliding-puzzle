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
bool PlateauSokoban::isGameEnd() {

	iterDoubleVector<CaseSokoban > monIter(this->plateau);

	CaseSokoban *tmpActual = monIter.next();

	if (tmpActual == nullptr) {
		cerr << "GameEnd with an empty plateau" << endl;
		return false;
	}

	//TODO
	while (monIter.hasnext()) {

		if (tmpActual->getValeur() == '$') {
			return false;
			//une case but est vide ( sans caisse dessus);
		}


		tmpActual = monIter.next();

	}
	return true;
}


PlateauSokoban* PlateauSokoban::readFile(const char * nameFile) {


	if(nameFile==nullptr){
		return nullptr;
	}
	ifstream aFile(nameFile);
	std::size_t lines_count = 0;
	std::string line;
	int biggerSizeLine=0;
	while (std::getline(aFile, line)) {
		if(line.size()>biggerSizeLine){
			biggerSizeLine=line.size();
		}

		++lines_count;
	}

	std::cout<<"TAILLE PLATEAU "<<lines_count<<" et "<<biggerSizeLine<<std::endl;

	return nullptr;
}

void PlateauSokoban::initPlateau(vector<char> & contenuJeu){

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
	if (nextPersonnage->getValeur() == '#') {
		return false;

		//a box
	} else if (nextPersonnage->getValeur() == '$' || nextPersonnage->getValeur() == '*') {

		int xAfterCaisse = -1;
		int yAfterCaisse = -1;

		this->getArrival_from_Position_and_Direction(xArriv, yArriv, direction,
				&xAfterCaisse, &yAfterCaisse);

		CaseSokoban * FuturPositionCaisse = plateau[xAfterCaisse][yAfterCaisse];


		//an available case for a BOXE
		if (FuturPositionCaisse->getValeur() == ' ' || FuturPositionCaisse->getValeur() == '.') {

			if(nextPersonnage->getValeur()=='*'){
				nextPersonnage->setValeur('.');
			}else{
				nextPersonnage->setValeur(' ');
			}

			if(FuturPositionCaisse->getValeur() == '.'){
				FuturPositionCaisse->setValeur('*');
			}else{
				FuturPositionCaisse->setValeur('$');
			}

		}
		else {
			return false; // next to the box is a WALL
		}
	}

	CaseSokoban * oldCase = plateau[PositionXPersonnage][PositionYPersonnage];

	if(oldCase->getValeur()=='+'){
		oldCase->setValeur('.');
	}else{
		oldCase->setValeur(' ');
	}

	if (nextPersonnage->getValeur()== '.') {
		nextPersonnage->setValeur('+');
	}else{
		nextPersonnage->setValeur('@');
	}

	this->PositionXPersonnage = xArriv;
	this->PositionYPersonnage = yArriv;
	return true;
}

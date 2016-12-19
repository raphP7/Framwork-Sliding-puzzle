/*
 * PlateauSokoban.hpp
 *
 *  Created on: 1 déc. 2016
 *      Author: raphael
 */

#ifndef PLATEAUTsokoban_HPP_
#define PLATEAUTsokoban_HPP_
#include "CaseSokoban.hpp"
#include "../FramPlateauLand.hpp"

class PlateauSokoban: public FramPlateauLand<CaseSokoban>{

public:

    PlateauSokoban(int sizeI, int sizeJ):FramPlateauLand<CaseSokoban> (sizeI, sizeJ,true){}

    virtual ~PlateauSokoban(){}

    virtual void initPlateau(vector<char> contenuJeu){

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

private:


    virtual bool gameEnd();

    virtual bool performAction(int xArriv, int yArriv) {

		if(plateau[xArriv][yArriv]->valeur=='#'){
			return false;
		}
	}


};


#endif /* PLATEAUTsokoban_HPP_ */

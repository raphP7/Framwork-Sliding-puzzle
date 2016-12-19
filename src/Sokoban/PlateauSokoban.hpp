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

    PlateauSokoban(int sizeI, int sizeJ):FramPlateauLand<CaseSokoban> (sizeI, sizeJ), PositionXPersonnage(-1),PositionYPersonnage(-1){}

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

    int PositionXPersonnage;
    int PositionYPersonnage;

    virtual bool gameEnd();

    virtual void performAction(){

        int *commande = new int[4];
        this->getInputFromConsole(commande,4,2,"Choisissez X : ","Choisissez Y : ");

        int i1=commande[0];
        int j1=commande[1];
        int i2=commande[2];
        int j2=commande[3];

        int sizeMaxI=this->plateau.size()-1;
        int sizeMaxJ=this->plateau[0].size()-1;
        if(i1<0 || j1<0 || i2<0 || j2<0 ||
            i1>sizeMaxI || i2>sizeMaxI || j1>sizeMaxJ || j2>sizeMaxJ ||
            ( i1==i2 && j1==j2) || i1+1<i2 || i2+1<i1 || j1+1<j2 || j2+1<j1||
            i1>i2+1 || i2>i1+1 || j1>j2+1 || j2>j1+1


            //TODO interdire les mouvements diagonaux
            ){
            cerr<<"valeur INCORRECT ou Mouvement Interdit"<<endl;
        }


        else if(!(this->plateau[i1][j1]->getEmptyCase() || this->plateau[i2][j2]->getEmptyCase())){

            cerr<<"select the empty case"<<endl;

        }
        else{

            this->doSwap(i1,j1,i2,j2);
        }
        delete commande;
    }


};


#endif /* PLATEAUTsokoban_HPP_ */

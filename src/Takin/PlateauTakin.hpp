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

    PlateauTakin(int sizeI, int sizeJ):FramPlateauLand<CaseTakin<T> >(sizeI, sizeJ),
    		AlreadySetBlankCase(false),BlankCaseAtTheEnd(false){}

    virtual ~PlateauTakin(){}

    virtual void initPlateau(vector<T> contenuJeu){

    	this->applyInitPlateau(contenuJeu);

    }

    void setBlank(int i,int j){
    	if(!AlreadySetBlankCase){
    		this->plateau[i][j]->EmptyCase=true;
    		AlreadySetBlankCase=true;
    		this->PositionXPersonnage=i;
    		this->PositionYPersonnage=j;

    	}
    }
    void setBlankCaseAtTheEnd(){
    	BlankCaseAtTheEnd=true;
    }
private:

	bool AlreadySetBlankCase;
	bool BlankCaseAtTheEnd;

    virtual bool gameEnd(){

    	iterDoubleVector< CaseTakin<T > > monIter(this->plateau);
    	CaseTakin<T> *tmpBefore;
    	CaseTakin<T> *tmpActual;

    	if(monIter.hasnext()){
    		tmpBefore=monIter.next();
    	}
    	while(monIter.hasnext()){

    		tmpActual=monIter.next();

    		if(BlankCaseAtTheEnd){
				if(!monIter.hasnext()){
					//last
					if(tmpActual->EmptyCase){
						return true;
					}else{
						return false;
					}
				}
    		}

    		if(*tmpBefore<*tmpActual){
    			tmpBefore=tmpActual;
    		}else{
    			return false;
    		}
    	}
    	return true;

    }

	virtual void performAction() {

		bool moveNotDone=true;

		char *commande = new char();

		int xArriv = -1;
		int yArriv = -1;

		while(moveNotDone){
			if(this->modeJoeur){
				this->getInputDirectionFromConsole(commande);
			}else{
				*commande=this->getRandomDirection();
				cout<<"direction choisi : "<<*commande<<endl;
			}
			this->getPositionFromDirectionPersonnage(&xArriv, &yArriv, *commande);

			int sizeMaxI = this->plateau.size() - 1;
			int sizeMaxJ = this->plateau[0].size() - 1;

			if (xArriv < 0 || yArriv < 0 || xArriv > sizeMaxI
					|| yArriv > sizeMaxJ) {
				if(this->modeJoeur){
					cout << "valeur INCORRECT ou Mouvement Interdit\n" << endl;
				}
			} else {

				this->doSwap(xArriv, yArriv);

				this->PositionXPersonnage = xArriv;
				this->PositionYPersonnage = yArriv;
				moveNotDone=false;
			}
		}
		delete commande;
	}

};

#endif /* PLATEAUTakin_HPP_ */

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

        typename vector<T>::iterator iterContenuJeu(contenuJeu.begin());

        iterDoubleVector< CaseTakin<T > > monIter(this->plateau);

        bool notFinish=1;
        while(monIter.hasnext() && notFinish){
            if(iterContenuJeu != contenuJeu.end()){

                monIter.next()->valeur=*iterContenuJeu;

                iterContenuJeu++;
            }else{
                //TODO
                cout<<"pas assez d'elements !"<<endl;
                notFinish=0;
            }
        }

        if(iterContenuJeu != contenuJeu.end()){
            //TODO
            cout<<"TROP d'elements !"<<endl;
        }
    }

    void setBlank(int i,int j){
    	if(!AlreadySetBlankCase){
    		this->plateau[i][j]->EmptyCase=true;
    		AlreadySetBlankCase=true;
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

#endif /* PLATEAUTakin_HPP_ */

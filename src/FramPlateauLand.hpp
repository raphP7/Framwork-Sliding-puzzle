/*
 * FramPlateauLand.hpp
 *
 *  Created on: 1 déc. 2016
 *      Author: raphael
 */

#ifndef FRAMPLATEAULAND_HPP_
#define FRAMPLATEAULAND_HPP_
#include "CaseGeneric.hpp"
#include <vector>
#include <sstream>
#include <string>
#include <random>

using namespace std;


template<class T> class iterDoubleVector{
    public:

        iterDoubleVector(vector<vector<T * > >  &arg ):vec2D(arg),currentIndex(-1){
            this->sizeI=vec2D.size();
            this->sizeJ=vec2D[0].size();
            this->sizeMax=(this->sizeI)*(this->sizeJ);
        }

        bool hasnext(){
            return currentIndex<sizeMax-1;
        }

        T* next(){
            currentIndex++;
            int i=currentIndex/sizeJ;
            int j=currentIndex%sizeJ;
            return this->vec2D[i][j];
        }

        int getSizeMax(){
        	return sizeMax;
        }
    private:
        const vector<vector<T*> > &vec2D;
        int currentIndex;
        int sizeI;
        int sizeJ;
        int sizeMax;


};

template<class T> class FramPlateauLand
{

protected:
	int PlateauSizeI;
	int PlateauSizeJ;
	vector<vector<T*> >plateau;
	int speedGame;
	bool modeJoeur;// si TRUE -> utlisateur | FALSE -> automatique

public:
    void startGame();

    virtual bool gameEnd()=0;
    /*{
    	//TODO EXCEPTION
    	cerr<<"PAS BON"<<endl;
    	return false;
    }
*/
    virtual bool isFusionnable(T * case1,T * case2)const{
    	//TODO EXCEPTION
    	cerr<<"PAS BON isFusionnable"<<endl;
    	return false;
    }

    virtual bool isCaseEmpty(T const* case1){
    	//TODO EXCEPTION
    	cerr<<"PAS BON isCaseEmpty"<<endl;
    	return false;
    }
    virtual void applyFusion(T * case1,T * case2){
    	//TODO EXCEPTION
    	cerr<<"PAS BON applyFusion"<<endl;
    }

    virtual void performAction(){
    	//TODO EXCEPTION
        cerr<<"PAS BON performAction"<<endl;
    }

    virtual void initPlateau(vector<T> contenuJeu){
    	//TODO EXCEPTION
        cerr<<"PAS BON initPlateau"<<endl;
    }

    void doSwap(int i1,int j1,int i2,int j2);

    bool doDirectionalSWIPE(char direction,bool recursive,bool justTest=false);

    T* getRandomEmptyCase();


    void getInputFromConsole(int * input, int size, int groupe,
			string const& message1 = string(), string const& message2 =
					string());

    void getInputDirectionFromConsole(char * input){
			cout<<"Entre une valeur :";
			cin>>input;
    }

    char* getCommandeFromConsole(int nbCommandes);

    void do1Round(){
        if(modeJoeur){
            this->performAction();
        }

    }

    bool getModeJeux(){
        return modeJoeur;
    }

    void setModeJeux(bool modeJeux){
        modeJoeur=modeJeux;
    }


    const string style="-------------------------------------\n";
    //FramPlateauLand(int sizeI, int sizeJ);


    FramPlateauLand(int sizeI, int sizeJ);

    void affiche();

    virtual ~FramPlateauLand();

	template<typename U > void applyInitPlateau(U contenuJeu) {

		typename U::iterator iterContenuJeu(contenuJeu.begin());

		iterDoubleVector<T> monIter(this->plateau);

		bool notFinish = 1;
		while (monIter.hasnext() && notFinish) {
			if (iterContenuJeu != contenuJeu.end()) {

				monIter.next()->valeur = *iterContenuJeu;

				iterContenuJeu++;
			} else {
				//TODO
				cout << "pas assez d'elements !" << endl;
				notFinish = 0;
			}
		}

		if (iterContenuJeu != contenuJeu.end()) {
			//TODO
			cout << "TROP d'elements !" << endl;
		}
	}

};

#include"FramPlateauLand.tpp"

#endif /* FRAMPLATEAULAND_HPP_ */

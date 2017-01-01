/*
 * FramPlateauLand.hpp
 *
 *  Created on: 1 déc. 2016
 *      Author: raphael
 */

#ifndef FRAMPLATEAULAND_HPP_
#define FRAMPLATEAULAND_HPP_
#include "CaseGeneric.hpp"
#include "DoublePointer.hpp"
#include <vector>
#include <sstream>
#include <string>
#include <random>

using namespace std;

class TwoValue{
public:
	int x;
	int y;
	TwoValue(int _x,int _y):x(_x),y(_y){}
};

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

private:
	bool modeTerminal;

protected:

    int PositionXPersonnage;
    int PositionYPersonnage;

	bool modeGame;// si TRUE -> utlisateur | FALSE -> automatique
	bool isJeuxPersonnage; // si TRUE -> mode case qui se deplace | FALSE -> jeux autre ( exemple 2048 )

	bool recursive;//False by default

	FramPlateauLand(int sizeI, int sizeJ,bool _isJeuxPersonnage);
	FramPlateauLand(FramPlateauLand const &) = delete;
	void operator=(FramPlateauLand const &x) = delete;

    void doSwap(int i2,int j2);
    bool doDirectionalSWIPE(char direction,bool justTest=false);
    T* getRandomEmptyCase();


	virtual bool performAction(int xArriv=0,int yArriv=0,char direction=0)=0;

    virtual char isFusionnable(T * case1,T * case2)const{
    	//TODO EXCEPTION
    	cerr<<"You should REDIFINE isFusionnable"<<endl;
    	return false;
    }

    virtual bool isCaseEmpty(T const* case1){
    	//TODO EXCEPTION
    	cerr<<"You should REDIFINE isCaseEmpty"<<endl;
    	return false;
    }
    virtual DoublePointer<T>* applyFusion(T * case1,T * case2,char direction){
    	//TODO EXCEPTION
    	cerr<<"You should REDIFINE applyFusion"<<endl;
    }

	bool testArrivalPositionForPersonnage(int  xArriv, int  yArriv);
    void getArrival_from_Direction_of_Personnage(int * xArriv , int * yArriv,char direction);


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


public:
	int PlateauSizeI;
	int PlateauSizeJ;
	vector<vector<T*> >plateau;

	void setRandomEmptyCase(T* newCase);

    virtual ~FramPlateauLand();
    void affiche();
	void StartModeTerminal();

    virtual bool isGameEnd()=0;

    bool doAction(char direction);

    virtual void afterAction(){
    	//TODO EXCEPTION
    	//cerr<<"You should REDIFINE afterAction"<<endl;
    }

    /*
    virtual void initPlateau(vector<T> & contenuJeu){
        //TODO EXCEPTION
    	cerr<<"You should REDIFINE initPlateau"<<endl;
    }
    */
    static void getArrival_from_Position_and_Direction(int xStart, int yStart, char direction,
        		int * xArriv, int * yArriv);

    static char getRandomDirection();

    static void getInputFromConsole(int * input, int size, int groupe,
			string const& message1 = string(), string const& message2 =
					string());

	static char getInputDirectionFromConsole();
	static char* getCommandeFromConsole(int nbCommandes) ;


    const string style="-------------------------------------\n";
    //FramPlateauLand(int sizeI, int sizeJ);


	bool getModeTerminal() const{
		return modeTerminal;
	}
	void setModeTerminal(bool _modeTerminal){
		modeTerminal=_modeTerminal;
	}
	bool getModeRecursive() const{
		return recursive;
	}
	void setModeRecursive(bool _recursive){
		recursive=_recursive;
	}
    bool getGameMode() const{
        return modeGame;
    }
    void setGameMode(bool _modeGame){
        modeGame=_modeGame;
    }

};

#include"FramPlateauLand.tpp"

#endif /* FRAMPLATEAULAND_HPP_ */

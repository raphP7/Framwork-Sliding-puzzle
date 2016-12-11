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

using namespace std;


template<class T> class iterDoubleVector{
    public:
        int sizeMax;
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

    private:
        const vector<vector<T*> > &vec2D;
        int currentIndex;
        int sizeI;
        int sizeJ;


};

template<class T> class FramPlateauLand
{


public:
	vector<vector<T*> >plateau;
	int speedGame;
	bool modeJoeur;// si TRUE -> utlisateur | FALSE -> automatique

    void startGame(){
    	this->affiche();
        do{
            this->do1Round();
            this->affiche();
        }while(!this->gameEnd());

        cout<<"JEUX FINI"<<endl;

    }

    virtual bool gameEnd(){
    	//TODO EXCEPTION
    	return false;
    }

    virtual bool isFusionnable(T* case1,T* case2){
    	//TODO EXCEPTION
    	return false;
    }

    virtual bool isCaseEmpty(T* case1){
    	//TODO EXCEPTION
    	return false;
    }
    virtual void applyFusion(T* case1,T* case2){
    	//TODO EXCEPTION
    }

    void doSwap(int i1,int j1,int i2,int j2){

        T* tmp=plateau[i1][j1];
        plateau[i1][j1]=plateau[i2][j2];
        plateau[i2][j2]=tmp;

    }

    bool doDirectionalSWIPE(char direction,bool recursive){

    	bool onMoveDone=false;
    	//DROITE

    	if(direction=='l'){
    		for(std::size_t i=0; i < plateau.size();i++){
				for(int j=plateau.size()-1;j>-1;j--){
					bool canMove=true;
					int tmpJ=j;
					//cout<<"AVANT BOUCLE\nvaleur i:"<<i<<" |j: "<<tmpJ<<endl;

					do{
						//cout<<"DANS BOUCLE"<<endl;
						//cout<<"valeur i:"<<i<<" |j: "<<tmpJ<<endl<<"--------"<<endl;

						if(tmpJ+1==plateau.size()){//limite a droite
							canMove=false;
						}else{
							if(isCaseEmpty(plateau[i][tmpJ])){//case vide , ne ce deplace pas
								canMove=false;
							}
							else if(isFusionnable(plateau[i][tmpJ],plateau[i][tmpJ+1])){
								applyFusion(plateau[i][tmpJ],plateau[i][tmpJ+1]);
								tmpJ++;
								onMoveDone=true;
							}
							else{
								canMove=false;
							}
						}
					}while(canMove);
				}
    		}
    	}
    	//GAUCHE
    	else if(direction=='j'){
    		for(std::size_t i=0; i < plateau.size();i++){
				for(int j=0;j<plateau.size();j++){
					bool canMove=true;
					int tmpJ=j;
					//cout<<"AVANT BOUCLE\nvaleur i:"<<i<<" |j: "<<tmpJ<<endl;

					do{
						//cout<<"DANS BOUCLE"<<endl;
						//cout<<"valeur i:"<<i<<" |j: "<<tmpJ<<endl<<"--------"<<endl;

						if(tmpJ-1==-1){//limite a GAUCHE
							canMove=false;
						}else{
							if(isCaseEmpty(plateau[i][tmpJ])){//case vide , ne ce deplace pas
								canMove=false;
							}
							else if(isFusionnable(plateau[i][tmpJ],plateau[i][tmpJ-1])){
								applyFusion(plateau[i][tmpJ],plateau[i][tmpJ-1]);
								tmpJ--;
								onMoveDone=true;

							}
							else{
								canMove=false;
							}
						}
					}while(canMove);
				}
    		}
    	//HAUT
    	}else if(direction=='i'){
    		for(std::size_t j=0; j < plateau.size();j++){
				for(int i=0;i<plateau.size();i++){
					bool canMove=true;
					int tmpI=i;
					//cout<<"AVANT BOUCLE\nvaleur i:"<<i<<" |j: "<<tmpJ<<endl;

					do{
						//cout<<"DANS BOUCLE"<<endl;
						//cout<<"valeur i:"<<i<<" |j: "<<tmpJ<<endl<<"--------"<<endl;

						if(tmpI-1==-1){//limite en haut
							canMove=false;
						}else{
							if(isCaseEmpty(plateau[tmpI][j])){//case vide , ne ce deplace pas
								canMove=false;
							}
							else if(isFusionnable(plateau[tmpI][j],plateau[tmpI-1][j])){
								applyFusion(plateau[tmpI][j],plateau[tmpI-1][j]);
								tmpI--;
								onMoveDone=true;
							}
							else{
								canMove=false;
							}
						}
					}while(canMove);
				}
    		}

    	//BAS
    	}else if(direction=='k'){
    		for(std::size_t j=0; j < plateau.size();j++){
				for(int i=plateau.size()-1;i>-1;i--){
					bool canMove=true;
					int tmpI=i;
					//cout<<"AVANT BOUCLE\nvaleur i:"<<i<<" |j: "<<tmpJ<<endl;

					do{
						//cout<<"DANS BOUCLE"<<endl;
						//cout<<"valeur i:"<<i<<" |j: "<<tmpJ<<endl<<"--------"<<endl;

						if(tmpI==plateau.size()-1){//limite en bas
							canMove=false;
						}else{
							if(isCaseEmpty(plateau[tmpI][j])){//case vide , ne ce deplace pas
								canMove=false;
							}
							else if(isFusionnable(plateau[tmpI][j],plateau[tmpI+1][j])){
								applyFusion(plateau[tmpI][j],plateau[tmpI+1][j]);
								tmpI++;
								onMoveDone=true;
							}
							else{
								canMove=false;
							}
						}
					}while(canMove);
				}
    		}
    	}else{
    		//TODO exception
    	}

    	cout<<"Un mouvomeent a ete realiser :"<<onMoveDone<<endl;
    	return onMoveDone;
    }

    void getInputFromConsole(int * input,int size,int groupe){
        for(int i =0;i<size;i++){
            if(i%groupe==0){
                cout<<"Entre une valeur :";
            }else{
                cout<<"Entree une valeur associe : ";
            }
            cin>>input[i];
        }
    }

    void getInputDirectionFromConsole(char * input){
			cout<<"Entre une valeur :";
			cin>>input;
    }

    char* getCommandeFromConsole(int nbCommandes){
        if(modeJoeur){
            char * commandes=new char[nbCommandes+1];
            for(int i=0; i<nbCommandes;i++){
                cin>>commandes[i];
            }
            commandes[nbCommandes]='\0';
            cout<<"COMMANDE : ";
            for(int i=0; i<nbCommandes;i++){
                cout<<commandes[i];
            }
            cout<<endl;
            return commandes;
        }
        return nullptr;
    }


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



    virtual void performAction(){}

    virtual void initPlateau(vector<T> contenuJeu){}


    const string style="-------------------------------------\n";
    //FramPlateauLand(int sizeI, int sizeJ);


    FramPlateauLand(int sizeI, int sizeJ)
    {

        static_assert(std::is_base_of<CaseGeneric, T>::value, "wrong type");

        for (int i = 0; i < sizeI; i++)
        {
            std::vector<T*> tab;
            this->plateau.push_back(tab);

            for (int j = 0; j < sizeJ; j++)
            {

                this->plateau[i].push_back(new T(i, j));
            }
        }
        speedGame=1;
        modeJoeur=true;
    }

    FramPlateauLand(vector<vector <T>  > _pla);

    void affiche()
    {
        cout<<this->style;

        typename vector< vector<T*> >::iterator row;
        typename vector<T*>::iterator col;

        for (row = this->plateau.begin(); row != this->plateau.end(); row++)
        {

            for (col = row->begin(); col != row->end(); col++)
            {
                cout<<*(*col);
            }
            cout<<endl;
        }
        cout<<this->style<<endl<<endl;
    }

    virtual ~FramPlateauLand()
    {

        static_assert(std::is_base_of<CaseGeneric, T>::value, "wrong type");

        typename vector< vector<T*> >::iterator row;
        typename vector<T*>::iterator col;

        for (row = this->plateau.begin(); row != this->plateau.end(); row++)
        {

            for (col = row->begin(); col != row->end(); col++)
            {
                delete *col;
            }
        }
    }
};

#endif /* FRAMPLATEAULAND_HPP_ */

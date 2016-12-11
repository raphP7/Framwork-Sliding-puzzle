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

bool modeJoeur;// si TRUE -> utlisateur | FALSE -> automatique
int speedGame;

public:

    void startGame(){
    	this->affiche();
        do{
            this->do1Round();
            this->affiche();
        }while(!this->gameEnd());

        cout<<"JEUX FINI"<<endl;

    }

    virtual bool gameEnd(){
    	return false;
    }

    void doSwap(int i1,int j1,int i2,int j2){

        T* tmp=plateau[i1][j1];
        plateau[i1][j1]=plateau[i2][j2];
        plateau[i2][j2]=tmp;

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
    vector<vector<T*> >plateau;

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

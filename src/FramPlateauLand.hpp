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
using namespace std;

template<class T> class iterDoubleVector{
    public:

        iterDoubleVector(vector<vector<T * > >  &arg):vec2D(arg),currentIndex(-1){
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
        int currentIndex;
        int sizeI;
        int sizeJ;
        int sizeMax;
        vector<vector<T*> > &vec2D;

};

template<class T> class FramPlateauLand
{
public:

    virtual void initPlateau()=0;
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

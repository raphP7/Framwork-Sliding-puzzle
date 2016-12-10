/*
 * FramPlateauLand.cpp
 *
 *  Created on: 1 déc. 2016
 *      Author: raphael
 */

#include"FramPlateauLand.hpp"
#include"2048/Case2048.hpp"

template<typename T> FramPlateauLand<T>::FramPlateauLand(int sizeI, int sizeJ) {

	for (int i = 0; i < sizeI; i++) {
		std::vector<T> tab;
		this->plateau.push_back(tab);

		for (int j = 0; j < sizeJ; j++) {
			this->plateau[i].push_back(T(i, j));
		}
	}
}

template<typename T> FramPlateauLand<T>::FramPlateauLand(
		vector<vector<T> > _pla) :
		plateau(_pla) {

}

template<typename T> void FramPlateauLand<T>::affiche() {

	typename vector< vector<T> >::iterator row;
	typename vector<T>::iterator col;
	for (row = this->plateau.begin(); row != this->plateau.end(); row++) {

	    for (col = row->begin(); col != row->end(); col++) {
	    	cout<<*col;
	    }
	    cout<<endl;
	}
	cout<<endl;

}
int main() {

	cout << "hello" << endl;

	FramPlateauLand<Case2048>* fram;
	fram = new FramPlateauLand<Case2048>(8, 8);

	fram->affiche();

	fram->plateau[0][0].valeur=2;
	fram->affiche();
}

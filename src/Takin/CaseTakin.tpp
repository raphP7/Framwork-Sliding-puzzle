/*
 * CaseTakin.tpp
 *
 *  Created on: 1 déc. 2016
 *      Author: raphael
 */

template<class T> CaseTakin<T>::CaseTakin(int _i, int _j) :
		CaseGeneric(_i, _j, false), valeur(0), EmptyCase(false) {
	//std::cout << "appel constructeur CaseTakin : "<<i<<" "<<j << std::endl;

}

template<class T> CaseTakin<T>::~CaseTakin() {
	//std::cout<<"delete Takin de "<<i<<" "<<j<<std::endl;
}

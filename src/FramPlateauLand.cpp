/*
 * FramPlateauLand.cpp
 *
 *  Created on: 1 déc. 2016
 *      Author: raphael
 */

#include"FramPlateauLand.hpp"

template<typename T>FramPlateauLand<T>::FramPlateauLand(int sizeI, int sizeJ){

	for (int i = 0; i < sizeI; i++) {
		std::vector<T> tabb;
		this->plateau.push_back(tabb);
	}
}
template<typename T>FramPlateauLand<T>::FramPlateauLand(vector<vector<T> >_pla):plateau(_pla){

}

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

template<class T> class PlateauTakin: public FramPlateauLand<CaseTakin<T> > {

public:

	PlateauTakin(int sizeI, int sizeJ);

	virtual ~PlateauTakin();

	virtual void initPlateau(vector<T> contenuJeu);

	void setBlank(int i, int j);

	void setBlankCaseAtTheEnd();
private:

	bool AlreadySetBlankCase;
	bool BlankCaseAtTheEnd;

	virtual bool isGameEnd();
	virtual bool performAction(int xArriv, int yArriv,char direction);
};

#include "PlateauTakin.tpp"

#endif /* PLATEAUTakin_HPP_ */

/*
 * PlateauTakin.tpp
 *
 *  Created on: 1 déc. 2016
 *      Author: raphael
 */

template<class T> PlateauTakin<T>::PlateauTakin(int sizeI, int sizeJ) :
		FramPlateauLand<CaseTakin<T> >(sizeI, sizeJ, true), AlreadySetBlankCase(
				false), BlankCaseAtTheEnd(false) {
}



template<class T> PlateauTakin<T>::~PlateauTakin() {
}

template<class T> void PlateauTakin<T>::initPlateau(vector<T> contenuJeu) {

	this->applyInitPlateau(contenuJeu);

}

template<class T> void PlateauTakin<T>::setBlank(int i, int j) {
	if (!AlreadySetBlankCase) {
		this->plateau[i][j]->EmptyCase = true;
		AlreadySetBlankCase = true;
		this->PositionXPersonnage = i;
		this->PositionYPersonnage = j;
	}
}
template<class T> void PlateauTakin<T>::setBlankCaseAtTheEnd() {
	BlankCaseAtTheEnd = true;
}

template<class T> bool PlateauTakin<T>::gameEnd() {

	iterDoubleVector<CaseTakin<T> > monIter(this->plateau);
	CaseTakin<T> *tmpBefore;
	CaseTakin<T> *tmpActual;

	if (monIter.hasnext()) {
		tmpBefore = monIter.next();
	}
	while (monIter.hasnext()) {

		tmpActual = monIter.next();

		if (BlankCaseAtTheEnd) {
			if (!monIter.hasnext()) {
				//last
				if (tmpActual->EmptyCase) {
					return true;
				} else {
					return false;
				}
			}
		}

		if (*tmpBefore < *tmpActual) {
			tmpBefore = tmpActual;
		} else {
			return false;
		}
	}
	return true;

}

template<class T> bool PlateauTakin<T>::performAction(int xArriv, int yArriv,char direction) {

	this->doSwap(xArriv, yArriv);
	this->PositionXPersonnage = xArriv;
	this->PositionYPersonnage = yArriv;
	return true;
}


/*
 * PlateauSokoban.cpp
 *
 *  Created on: 1 déc. 2016
 *      Author: raphael
 */

#include"PlateauSokoban.hpp"

bool PlateauSokoban::gameEnd() {

	iterDoubleVector<CaseSokoban > monIter(this->plateau);

	CaseSokoban *tmpActual = monIter.next();

	if (tmpActual == nullptr) {
		cerr << "GameEnd with an empty plateau" << endl;
		return false;
	}

	while (monIter.hasnext()) {

		if (tmpActual->EmptyCase && tmpActual->valeur == 2) {
			return false;
			//une case but est vide ( sans caisse dessus);
		}

		tmpActual = monIter.next();

	}
	return true;
}

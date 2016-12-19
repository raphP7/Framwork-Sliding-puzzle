/*
 * PlateauSokoban.hpp
 *
 *  Created on: 1 déc. 2016
 *      Author: raphael
 */

#ifndef PLATEAUTsokoban_HPP_
#define PLATEAUTsokoban_HPP_
#include "CaseSokoban.hpp"
#include "../FramPlateauLand.hpp"

class PlateauSokoban: public FramPlateauLand<CaseSokoban> {

public:

	PlateauSokoban(int sizeI, int sizeJ);

	virtual ~PlateauSokoban();

	virtual void initPlateau(vector<char> contenuJeu);

private:

	virtual bool gameEnd();

	virtual bool performAction(int xArriv, int yArriv,char direction);

};

#endif /* PLATEAUTsokoban_HPP_ */

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


template<class T>class PlateauTakin: public FramPlateauLand<CaseTakin <T> >
{
public:

    PlateauTakin(int sizeI, int sizeJ):FramPlateauLand<CaseTakin<T> >(sizeI, sizeJ)
    {

    }
    void initPlateau(){


    }
};

#endif /* PLATEAUTakin_HPP_ */

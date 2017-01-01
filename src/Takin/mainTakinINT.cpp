#include "../FramPlateauLand.hpp"
#include "PlateauTakin.hpp"
#include "../Display/display.hpp"

void playTakinInt(){

	PlateauTakin<int> pTakinInt(5,2);
    vector<int> v { 2,7,0,10,5,1,4,8,4,9 };
    pTakinInt.initPlateau(v);
    pTakinInt.setBlank(1,0);
    pTakinInt.setModeBlankCaseAtTheEnd();
    pTakinInt.setGameMode(true);
    //pTakinInt.StartModeTerminal();
    display<CaseTakin<int>> affichage(pTakinInt,80);
    affichage.StartModeWindow();

}
int main(int argc, char* argv[]) {
    playTakinInt();
}

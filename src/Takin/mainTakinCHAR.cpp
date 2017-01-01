#include "../FramPlateauLand.hpp"
#include "PlateauTakin.hpp"

void playTakinChar(){
    PlateauTakin<char> pTakinInt(3,6);
    vector<char> v { 'a','b',' ','d','k','t','p','m','l',
        'x','s','a','b','p' ,'w','y','q','h'};
    pTakinInt.initPlateau(v);
    pTakinInt.setBlank(0,2);
    pTakinInt.setModeBlankCaseAtTheEnd();
    pTakinInt.setGameMode(true);
    pTakinInt.StartModeTerminal();
}

int main(int argc, char* argv[]) {
    playTakinChar();
}

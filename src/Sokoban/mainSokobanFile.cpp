#include "../FramPlateauLand.hpp"

#include "PlateauSokoban.hpp"
//#include "Sokoban/CaseSokoban.hpp"
#include "../Display/display.hpp"

void playSokoban(const char * nameFile){
	PlateauSokoban * pSokoban;
	if(nameFile!=nullptr){
		pSokoban=PlateauSokoban::readFile(nameFile);
	}
	if(pSokoban!=nullptr){
		pSokoban->setGameMode(true);
		display<CaseSokoban> affichage(*pSokoban,45);
		affichage.gridBGColour=new sf::Color (250, 248, 239, 255);
		affichage.StartModeWindow();
	}
}

int main(int argc, char* argv[]) {
	if(argc>1){
	   playSokoban(argv[1]);
   }
}

#include "../FramPlateauLand.hpp"

#include "PlateauSokoban.hpp"
//#include "Sokoban/CaseSokoban.hpp"
#include "../Display/display.hpp"

void playSokoban(){
	PlateauSokoban pSokoban(5,6);
    vector<char> v { '#','#','#','#','#','#',
    				'#',' ',' ',' ','#','#',
					'#','.','$',' ','#','#',
					'#',' ',' ','@','#','#',
					'#','#','#','#','#','#',
    				};
    pSokoban.initPlateau(v);
    pSokoban.setGameMode(true);
    display<CaseSokoban> affichage(pSokoban,60);
    //pSokoban.StartModeTerminal();
    affichage.gridBGColour=new sf::Color (250, 248, 239, 255);
    affichage.StartModeWindow();
}
int main(int argc, char* argv[]) {
	
	playSokoban();
   
}

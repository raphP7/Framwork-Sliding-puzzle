#include "../FramPlateauLand.hpp"
#include "Plateau2048.hpp"
#include "../Display/display.hpp"

void play2048(){
	Plateau2048 pl2048(5,5);
	pl2048.initPlateau();
	pl2048.setGameMode(false);
	pl2048.setModeRecursive(false);
	display<Case2048>  affichage=display<Case2048>(pl2048,70);
	affichage.StartModeWindow();
}

int main(int argc, char* argv[]) {
	play2048();
}

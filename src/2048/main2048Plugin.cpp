#include "../FramPlateauLand.hpp"
#include "Plateau2048Plugin.hpp"
#include "../Display/display.hpp"

void play2048Plugin(){
	Plateau2048Plugin pl2048PlugIn(5,5);
	pl2048PlugIn.initPlateau();
	pl2048PlugIn.setGameMode(true);
	pl2048PlugIn.setModeRecursive(false);

	display<Case2048>  affichage=display<Case2048>(pl2048PlugIn,70);
	affichage.StartModeWindow();
}

int main(int argc, char* argv[]) {
	play2048Plugin();
}

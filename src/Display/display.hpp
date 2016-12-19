/*
 * display.hpp
 *
 *  Created on: 1 déc. 2016
 *      Author: raphael
 */

#ifndef DISPLAY_HPP_
#define DISPLAY_HPP_

#include "../FramPlateauLand.hpp"
#include <SFML/Graphics.hpp>
#include <utility>
#include <sstream>
#include <string>
#include <stdlib.h>


#define tailleX 2
#define tailleY 2

#define tailleXn tailleX-1

#define tailleYn tailleY-1

#define sizeblock 120


class display {
public:

	FramPlateauLand<CaseGeneric> * plateau;

	display(FramPlateauLand<CaseGeneric> * plateau);

	void show();

	void refreshScreen();

	unsigned short score = 0;
	unsigned short highScore = 0;
	unsigned short grid [tailleX][tailleY];

	sf::Font font;
	sf::Color windowBGColour;
	sf::Color gridBGColour;
	sf::Color textColour;
	float padding = 10.f;
	float gridSize = (sizeblock * tailleXn - (padding * 2.f));
	float tileSize = (gridSize - (5 * padding)) / tailleX;

	sf::RenderWindow window;
	sf::RectangleShape gridBackgroundRect;
	sf::RectangleShape gameOverBackground;
	sf::RectangleShape gridTile;
	sf::Text titleText;
	sf::Text gameOverText;
	sf::Text scoreText;
	sf::Text scoreDecoratorText;
	sf::Text tileText;


	map<int, sf::Color> numberColours;
	bool showGameOver = false;


};

#endif /* DISPLAY_HPP_ */

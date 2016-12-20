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

#define tailleX 2
#define tailleY 2
#define tailleXn tailleX-1
#define tailleYn tailleY-1
#define sizeblock 120


template <typename T>class display {

private:
	void initWindow();
	void refreshScreen();
	FramPlateauLand<T> * plateau;

public:

	display(FramPlateauLand<T> * plateau);

	void StartModeWindow();

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

#include "display.tpp"

#endif /* DISPLAY_HPP_ */

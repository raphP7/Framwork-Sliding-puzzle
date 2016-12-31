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
#include <chrono>
#include <thread>


template<typename T> class display {

public:
	display(FramPlateauLand<T> & plateau,int sizeBlock);
	virtual ~display();
	void StartModeWindow();

	sf::Color * windowBGColour;
	sf::Color * gridBGColour;
	sf::Color * textColour;

private:
	void refreshWindow();
	void quitOrGameOver(sf::Event &event);
	void modeAuto();
	void modeGamer();
	int speedGame;

protected:
	virtual void initWindow();
	FramPlateauLand<T> & plateau;
	sf::RenderWindow * window;
	sf::Font * font;
	sf::RectangleShape * gridBackgroundRect;
	sf::RectangleShape * gameOverBackground;
	sf::RectangleShape * gridTile;
	sf::Text * titleText;
	sf::Text * gameOverText;
	sf::Text * scoreText;
	sf::Text * scoreDecoratorText;
	sf::Text * tileText;

	float sizeblock;

	unsigned short score;
	unsigned short highScore;

	//epaisseur traits
	float padding;

	//dimension tableau
	float gridSizeI;
	float gridSizeJ;

	//dimention fenetre
	float windowSizeI;
	float windowSizeJ;

	//pour dessiner les cases
	float margeNormal;
	float margeY;
	float margeX;

	//taille reserver pour le titre
	//float tileSize;

	bool showGameOver;

	void setSpeed(int _speed);
};

#include "display.tpp"

#endif /* DISPLAY_HPP_ */

/*
 * display.tpp
 *
 *  Created on: 1 déc. 2016
 *      Author: raphael
 *
 *  color and design of sfml::window inspired of https://github.com/Palmr/2048-SFML
 */

template<class T> display<T>::display(FramPlateauLand<T> & plateau,int sizeBlock) :
		plateau(plateau) {

	sizeblock=sizeBlock;
	speedGame=0;
	score = 0;
	highScore = 0;
	padding = 10.f;
	gridSizeI = (sizeblock * plateau.PlateauSizeI)  + (padding * (plateau.PlateauSizeI+1));
	gridSizeJ = (sizeblock * plateau.PlateauSizeJ)  + (padding * (plateau.PlateauSizeJ+1));
	//tileSize = sizeblock;
	showGameOver = false;


	margeNormal=sizeblock + padding;

	margeY=padding *2.f;
	margeX = sizeblock + padding;

	//inverse -> pour que le repere soit en haut a gauche ( comme dans le motor du framwork)
	windowSizeI=gridSizeJ+padding*2.f;
	windowSizeJ=gridSizeI +sizeblock+padding;

	window = new sf::RenderWindow (
				sf::VideoMode(windowSizeI,windowSizeJ), "TITRE",
				sf::Style::Close | sf::Style::Titlebar);


	//inverse
	gridBackgroundRect= new sf::RectangleShape(sf::Vector2f(gridSizeJ, gridSizeI));
	gameOverBackground= new sf::RectangleShape(sf::Vector2f(gridSizeJ, gridSizeI));
	gridTile= new sf::RectangleShape(sf::Vector2f(sizeblock, sizeblock));


	font= new sf::Font ();
	titleText=new sf::Text("FRAM PLATEAU LAND", *font, sizeblock-(sizeblock/2));
	gameOverText=new sf::Text("Game Over!", *font, 30);
	scoreText=new sf::Text(to_string(score), *font, 30);
	scoreDecoratorText=new sf::Text("", *font, 15);
	tileText=new sf::Text();

	windowBGColour= new sf::Color (250, 248, 239, 255);
	gridBGColour= new sf::Color (187, 173, 160, 255);
	textColour= new sf::Color (67, 53, 40, 255);

}

template<class T> void display<T>::setSpeed(int _speed){
	if(_speed>-1){
		speedGame=_speed;
	}
}

template<class T> display<T>::~display() {

	delete window;
	delete font;
	delete windowBGColour;
	delete gridBGColour;
	delete textColour;
	delete gridBackgroundRect;
	delete gameOverBackground;
	delete gridTile;
	delete titleText;
	delete gameOverText;
	delete scoreText;
	delete scoreDecoratorText;
	delete tileText;
}

template<class T> void display<T>::refreshWindow() {


	window->clear(*windowBGColour);
	window->draw(*gridBackgroundRect);

	//TODO a remplacer par l'iterateur pour replacer la variable plateau de framplatauLand en protected

	for (int ix = plateau.PlateauSizeI-1; ix > -1; ix--) {
		for (int iy = plateau.PlateauSizeJ-1; iy > -1; iy--) {
			gridTile->setPosition(
					//inverse
					//iy inverser avec ix
					sf::Vector2f(margeY+ (iy * margeNormal) ,margeX + (ix * margeNormal)
							)
			);

			window->draw(*gridTile);

			CaseGeneric* caseTmp = plateau.plateau[ix][iy];
			tileText->setString(caseTmp->toString());
			sf::Vector2f textPosition = (gridTile->getPosition()
					+ (gridTile->getSize() / 2.f));

			textPosition.x -= tileText->getGlobalBounds().width / 2.f;
			textPosition.y -= (tileText->getGlobalBounds().height + padding)/ 2.f;
			tileText->setPosition(textPosition);
			window->draw(*tileText);
		}
	}

	// Handle game over display
	if (showGameOver) {
		window->draw(*gameOverBackground);
		window->draw(*gameOverText);
		scoreDecoratorText->setString("Hit ENTER to EXIT");
		scoreDecoratorText->setPosition(
				sf::Vector2f(gameOverText->getPosition().x,
						gameOverText->getPosition().y
								+ gameOverText->getLocalBounds().height
								+ padding * 2));
		window->draw(*scoreDecoratorText);
	}

	window->draw(*titleText);
	window->display();


}

template<class T> void display<T>::initWindow() {
	if (this->plateau.getModeTerminal()) {
		cerr << "mode TERMINAL ACTIVER !!" << endl;
		return;
	}


	if (!font->loadFromFile("ClearSans-Bold.ttf")) {
		cout<<"Font fail"<<endl;
		return;
	}

	// Set up the grid background rect
	gridBackgroundRect->setFillColor(*gridBGColour);
	gridBackgroundRect->setPosition(sf::Vector2f(padding, sizeblock));

	// Set up the title text
	titleText->setStyle(sf::Text::Bold);
	titleText->setColor(*textColour);
	titleText->setPosition(sf::Vector2f(0, 0));

	// Set up the score text objects
	scoreText->setStyle(sf::Text::Bold);
	scoreText->setColor(*textColour);
	scoreDecoratorText->setColor(*textColour);

	// Set up the tile text
	tileText->setFont(*font);
	tileText->setCharacterSize(sizeblock/2);
	tileText->setStyle(sf::Text::Bold);
	tileText->setColor(*textColour);

	// Set up the game over display
	gameOverBackground->setFillColor(sf::Color(250, 248, 239, 175));
	gameOverBackground->setPosition(sf::Vector2f(padding, sizeblock));
	gameOverText->setStyle(sf::Text::Bold);
	gameOverText->setColor(*textColour);
	gameOverText->setPosition(sf::Vector2f(windowSizeI/4, windowSizeJ/4));
}

template<class T> void display<T>::quitOrGameOver(sf::Event & event) {
	if (event.type == sf::Event::Closed
			|| (event.type == sf::Event::KeyPressed
					&& sf::Keyboard::isKeyPressed(sf::Keyboard::Return))) {
		window->close();
		return;
	}
}

template<class T> void display<T>::modeAuto() {
	bool moveDone = true;
	char commande = ' ';

	while (window->isOpen()) {
		sf::Event event;

		if (!showGameOver) {
			commande = plateau.getRandomDirection();

			if (this->plateau.doAction(commande)) {
				if (plateau.isGameEnd()) {
					showGameOver = true;
				}
			}
		}

		refreshWindow();
		if(showGameOver){
			if (window->waitEvent(event)) {
				quitOrGameOver(event);
			}
		} else {
			if (window->pollEvent(event)) {
				quitOrGameOver(event);
			}
		}
	}
}


template<class T> void display<T>::modeGamer() {
	bool moveDone = true;
	char commande = ' ';

	while (window->isOpen()) {

		refreshWindow();
		sf::Event event;
		if(window->waitEvent(event)) {

			if (event.type == sf::Event::Closed) {
				window->close();
			}

			else if (event.type == sf::Event::KeyPressed && !moveDone ) {
				commande = ' ';

				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
					commande = 'i';
				} else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
					commande = 'l';
				} else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
					commande = 'k';
				} else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
					commande = 'j';
				}else if (sf::Keyboard::isKeyPressed(sf::Keyboard::O)) {
					showGameOver = true;
				} else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Return)) {
					//reset();
					return;
				}
				if (commande != ' ' &&!showGameOver) {
					if (this->plateau.doAction(commande)) {
						moveDone = true;
					}
				}
			}

			if (event.type == sf::Event::KeyReleased && moveDone) {
				if (plateau.isGameEnd()) {
					showGameOver = true;
				}
				moveDone = false;
			}
		}
	}
}

template<class T> void display<T>::StartModeWindow() {
	initWindow();
	if(plateau.getGameMode()){
		modeGamer();
	}else{
		modeAuto();
	}
}

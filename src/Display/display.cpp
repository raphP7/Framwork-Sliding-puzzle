#include "display.hpp"

display::display(FramPlateauLand<CaseGeneric> * plateau):plateau(plateau){
	unsigned short score = 0;
	unsigned short highScore = 0;

	int** ary = new int*[plateau->PlateauSizeI];
	for(int i = 0; i < plateau->PlateauSizeI; ++i)
	    ary[i] = new int[plateau->PlateauSizeJ];

	//unsigned short grid =new [plateau->PlateauSizeI][plateau->PlateauSizeJ];

	sf::Font font;
	sf::Color windowBGColour(250, 248, 239, 255);
	sf::Color gridBGColour(187, 173, 160, 255);
	sf::Color textColour(67, 53, 40, 255);
	float padding = 10.f;
	float gridSize = (sizeblock * tailleXn - (padding * 2.f));
	float tileSize = (gridSize - (5 * padding)) / tailleX;

	sf::RenderWindow window(sf::VideoMode(sizeblock * tailleX, sizeblock + 120 *tailleYn), "TITRE", sf::Style::Close|sf::Style::Titlebar);
	sf::RectangleShape gridBackgroundRect(sf::Vector2f(gridSize, gridSize));
	sf::RectangleShape gameOverBackground(sf::Vector2f(gridSize, gridSize));
	sf::RectangleShape gridTile(sf::Vector2f(tileSize, tileSize));
	sf::Text titleText("2048!", font, 48);
	sf::Text gameOverText("Game Over!", font, 50);
	sf::Text scoreText(to_string(score), font, 48);
	sf::Text scoreDecoratorText("", font, 15);
	sf::Text tileText;


	map<int, sf::Color> numberColours;
	bool showGameOver = false;

}

void display::refreshScreen() {
	window.clear(windowBGColour);

	window.draw(gridBackgroundRect);

	// render the grid
	for (int ix = 0; ix < tailleX; ix++) {
		for (int iy = 0; iy < tailleY; iy++) {
			gridTile.setPosition(sf::Vector2f(20 + (ix * (tileSize + padding)), sizeblock + (iy * (tileSize + padding))));
			gridTile.setFillColor(numberColours.find(grid[ix][iy])->second);
			window.draw(gridTile);

			if (grid[ix][iy] > 0) {
				tileText.setString(to_string(grid[ix][iy]));
				sf::Vector2f textPosition = (gridTile.getPosition() + (gridTile.getSize() / 2.f));
				textPosition.x -= tileText.getGlobalBounds().width / 2.f;
				textPosition.y -= (tileText.getGlobalBounds().height + padding) / 2.f;
				tileText.setPosition(textPosition);
				window.draw(tileText);
			}
		}
	}

	// render the score info
	scoreText.setString(to_string(score));
	scoreText.setPosition(sf::Vector2f(380 - scoreText.getGlobalBounds().width, 25));
	window.draw(scoreText);
	scoreDecoratorText.setString("score:");
	scoreDecoratorText.setPosition(sf::Vector2f(scoreText.getPosition().x - scoreDecoratorText.getGlobalBounds().width - 10, 57));
	window.draw(scoreDecoratorText);
	scoreDecoratorText.setString("highscore: " + to_string(highScore));
	scoreDecoratorText.setPosition(sf::Vector2f(scoreDecoratorText.getPosition().x, 72));
	window.draw(scoreDecoratorText);

	// Handle game over display
	if (showGameOver) {
		window.draw(gameOverBackground);
		window.draw(gameOverText);
		scoreDecoratorText.setString("Hit ENTER to restart");
		scoreDecoratorText.setPosition(sf::Vector2f(gameOverText.getPosition().x + 75, gameOverText.getPosition().y + gameOverText.getLocalBounds().height + padding*2));
		window.draw(scoreDecoratorText);
	}

	window.draw(titleText);
	window.display();
}


void display::show() {
	// Try and load the font
	if (!font.loadFromFile("ClearSans-Bold.ttf")) {
		printf("Font fail\r\n");
		return;
	}

	printf("bonjour");

	// Define colours for the cells based on their value
	numberColours[0] = sf::Color(204, 192, 179, 255);
	numberColours[2] = sf::Color(238, 228, 218, 255);
	numberColours[4] = sf::Color(237, 224, 200, 255);
	numberColours[8] = sf::Color(242, 177, 121, 255);
	numberColours[16] = sf::Color(245, 149, 99, 255);
	numberColours[32] = sf::Color(246, 124, 95, 255);
	numberColours[64] = sf::Color(246, 94, 59, 255);
	numberColours[128] = sf::Color(237, 207, 114, 255);
	numberColours[256] = sf::Color(237, 204, 97, 255);
	numberColours[512] = sf::Color(237, 200, 80, 255);
	numberColours[1024] = sf::Color(237, 197, 63, 255);
	numberColours[2048] = sf::Color(237, 194, 46, 255);

	// Set up the grid background rect
	gridBackgroundRect.setFillColor(gridBGColour);
	gridBackgroundRect.setPosition(sf::Vector2f(10, 110));

	// Set up the title text
	titleText.setStyle(sf::Text::Bold);
	titleText.setColor(textColour);
	titleText.setPosition(sf::Vector2f(10, 25));

	// Set up the score text objects
	scoreText.setStyle(sf::Text::Bold);
	scoreText.setColor(textColour);
	scoreDecoratorText.setColor(textColour);

	// Set up the tile text
	tileText.setFont(font);
	tileText.setCharacterSize(32);
	tileText.setStyle(sf::Text::Bold);
	tileText.setColor(textColour);

	// Set up the game over display
	gameOverBackground.setFillColor(sf::Color(250, 248, 239, 175));
	gameOverBackground.setPosition(sf::Vector2f(10, 110));
	gameOverText.setStyle(sf::Text::Bold);
	gameOverText.setColor(textColour);
	gameOverText.setPosition(sf::Vector2f(60, 265));


	// Some stuff for making the random adds to hapen after a slight delay
	bool moveDone = false;
	bool scheduledNumberAdd = false;
	sf::Clock clock;
	clock.restart();
	sf::Time addTimeout = sf::milliseconds(75);

	char commande=' ';
	while (window.isOpen()) {
		sf::Event event;
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed) {
				window.close();
			}
			if (event.type == sf::Event::KeyPressed && !moveDone
					&& !scheduledNumberAdd) {
				unsigned char tilesMoved = 0;
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
					commande = 'i';
				} else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
					commande = 'l';
				} else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
					commande = 'k';
				} else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
					commande = 'j';
				} else if (sf::Keyboard::isKeyPressed(sf::Keyboard::O)) {
					showGameOver = true;
				} else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Return)) {
					//reset();
					continue;
				}
				moveDone = true;
				if (tilesMoved > 0) {
					scheduledNumberAdd = true;
					clock.restart();
				}
			}
			if (event.type == sf::Event::KeyReleased && moveDone) {

				this->plateau->performAction();

				if (this->plateau->gameEnd()) {
					showGameOver = true;
				}
				moveDone = false;
			}
		}

		if (scheduledNumberAdd && clock.getElapsedTime() > addTimeout) {
			//new value
			scheduledNumberAdd = false;
		}
		refreshScreen();
	}
}

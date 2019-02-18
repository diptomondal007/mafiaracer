#pragma once

#include "SFML/Graphics.hpp"

using namespace std;

class HighScore
{
public:
	HighScore();
	sf::Text text[2];

	string arr;
	~HighScore();

	void draw(sf::RenderWindow &window);

	int score();

private:
	sf::Font font;
	sf::Font name;
	string line;
};


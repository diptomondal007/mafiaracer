#include "HighScore.h"
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <iostream>
#include <sstream>
#include <time.h>
#include <fstream>
#include <stack>
#include<string>

using namespace std;
HighScore::HighScore()
{
	font.loadFromFile("src/font/text2.ttf");
	int i = 0;

	ifstream myfile("example.txt");


	name.loadFromFile("src/font/text2.ttf");

	if (myfile.is_open())
	{
		while (getline(myfile, line))
		{
			text[i].setString(line);
			arr = line;
			i++;
		}
		myfile.close();
	}
	else cout << "Unable to open file";
}
HighScore::~HighScore()
{
}

void HighScore::draw(sf::RenderWindow &window)
{
	sf::Texture h_score;
	h_score.loadFromFile("src/media/high_score.jpg");

	sf::Sprite high_score;
	high_score.setTexture(h_score);
	high_score.setPosition(-200, -400);
	//high_score.setTextureRect(sf::IntRect(0, 0, 1370, 690));
	sf::Font score;
	score.loadFromFile("src/font/Begok.ttf");
	sf::Text high;
	high.setFont(score);
	high.setString("high score");
	high.setColor(sf::Color::Cyan);
	high.setCharacterSize(80);
	high.setStyle(sf::Text::Bold);
	high.setPosition(900 / 2 - high.getGlobalBounds().width / 2, 150);

	sf::Font fnt;
	fnt.loadFromFile("src/font/Begok.ttf");
	sf::Text txt;
	txt.setFont(fnt);
	txt.setString("press escape key for the main menu");
	txt.setColor(sf::Color::Red);
	txt.setStyle(sf::Text::Bold);
	txt.setCharacterSize(30);
	txt.setPosition(250,600);



	while (window.isOpen())
	{

		sf::Event event;

		while (window.pollEvent(event))
		{
			switch (event.type)
			{
			case sf::Event::Closed:
				window.close();

				break;
			}
		}
		if (sf::Keyboard::isKeyPressed)
		{
			if (event.key.code == sf::Keyboard::Escape)
				break;
		}
		window.clear();
		window.draw(high_score);
		window.draw(txt);
		window.draw(high);
		for (int i = 0; i < 2; i++)
		{
			text[i].setColor(sf::Color::Cyan);
			text[i].setFont(name);
			text[i].setPosition(900 / 2 - text[i].getGlobalBounds().width / 2, 300 + (i * 70));
			text[i].setStyle(sf::Text::Regular);
			text[i].setCharacterSize(50);
			window.draw(text[i]);
		}
		window.display();
	}
}

int HighScore::score()
{
	int x;
	std::istringstream ss(arr);
	ss>>x;
	return x;
}

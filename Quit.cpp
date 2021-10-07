#include "Quit.h"



Quit::Quit()
{
}

Quit::Quit(sf::Vector2f v)
{
	myRec.setFillColor(sf::Color::White);
	myRec.setTexture(&SingletonTextures::instance().get_exitgame());
	myRec.setPosition(v);
	myRec.setSize(sf::Vector2f(150, 150));
}


Quit::~Quit()
{
}

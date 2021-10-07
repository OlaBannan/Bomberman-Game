#include "Start.h"



Start::Start()
{
}

Start::Start(sf::Vector2f v)
{
	myRec.setFillColor(sf::Color::White);
	myRec.setTexture(&SingletonTextures::instance().get_startgame());

	myRec.setPosition(v);
	myRec.setSize(sf::Vector2f(150, 150));
}


Start::~Start()
{
}

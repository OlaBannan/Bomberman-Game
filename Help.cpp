#include "Help.h"



Help::Help()
{
}

Help::Help(sf::Vector2f v)
{
	myRec.setFillColor(sf::Color::White);
	myRec.setTexture(&SingletonTextures::instance().get_helpgame());

	myRec.setPosition(v);
	myRec.setSize(sf::Vector2f(150, 150));

}


Help::~Help()
{
}

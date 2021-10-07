#include "Brick.h"



Brick::Brick(int i, int j, char type) : UnMoveable(i, j, type)
{
	myRec.setFillColor(sf::Color::White);
	myRec.setTexture(&SingletonTextures::instance().get_brick());
}


Brick::~Brick()
{
}

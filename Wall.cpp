#include "Wall.h"



Wall::Wall(int i, int j, char type) : UnMoveable(i, j, type)
{
	
	myRec.setFillColor(sf::Color::White);
	myRec.setTexture(&SingletonTextures::instance().get_wall());
}


Wall::~Wall()
{
}

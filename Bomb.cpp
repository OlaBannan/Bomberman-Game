#include "Bomb.h"
#include "Flame.h"


Bomb::Bomb(int i, int j, char type) : UnMoveable(i, j, type)
{
	myRec.setFillColor(sf::Color::White);
	myRec.setTexture(&SingletonTextures::instance().get_bomb());
}


Bomb::~Bomb()
{
}

bool Bomb::setbomb()
{

	if (m_Bombclock.getElapsedTime().asSeconds() >= 4) {
		this->kill();
		return true;
	}
	return false;
}

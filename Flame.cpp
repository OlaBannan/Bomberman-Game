#include "Flame.h"



Flame::Flame(int i, int j, char type) : UnMoveable(i, j, type)
{

	myRec.setFillColor(sf::Color::White);
	myRec.setTexture(&SingletonTextures::instance().get_flame());
}

void Flame::setFlame()
{

	if (m_FlameClock.getElapsedTime().asSeconds() >= 1) {

		this->kill();
		m_FlameClock.restart();
	}
}

Flame::~Flame()
{
}

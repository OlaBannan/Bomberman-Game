#include "GiftUnderBrick.h"


GiftUnderBrick::GiftUnderBrick(int i, int j, char type) : UnMoveable(i, j, type)
{
	myRec.setFillColor(sf::Color::White);
	myRec.setTexture(&SingletonTextures::instance().get_brick());
}


GiftUnderBrick::~GiftUnderBrick()
{

}


void GiftUnderBrick::setAlive()
{
	killed = false;
	m_checked = false;
}
#include "Gift.h"


Gift::Gift(int i, int j, char type) : UnMoveable(i, j, type)
{
	
	m_gift_under_brick = false;
	myRec.setTexture(&SingletonTextures::instance().get_gift());
}
void Gift::setSituationGift()
{
	m_gift_under_brick = true;
}

bool Gift::wasUnderBrick()
{
	return m_gift_under_brick;
}

Gift::~Gift()
{
}

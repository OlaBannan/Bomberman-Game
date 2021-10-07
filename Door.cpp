#include "Door.h"

Door::Door(int i, int j, char type) : UnMoveable(i, j, type)
{
	myRec.setTexture(&SingletonTextures::instance().get_door());
}


Door::~Door()
{
}

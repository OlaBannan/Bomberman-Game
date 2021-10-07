#include "REnemyRobotColl.h"



REnemyRobotColl::REnemyRobotColl()
{
}

void REnemyRobotColl::collide(Moveable *&Enemy, GameObject *&Robot, sf::Vector2u limits)
{
	Robot->kill();
}

REnemyRobotColl::~REnemyRobotColl()
{
}

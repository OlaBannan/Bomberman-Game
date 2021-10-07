#include "SEnemyRobotcoll.h"



SEnemyRobotcoll::SEnemyRobotcoll()
{
}

void SEnemyRobotcoll::collide(Moveable *&Enemy, GameObject *&Robot, sf::Vector2u limits)
{
	Robot->kill();
}


SEnemyRobotcoll::~SEnemyRobotcoll()
{
}

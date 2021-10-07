#include "RobotREnemyColl.h"

RobotREnemyColl::RobotREnemyColl()
{
}

void RobotREnemyColl::collide(Moveable *&Robot, GameObject *&Enemy, sf::Vector2u limits)
{
	Robot->kill();
}

RobotREnemyColl::~RobotREnemyColl()
{
}

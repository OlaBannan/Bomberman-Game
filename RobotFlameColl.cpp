#include "RobotFlameColl.h"



RobotFlameColl::RobotFlameColl()
{
}


void RobotFlameColl::collide(Moveable* &Robot,GameObject * &Flame, sf::Vector2u limits)
{
	Robot->kill();
}

RobotFlameColl::~RobotFlameColl()
{
}

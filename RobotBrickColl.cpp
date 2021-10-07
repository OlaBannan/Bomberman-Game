#include "RobotBrickColl.h"



RobotBrickColl::RobotBrickColl()
{
}

void RobotBrickColl::collide(Moveable* &Robot, GameObject * &Brick, sf::Vector2u limits)
{

	Robot->setColor(sf::Color::Red);
	Robot->setNewPos(Robot->getnext(Robot->get_pos(), limits));
}

RobotBrickColl::~RobotBrickColl()
{
}

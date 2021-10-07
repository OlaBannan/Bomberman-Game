#include "RobotDoorColl.h"



RobotDoorColl::RobotDoorColl()
{
}

void RobotDoorColl::collide(Moveable* &Robot, GameObject * &Door, sf::Vector2u limits)
{

	Robot->setColor(sf::Color::Red);
	Robot->setNewPos(Robot->getnext(Robot->get_pos(), limits));
}


RobotDoorColl::~RobotDoorColl()
{
}

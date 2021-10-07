#include "RobotWallColl.h"



RobotWallColl::RobotWallColl()
{
}

void RobotWallColl::collide(Moveable* &Robot, GameObject * &Wall, sf::Vector2u limits)
{

	Robot->setColor(sf::Color::Red);
	Robot->setNewPos(Robot->getnext(Robot->get_pos(), limits));
	//Wall->kill();
}

RobotWallColl::~RobotWallColl()
{
}

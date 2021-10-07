#include "RobotGiftColl.h"



RobotGiftColl::RobotGiftColl()
{
}


void RobotGiftColl::collide(Moveable* &Robot, GameObject * &Gift, sf::Vector2u limits)
{

	//Robot->setColor(sf::Color::Red);
	Robot->setNewPos(Robot->getnext(Robot->get_pos(), limits));
	Gift->kill();
	Robot->changeSpeed(0.8f, 7);
	Robot->addBombNum(5);
}

RobotGiftColl::~RobotGiftColl()
{
}

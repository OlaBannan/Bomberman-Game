#include "RobotEmptyColl.h"



RobotEmptyColl::RobotEmptyColl()
{
}

void RobotEmptyColl::collide(Moveable * &Robot, GameObject *& Empty, sf::Vector2u limits)
{

	sf::Vector2i pos = Empty->get_pos();
	sf::Vector2i pacPos = Robot->get_pos();


}


RobotEmptyColl::~RobotEmptyColl()
{
}

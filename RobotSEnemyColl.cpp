#include "RobotSEnemyColl.h"



RobotSEnemyColl::RobotSEnemyColl()
{
}

void RobotSEnemyColl::collide(Moveable *&Robot, GameObject *&Enemy, sf::Vector2u limits)
{

	Robot->kill();

}

RobotSEnemyColl::~RobotSEnemyColl()
{
}

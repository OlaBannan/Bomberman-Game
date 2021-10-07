#include "SEnemyFlameColl.h"



SEnemyFlameColl::SEnemyFlameColl()
{
}


void SEnemyFlameColl::collide(Moveable *&Enemy, GameObject * &Flame, sf::Vector2u limits)
{

	Enemy->kill();

}

SEnemyFlameColl::~SEnemyFlameColl()
{
}

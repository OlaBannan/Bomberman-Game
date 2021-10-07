#include "REnemyFlameColl.h"



REnemyFlameColl::REnemyFlameColl()
{
}


void REnemyFlameColl::collide(Moveable *&Enemy, GameObject * &Flame, sf::Vector2u limits)
{

	Enemy->kill();
	


}

REnemyFlameColl::~REnemyFlameColl()
{
}

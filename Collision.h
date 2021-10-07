#pragma once
#include "GameObject.h"
#include "Moveable.h"
class Collision
{
public:
	Collision();
	virtual void collide(Moveable*&, GameObject * &, sf::Vector2u limits) = 0;
	~Collision();
};


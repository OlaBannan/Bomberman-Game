#pragma once
#include "Collision.h"

class MoveCollision :public Collision
{
public:
	MoveCollision();
	virtual void collide(Moveable*&, GameObject * &, sf::Vector2u limits) = 0;

	~MoveCollision();
};


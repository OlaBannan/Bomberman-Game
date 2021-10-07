#pragma once
#include "Collision.h"

class UnmoveCollison :public Collision
{
public:
	UnmoveCollison();
	virtual void collide(Moveable *&, GameObject *&, sf::Vector2u limits) = 0;
	~UnmoveCollison() ;
};


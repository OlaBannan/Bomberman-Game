#pragma once
//#include "UnmoveCollison.h"
#include "Moveable.h"
#include"UnMoveable.h"
#include "UnmoveCollison.h"
#include "Enemy.h"
#include "Macros.h"

class SEnemyFlameColl : public UnmoveCollison
{
public:
	SEnemyFlameColl();
	void collide(Moveable *&Enemy, GameObject * &Flame, sf::Vector2u limits);
	~SEnemyFlameColl();
};





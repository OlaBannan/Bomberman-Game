#pragma once
//#include "UnmoveCollison.h"
#include "Moveable.h"
#include"UnMoveable.h"
#include "UnmoveCollison.h"
#include "Flame.h"
#include "Enemy.h"
#include "Macros.h"

class REnemyFlameColl : public UnmoveCollison
{
public:
	REnemyFlameColl();
	void collide(Moveable *&Enemy, GameObject * &Flame, sf::Vector2u limits);
	~REnemyFlameColl();
};





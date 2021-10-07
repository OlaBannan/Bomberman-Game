#pragma once
#include "Moveable.h"
#include"UnMoveable.h"
#include "UnmoveCollison.h"
#include"Robot.h"
#include "Enemy.h"
#include "Macros.h"

class RobotFlameColl : public UnmoveCollison
{
public:
	RobotFlameColl();
	void collide(Moveable* &Robot, GameObject * &Flame, sf::Vector2u limits);          	
	~RobotFlameColl();
};





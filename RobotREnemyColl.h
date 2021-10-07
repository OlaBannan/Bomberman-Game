#pragma once
#include "MoveCollision.h"
#include"EmptyCell.h"
#include "Enemy.h"

class RobotREnemyColl :public MoveCollision
{
public:
	RobotREnemyColl();
	 void collide( Moveable *&Enemy, GameObject *&Robot, sf::Vector2u limits);
	~RobotREnemyColl();
};


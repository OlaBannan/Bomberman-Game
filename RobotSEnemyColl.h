#pragma once
#include "MoveCollision.h"
#include"EmptyCell.h"
#include "Enemy.h"

class RobotSEnemyColl :public MoveCollision
{
public:
	RobotSEnemyColl();
	virtual void collide(Moveable*&, GameObject * &, sf::Vector2u limits);
	~RobotSEnemyColl();
};


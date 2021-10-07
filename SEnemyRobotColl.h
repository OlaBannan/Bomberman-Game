#pragma once
#include "MoveCollision.h"
#include"EmptyCell.h"
#include "Enemy.h"

class SEnemyRobotcoll :public MoveCollision
{
public:
	SEnemyRobotcoll();
	virtual void collide(Moveable*&, GameObject * &, sf::Vector2u limits);
	~SEnemyRobotcoll();
};


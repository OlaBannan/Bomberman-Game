#pragma once
#include "MoveCollision.h"
#include"EmptyCell.h"
#include "Enemy.h"

class REnemyRobotColl :public MoveCollision
{
public:
	REnemyRobotColl();
	void collide(Moveable *&Enemy, GameObject *&Robot, sf::Vector2u limits);
	~REnemyRobotColl();
};


#pragma once
#include "Moveable.h"
#include"UnMoveable.h"
#include "UnmoveCollison.h"
#include"EmptyCell.h"
#include"Robot.h"
#include "Enemy.h"
#include "Macros.h"

class RobotWallColl : public UnmoveCollison
{
public:
	RobotWallColl();
	void collide(Moveable* &Robot, GameObject * &Gif, sf::Vector2u limits);
	~RobotWallColl();
};


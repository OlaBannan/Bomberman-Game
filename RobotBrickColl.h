#pragma once
#include "Moveable.h"
#include"UnMoveable.h"
#include "UnmoveCollison.h"
#include"EmptyCell.h"
#include"Robot.h"
#include "Enemy.h"
#include "Macros.h"

class RobotBrickColl : public UnmoveCollison
{
public:
	RobotBrickColl();
	void collide(Moveable* &Robot, GameObject * &Gif, sf::Vector2u limits);
	~RobotBrickColl();
};


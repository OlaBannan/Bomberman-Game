#pragma once
//#include "UnmoveCollison.h"
#include "Moveable.h"
#include"UnMoveable.h"
#include "UnmoveCollison.h"
#include"EmptyCell.h"
#include"Robot.h"
#include "Enemy.h"
#include "Macros.h"

class RobotGiftColl : public UnmoveCollison
{
public:
	RobotGiftColl();
	void collide(Moveable* &Robot, GameObject* &Gift, sf::Vector2u limits);
	~RobotGiftColl();
};





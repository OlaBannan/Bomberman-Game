#pragma once
#include "UnmoveCollison.h"

class RobotDoorColl : public UnmoveCollison
{
public:
	RobotDoorColl();
	void collide(Moveable* &Robot, GameObject * &Door,sf::Vector2u limits);
	~RobotDoorColl();
};


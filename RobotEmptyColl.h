#pragma once
#include "UnmoveCollison.h"
#include "Moveable.h"
#include"UnMoveable.h"
#include "Robot.h"
#include "GameObject.h"

class RobotEmptyColl :public UnmoveCollison
{
public:
	RobotEmptyColl();
	void collide(Moveable* &Robot, GameObject* &Empty, sf::Vector2u limits);
	~RobotEmptyColl();
};


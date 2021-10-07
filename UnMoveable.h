#pragma once
#include "GameObject.h"

class UnMoveable :public GameObject
{
public:
	UnMoveable();
	UnMoveable(int i, int j, char type);
	virtual ~UnMoveable() = 0 {};
};


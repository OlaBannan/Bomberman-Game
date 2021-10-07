#pragma once
#include "UnMoveable.h"
#include "Texture.h"

class Brick : public UnMoveable
{
public:
	Brick(int i, int j, char type);
	~Brick();
};


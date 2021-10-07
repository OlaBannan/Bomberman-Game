#pragma once
#include "UnMoveable.h"
#include "Texture.h"

class Wall : public UnMoveable
{
public:
	Wall(int i, int j, char type);
	~Wall();
};


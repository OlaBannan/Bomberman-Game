#pragma once

#include "UnMoveable.h"
#include "Texture.h"

class Door : public UnMoveable
{
public:
	Door(int i, int j, char type);
	~Door();
};


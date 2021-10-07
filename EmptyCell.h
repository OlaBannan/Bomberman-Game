#pragma once

#include "UnMoveable.h"
#include "Texture.h"

class EmptyCell : public UnMoveable
{
public:
	EmptyCell(int i, int j, char type);
	~EmptyCell();
};


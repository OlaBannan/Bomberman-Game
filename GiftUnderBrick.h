#pragma once
#include "UnMoveable.h"
#include "Texture.h"

class GiftUnderBrick : public UnMoveable
{
public:
	GiftUnderBrick(int i, int j, char type);
	virtual void setAlive();
	~GiftUnderBrick();
};


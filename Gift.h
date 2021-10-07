#pragma once
#include "UnMoveable.h"
#include "Texture.h"

class Gift : public UnMoveable
{
private:
	bool m_gift_under_brick;
public:
	Gift(int i, int j, char type);
	void setSituationGift();
	bool wasUnderBrick();
	~Gift();
};


#pragma once
#include "UnMoveable.h"
#include "Texture.h"


class Bomb : public UnMoveable
{
private:
	sf::Clock m_Bombclock;
public:
	virtual bool setbomb();
	Bomb(int i, int j, char type);
	~Bomb();
};


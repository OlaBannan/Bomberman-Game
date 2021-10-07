#pragma once
#include "UnMoveable.h"
#include "Texture.h"

class Flame : public UnMoveable
{
private:
	sf::Clock m_FlameClock;
public:
	Flame(int i, int j, char type);
	void setFlame();
	~Flame();


};


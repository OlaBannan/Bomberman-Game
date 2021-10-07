#pragma once
#include "Enemy.h"
#include "Texture.h"

class RandomEnemy :public Enemy
{
public:
	RandomEnemy();
	RandomEnemy(int i, int j, char type);
	void move(sf::Vector2i robotPos, sf::Vector2u limits);
	~RandomEnemy();
};


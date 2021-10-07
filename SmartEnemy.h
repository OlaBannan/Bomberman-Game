#pragma once
#include "Enemy.h"
#include "Texture.h"


class SmartEnemy :public Enemy
{
public:
	SmartEnemy();
	SmartEnemy(int i, int j, char type);
	virtual void move(sf::Vector2i robotPos, sf::Vector2u limits);
	~SmartEnemy();

};



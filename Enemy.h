#pragma once
#include "Texture.h"
#include "Moveable.h"
#include <iostream>


class Enemy :public Moveable
{
public:
	Enemy();
	Enemy(int i, int j, char type);
	sf::Vector2f getnext(sf::Vector2i, sf::Vector2u limits) ;
	virtual void move(sf::Vector2i, sf::Vector2u limits);
	Enemy(sf::Vector2f);
	//Enemy(sf::Vector2f, enum MONSTERCOLOR);

	~Enemy();
	static int getEnemyNum() ;
protected:
	static int m_Enemy_count;
	void moveDirection(int path, sf::Vector2u limits);

private:
	sf::RectangleShape    m_shape;
	

};


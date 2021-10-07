#pragma once
#include "Moveable.h"
#include <SFML/Graphics.hpp>
#include <vector>
#include "GameObject.h"
#include"UnMoveable.h"


using namespace ::std;
class GameBoard
{
public:
	GameBoard();
	~GameBoard();
	GameObject * getGameObjInPos(sf::Vector2f);
	void drawMenu(sf::RenderWindow &menu);
	void insertTomenu(GameObject*);
	
	vector<GameObject*>m_menu;
};


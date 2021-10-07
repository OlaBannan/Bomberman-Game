#include "GameBoard.h"

GameBoard::GameBoard()
{

}


GameBoard::~GameBoard()
{
}

GameObject * GameBoard::getGameObjInPos(sf::Vector2f v)
{
	return nullptr;
}

void GameBoard::drawMenu(sf::RenderWindow & menu)
{
	for (size_t i = 0; i < m_menu.size(); i++) {
		m_menu[i]->draw(menu);
	}
}

void GameBoard::insertTomenu(GameObject *menu)
{
	m_menu.push_back(menu);
}


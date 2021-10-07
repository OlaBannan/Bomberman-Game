#include "Enemy.h"




Enemy::Enemy()
{
}

Enemy::Enemy(int i, int j, char type) :Moveable(i, j, type)
{
	m_Enemy_count++;
}

sf::Vector2f Enemy::getnext(sf::Vector2i robotPos, sf::Vector2u limits) 
{

	move(robotPos, limits);
	return _nextPos;
}

void Enemy::move(sf::Vector2i robotPos, sf::Vector2u limits)
{
	
}

Enemy::Enemy(sf::Vector2f v)
{
}

Enemy::~Enemy()
{
	m_Enemy_count--;
	//std::cout << m_Enemy_count;
}



void Enemy::moveDirection(int path, sf::Vector2u limits)
{
	sf::Vector2f tempPos;
	updateSpeed();
	m_speed /= 4;
	
	switch (path)
	{
	case 0:
		tempPos.x = myRec.getPosition().x + m_speed ;
		tempPos.y = myRec.getPosition().y;
		if (checkLimits(tempPos, limits))
			_nextPos = tempPos;
		else {
			dir = NONE;
			return;
		}
		dir = RIGHT;
		break;
	case 1:
		tempPos.x = myRec.getPosition().x - m_speed;
		tempPos.y = myRec.getPosition().y;
		if (checkLimits(tempPos, limits))
			_nextPos = tempPos;
		else {
			dir = NONE;
			return;
		}


		dir = LEFT;
		break;
	case 2:
		tempPos.x = myRec.getPosition().x;
		tempPos.y = myRec.getPosition().y + m_speed;
		if (checkLimits(tempPos, limits))
			_nextPos = tempPos;
		else {
			dir = NONE;
			return;
		}
		dir = UP;
		break;
	case 3:
		tempPos.x = myRec.getPosition().x;
		tempPos.y = myRec.getPosition().y - m_speed;
		if (checkLimits(tempPos, limits))
			_nextPos = tempPos;
		else {
			dir = NONE;
			return;
		}
		dir = DOWN;
		break;
	default:
		break;
	}
}

int Enemy::getEnemyNum() 
{
	return m_Enemy_count;
}
int  Enemy::m_Enemy_count = 0;


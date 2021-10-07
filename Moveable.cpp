#include "Moveable.h"


Moveable::Moveable() :m_defaul_speed(10)
{
	m_speed = (int)m_defaul_speed;
}

//Moveable::Moveable(Moveable & other): m_defaul_speed(10)
//{
//
//	this->_nextPos = other.myRec.getPosition();
//	dir = NONE;
//	killed = false;    
//}



Moveable::Moveable(int i, int j, char type) : GameObject(i, j, type), m_defaul_speed(10)
{
	dir = NONE;
	killed = false; 
	success = false;
	_nextPos = myRec.getPosition();
	m_speed = (int)m_defaul_speed;
}

Moveable::Moveable(sf::Vector2f) : m_defaul_speed(10)
{
	m_speed = (int)m_defaul_speed;
}

//void Moveable::setmovment(sf::Vector2i movment)
//{
//	/*if (movment.x == 1) {
//		_nextPos.x = myRec.getPosition().x + m_speed;
//		_nextPos.y = myRec.getPosition().y;
//		dir = RIGHT;
//	}
//	else if (movment.x == -1) {
//		_nextPos.x = myRec.getPosition().x - m_speed;
//		_nextPos.y = myRec.getPosition().y;
//		dir = LEFT;
//	}
//	else if (movment.y == 1) {
//		_nextPos.x = myRec.getPosition().x;
//		_nextPos.y = myRec.getPosition().y + m_speed;
//		dir = UP;
//	}
//	else if (movment.y == -1) {
//		_nextPos.x = myRec.getPosition().x;
//		_nextPos.y = myRec.getPosition().y - m_speed;
//		dir = DOWN;
//	}*/
//
//}

sf::Vector2f Moveable::getnext(sf::Vector2i robotPos, sf::Vector2u limits)
{

	return _nextPos;
}
void Moveable::setDefault()
{
	_nextPos = m_default_pos;
	killed = false;
	myRec.setPosition(m_default_pos);
}
void Moveable::changeSpeed(float, int time)
{
}

void Moveable::setScore(int)
{
}

int Moveable::getScore() const 
{
	return 0;
}

void Moveable::setColor(sf::Color)
{
}


sf::FloatRect  Moveable::getDirectionPos() const 
{
	sf::FloatRect boundRect = myRec.getGlobalBounds();
	switch (dir) {
	case LEFT:
		boundRect.left = boundRect.left - m_speed;
		break;
	case RIGHT:
		boundRect.left = boundRect.left + m_speed  ;
		break;
	case UP:
		boundRect.top = boundRect.top   + m_speed  ;
		break;
	case DOWN:
		boundRect.top = boundRect.top  - m_speed  ;
		break;
	}
	return boundRect;


}
void Moveable::updateSpeed()
{
	m_speed = (int)m_MoveableClock.getElapsedTime().asSeconds() + 10;

	if (m_MoveableClock.getElapsedTime().asSeconds() >= 15) {
		m_speed = (int) m_defaul_speed;
	}


}


bool Moveable::checkLimits(sf::Vector2f position, sf::Vector2u limits)
{
	
	if (position.x >= 0 && position.x + (55 - this->m_speed) < limits.y  && position.y >= 0 && position.y + (55 - this->m_speed) < limits.x ) {
		if (this->getType() == '/') {}

		return true;
	}
	else if(position.x < 0 || position.x + (55 -this->m_speed) >= limits.y || position.y < 0 || position.y + (55 - this->m_speed) >= limits.x){
		/*cout << position.x << " " << position.y << endl;
		cout << limits.x << " " << limits.y << endl;*/
		return false;
	}

	return false;
}
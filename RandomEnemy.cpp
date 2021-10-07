#include "RandomEnemy.h"


RandomEnemy::RandomEnemy()
{
}

RandomEnemy::RandomEnemy(int i, int j, char type):Enemy(i, j, type)
{
	int s = (i*j) % 5;

	myRec.setOutlineColor(sf::Color::White);
	myRec.setSize(sf::Vector2f(50, 50));
	myRec.setTexture(&SingletonTextures::instance().get_randomEnemy());

}

void RandomEnemy::move(sf::Vector2i robotPos, sf::Vector2u limits)
{
    srand(time(NULL));
	int path = (int)(rand() % 4);
	sf::Vector2f tempPos;
	updateSpeed();
	m_speed /= 20;
	

	switch (path)
	{
	case 0:
		tempPos.x = myRec.getPosition().x + m_speed;
		tempPos.y = myRec.getPosition().y;
		moveDirection(RIGHT, limits);
		//dir = RIGHT;
		break;
	case 1:
		tempPos.x = myRec.getPosition().x - m_speed;
		tempPos.y = myRec.getPosition().y;
		moveDirection(LEFT, limits);
		//dir = LEFT;
		break;
	case 2:
		tempPos.x = myRec.getPosition().x;
		tempPos.y = myRec.getPosition().y + m_speed;
		moveDirection(UP, limits);
		//dir = UP;
		break;
	case 3:
		tempPos.x = myRec.getPosition().x;
		tempPos.y = myRec.getPosition().y - m_speed;
		moveDirection(DOWN ,limits);
		//dir = DOWN;
		break;
	default:
		break;
	}
}

RandomEnemy::~RandomEnemy()
{
}

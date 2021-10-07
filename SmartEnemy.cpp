#include "SmartEnemy.h"



SmartEnemy::SmartEnemy()
{
}

SmartEnemy::SmartEnemy(int i, int j, char type) :Enemy(i, j, type)
{

	myRec.setOutlineColor(sf::Color::Transparent);
	myRec.setSize(sf::Vector2f(50, 50));
	myRec.setTexture(&SingletonTextures::instance().get_smartEnemy());
}

void SmartEnemy::move(sf::Vector2i robotPos, sf::Vector2u limits)
{

	
	sf::Vector2i enemyPos = this->get_pos();
	
	int random_num = (rand() % 2);
	
	//------ if the robot and the enemy in the same row ---------
	if (enemyPos.y / 55 == robotPos.y / 55) {
		// if the enemy is righter than the robot , then according to the random number 
		//the enemy go left or right to the direction of the robot 
		if (enemyPos.y / 55 > robotPos.y / 55 && random_num > 0)
			// enemy go left 
			moveDirection(LEFT,limits);
		else
			//enemy go right
			moveDirection( RIGHT, limits);

	}

	//------ if the robot and the enemy in the same cloumn ---------
	if (enemyPos.x / 55 == robotPos.x / 55) {
		// if the enemy is higher than the robot , then according to the random number 
		//the enemy go down or up to the direction of the robot 
		if (enemyPos.x / 55 < robotPos.x / 55 && random_num > 0)
			moveDirection(UP, limits);
		else
			moveDirection(DOWN, limits);


	}

	//------ if the enemy is righter than the robot, but they are not on the same row ---------
	if (enemyPos.x / 55 > robotPos.x / 55) {
		if (random_num > 0)
			// enemy go left 
			moveDirection(LEFT, limits);
		else
			// enemy go up 
			moveDirection(UP, limits);

		
	}

	//------ if the robot is righter than the enemy, but they are not on the same row ---------
	else {
		if (random_num > 0)
			// enemy go right to the direction of the robot 
			moveDirection(RIGHT, limits);
		else
			// enemy go down
			moveDirection(DOWN, limits);

	}


}


SmartEnemy::~SmartEnemy()
{
}

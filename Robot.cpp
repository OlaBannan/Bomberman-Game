#include "Robot.h"


Robot::Robot(int i, int j, char type) : Moveable(i, j, type)
{
	m_score = 0;

	m_lives = 3;
	killed = false;
	myRec.setSize(sf::Vector2f(48, 48));
	myRec.setTexture(&SingletonTextures::instance().get_right_robot());
}

Robot::Robot(const Robot & robot)
{
}

Robot::Robot()
{
}

Robot::~Robot()
{
}

void Robot::setBombNum(int bombs)
{
	m_bombs = bombs;
}

void Robot::addBombNum(int bombs)
{
	m_bombs += bombs;
}

int Robot::getBombNum()
{
	return m_bombs;
}

void Robot::changeSpeed(float changeSpeed, int time) {
	m_speed = m_speed * (int)changeSpeed;
	m_clock.restart();
	m_timer = time;
}

void Robot::setmovment(sf::Vector2i movment, sf::Vector2u limits)
{

	updateSpeed();
	

	if (movment.x == 1) {
		
		tempPos.x = myRec.getPosition().x + m_speed;
		tempPos.y = myRec.getPosition().y;
		if (checkLimits(tempPos, limits)) {
			_nextPos = tempPos;
			m_MoveableClock.restart();
		}
		else {
			dir = NONE;
			myRec.setTexture(&SingletonTextures::instance().get_right_robot());
			return;
		}
		myRec.setTexture(&SingletonTextures::instance().get_right_robot());

		dir = RIGHT;
	}
	else if (movment.x == -1) {
		tempPos.x = myRec.getPosition().x - m_speed;
		tempPos.y = myRec.getPosition().y;
		if (checkLimits(tempPos, limits)) {
			_nextPos = tempPos;
			m_MoveableClock.restart();
		}
		else {
			dir = NONE;
			myRec.setTexture(&SingletonTextures::instance().get_left_robot());
			return;
		}
		myRec.setTexture(&SingletonTextures::instance().get_left_robot());
		dir = LEFT;
	}
	else if (movment.y == 1) {
		tempPos.x = myRec.getPosition().x;
		tempPos.y = myRec.getPosition().y + m_speed;
		if (checkLimits(tempPos, limits)) {
			_nextPos = tempPos;
			m_MoveableClock.restart();
		}
		else {
			dir = NONE;
			myRec.setTexture(&SingletonTextures::instance().get_down_robot());
			return;
		}
		myRec.setTexture(&SingletonTextures::instance().get_down_robot());

		dir = UP;
	}
	else if (movment.y == -1) {
		tempPos.x = myRec.getPosition().x;
		tempPos.y = myRec.getPosition().y - m_speed;
		if (checkLimits(tempPos, limits)) {
			_nextPos = tempPos;
			m_MoveableClock.restart();
		}
		else {
			dir = NONE;
			myRec.setTexture(&SingletonTextures::instance().get_up_robot());
			return;
		}
		myRec.setTexture(&SingletonTextures::instance().get_up_robot());

		dir = DOWN;
	}
	
}

int Robot::getLives() const
{

	return m_lives;
}

void Robot::kill()
{
	m_lives--;
	killed = true;
	change = true;
}



bool Robot::isKill()
{
	if (m_lives <= 0)
		return true;
	return false;
}

/******update texture of the Robot ******/
void Robot::update_TextureRobot(sf::Texture newTexture) {
	m_shape.setTexture(&newTexture);
}

void Robot::change_texture(DIRECTION direct) {

	m_direction = direct;
	move_status(true);

	switch (direct) {
	case UP:
		m_shape.setTexture(&SingletonTextures::instance().get_up_robot());
		break;
	case DOWN:
		m_shape.setTexture(&SingletonTextures::instance().get_down_robot());
		break;
	case LEFT:
		m_shape.setTexture(&SingletonTextures::instance().get_left_robot());
		break;
	case RIGHT:
		m_shape.setTexture(&SingletonTextures::instance().get_right_robot());
		break;
	}
}
void Robot::startScore()
{
	m_score = 0;
}
void Robot::setScore(int score)
{
	m_score += score;
}

int Robot::getScore() const
{
	return m_score;
}

sf::Vector2f Robot::updatePosition()
{
	sf::Vector2f temp;
	temp.x = myRec.getGlobalBounds().top;
	temp.y = myRec.getGlobalBounds().top;

	return(temp);
}


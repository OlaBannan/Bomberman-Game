#pragma once
#include "Texture.h"
#include "Moveable.h"


class Robot : public Moveable
{
private:
	int m_lives;
	int m_bombs;
	int m_timer;
	int m_score;
	int Robotx, Roboty;
	sf::RectangleShape m_shape;
	enum DIRECTION m_direction;

public:
	Robot();
	Robot(int i, int j, char type);
	Robot(const Robot& robot);
	void setBombNum(int bombs);
	void addBombNum(int bombs);
	virtual void setSuccess(bool condition) { success = condition; };
	virtual bool  getSuccess() { return success; };
	int getBombNum();
	int getX() const { return this->Robotx; }
	int getY() const { return this->Roboty; }
	sf::Vector2f updatePosition();
	void changeSpeed(float, int);
	sf::Vector2f tempPos;
	virtual void setmovment(sf::Vector2i movment, sf::Vector2u limits);
	int getLives() const;
	virtual void kill();
	virtual bool isKill();
	void setScore(int);
	int getScore() const;
	void startScore();
	virtual void update_TextureRobot(sf::Texture);
	virtual void change_texture(DIRECTION);
	~Robot();
};


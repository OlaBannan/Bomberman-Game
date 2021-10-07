#pragma once
#include "GameObject.h"
class Controller;

class Moveable : public GameObject
{
public:
	Moveable();
	Moveable(int i, int j, char type);
	Moveable(sf::Vector2f);
	virtual sf::Vector2f getnext(sf::Vector2i robotPos, sf::Vector2u limits);
	bool checkLimits(sf::Vector2f, sf::Vector2u);
	void setDefault();
	void changeSpeed(float, int);
	virtual void setScore(int);
	virtual void setSuccess(bool condition) { };
	virtual bool  getSuccess() const  { return success; };
	virtual void addBombNum(int bombs) {};
	virtual int getScore() const  ;
	virtual void setColor(sf::Color);
	sf::FloatRect getDirectionPos() const ;
	void move_status(bool move) { go = move; }
	virtual ~Moveable() = 0 {};
protected:
	int m_speed;
	bool go;
	bool success;
	sf::Clock m_MoveableClock;
	sf::Vector2i movment;
	const float m_defaul_speed;
	void updateSpeed();
	sf::Vector2f _nextPos;
	enum DIRECTION  {RIGHT, LEFT, UP, DOWN, NONE };
	DIRECTION dir;


};


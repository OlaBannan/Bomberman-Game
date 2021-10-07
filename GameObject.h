#pragma once
#include "macros.h"

#pragma once
#include <vector>
#include <SFML/Graphics.hpp>

using namespace::std;
class GameObject
{
private:
	
public:
	GameObject();
	GameObject(int i, int j, char type);
	GameObject(int i);
	void restartClock() { m_clock.restart(); }
	void draw(sf::RenderWindow &win);
	virtual bool isclick(sf::Vector2f pos) { return myRec.getGlobalBounds().contains(pos); }
	virtual void setPosition(sf::Vector2f &pos) { this->myRec.setPosition(pos); }
	virtual sf::Vector2i get_pos() { return sf::Vector2i(m_x, m_y); };
	virtual void kill();
	virtual bool isKill();
	virtual bool die() { return killed; };
	virtual void  checked();
	virtual bool  isCheck();
	virtual void  setOrginalsitution(bool situation);
	virtual bool  getOrginalsitution();
	virtual void setAlive();

	virtual int getX()  { return m_x; }
	virtual int getY() { return m_y;  }
	
	virtual void setX(int x) { this->m_x = x; }
	virtual void setY(int y) { this->m_y = y; }
	virtual char getType() { return this->m_type; }
	virtual void setNewPos(sf::Vector2f pos);
	virtual bool changed() { return change; };
	virtual void setChanged() { change = false; };
	virtual sf::Vector2f getDefault() { return(this->m_default_pos); }
	void setDefault();
	bool isContain(sf::FloatRect v);
	virtual ~GameObject() = 0 {};
protected:
	sf::Clock m_clock;
	sf::RectangleShape myRec;
	sf::Texture myTexture;
	bool killed;
	bool m_checked;
	bool change;
	bool Orginal;
	int m_x, m_y;
	sf::Vector2f m_default_pos;
	char m_type;
};



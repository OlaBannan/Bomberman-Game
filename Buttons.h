#pragma once
#include "Texture.h"

class Buttons
{
public:
	Buttons();
	Buttons(int i);
	Buttons(sf::Vector2f v);
	virtual bool isclick(sf::Vector2f pos) const { return myRec.getGlobalBounds().contains(pos); }
	void draw(sf::RenderWindow &win) const;
	virtual ~Buttons() = 0 {};
private:
	sf::Texture m_texture;
protected:
	sf::RectangleShape myRec;
};


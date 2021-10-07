#pragma once
#include "Buttons.h"
#include "Texture.h"

class Back :public Buttons
{
public:
	Back(int i);
	~Back();
private:
	sf::Texture m_texture;

};
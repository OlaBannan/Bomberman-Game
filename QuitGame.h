#pragma once
#include "Buttons.h"
#include "Texture.h"

class QuitGame :public Buttons
{
public:
	QuitGame(int i);
	~QuitGame();
private:
	sf::Texture m_texture;

};
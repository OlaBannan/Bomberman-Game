#pragma once
#include "GameObject.h"
#include "Macros.h"
#include "Texture.h"
class Quit :public GameObject
{
public:
	Quit();
	Quit(sf::Vector2f);
	~Quit();
};


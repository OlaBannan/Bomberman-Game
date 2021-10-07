#pragma once
#include "GameObject.h"
#include "Macros.h"
#include "Texture.h"
class Start :public GameObject
{
public:
	Start();
	Start(sf::Vector2f);
	~Start();
};


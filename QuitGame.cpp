#include "QuitGame.h"

QuitGame::QuitGame(int i) :Buttons(i)
{

	myRec.setPosition(1800, 10);
	myRec.setSize(sf::Vector2f(100,100));
	myRec.setTexture(&SingletonTextures::instance().get_QuitGame());

}
QuitGame::~QuitGame()
{
}
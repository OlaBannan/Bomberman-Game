#include "Back.h"

Back::Back(int i) :Buttons(i)
{

	myRec.setPosition(900, 600);
	myRec.setSize(sf::Vector2f(100, 100));
	myRec.setTexture(&SingletonTextures::instance().get_back());

}
Back::~Back()
{
}
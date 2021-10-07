#include "GameObject.h"


GameObject::GameObject()
{
	
}
//constructor 
GameObject::GameObject(int i, int j, char type)
{
	this->m_x = i;
	this->m_y = j;
	this->m_type = type;
	killed = false;
	change = false;
	m_checked = false;
	Orginal = true;
	myRec.setSize(sf::Vector2f(55, 55));
	m_default_pos = sf::Vector2f((float)(55 * j), (float)(55 * i));
	myRec.setPosition(m_default_pos);

}

GameObject::GameObject(int i)
{
}
// draw the object's rectangle 
void GameObject::draw(sf::RenderWindow &win)
{
	win.draw(myRec);
}

// killed the object 
void GameObject::kill()
{
	killed = true;
}

//check if the object has been killed 
bool GameObject::isKill()
{
	return killed;
}

// set new position for the object 
void GameObject::setNewPos(sf::Vector2f pos)
{
	m_x = (int)pos.x;
	m_y = (int)pos.y;
	myRec.setPosition(pos);
}

//set the default position of the object 
void GameObject::setDefault()
{
	myRec.setPosition(m_default_pos);
	killed = false;
}


bool GameObject::isContain(sf::FloatRect v)
{
	return myRec.getGlobalBounds().intersects(v);

}

// return onject from killed to not killed (killed == false)
void GameObject::setAlive()
{
	killed = false;
}

//mark that the object has been checked 
void GameObject::checked()
{
	m_checked = true; 
}

// check if the object has been checked 
bool GameObject::isCheck()
{
	return m_checked;
}

// set the situation( every object has one from two sitiuatio, or it's orginal which mean
//the it was in the stage building process or not orginal like giftunder brike which was not before the brike exploded 
void GameObject::setOrginalsitution(bool situation)
{
	Orginal = situation;
}

//get the situation of the object 
bool GameObject::getOrginalsitution()
{
	return Orginal;
}
#include "EmptyCell.h"



EmptyCell::EmptyCell(int i, int j, char type) : UnMoveable(i, j, type)
{
	myRec.setTexture(&SingletonTextures::instance().get_emptyCell());
}


EmptyCell::~EmptyCell()
{
}

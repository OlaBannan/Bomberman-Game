#include "Texture.h"

SingletonTextures::SingletonTextures()
{
	//-----load from file for every images-----
	
	m_LeftPacman.loadFromFile(LEFTPACMAN);
	m_RightPacman.loadFromFile(RIGHTPACMAN);
	m_UpPacman.loadFromFile(UPPACMAN);
	m_DownPacman.loadFromFile(DOWNPACMAN);
	m_SmartEnemy.loadFromFile(SMARTENEMY);
	m_RandomEnemy.loadFromFile(RANDOMENEMY);
	m_Wall.loadFromFile(WALL);
	m_Brick.loadFromFile(BRICK);
	m_Door.loadFromFile(DOOR);
	m_Gift.loadFromFile(GIFT);
	m_emptyCell.loadFromFile(EMPTY);
	m_Bomb.loadFromFile(BOMB);
	m_Falme.loadFromFile(FLAME);
	m_QuitGame.loadFromFile(QUIT);
	m_Gameover.loadFromFile(GAMEOVER);
	m_wordGameover.loadFromFile(WORDGAMEOVER);
	m_won.loadFromFile(WON);


	m_Back.loadFromFile(BACK);

	m_StartGame.loadFromFile(STARTGAME);
	m_HelpGame.loadFromFile(HELPGAME);
	m_ExitGame.loadFromFile(EXITGAME);
	m_InfoGame.loadFromFile(INFOGAME);
	m_GameOverBackGround.loadFromFile(GAMEOVERBACKGROUND);
}

//*******************************************
SingletonTextures::~SingletonTextures() {}

//*******************************************
SingletonTextures SingletonTextures::m_instance = SingletonTextures();
//*******************************************
SingletonTextures& SingletonTextures::instance() {
	return m_instance;
}


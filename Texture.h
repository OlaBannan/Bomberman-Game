#pragma once


#include<iostream>
#include <SFML/Graphics.hpp>
#include"macros.h"

using std::cout;
using std::endl;


class SingletonTextures
{
public:
	~SingletonTextures();
	static SingletonTextures& instance();

	
	sf::Texture& get_wall() { return m_Wall; }
	sf::Texture& get_brick() { return m_Brick; }
	sf::Texture& get_door() { return m_Door; }
	sf::Texture& get_gift() { return m_Gift; }
	sf::Texture& get_emptyCell() { return m_emptyCell; }
	

	sf::Texture& get_down_robot() { return m_DownPacman; }
	sf::Texture& get_up_robot() { return m_UpPacman; }
	sf::Texture& get_left_robot() { return m_LeftPacman; }
	sf::Texture&get_right_robot() { return m_RightPacman; }

	sf::Texture& get_randomEnemy() { return m_RandomEnemy; }
	sf::Texture& get_smartEnemy() { return m_SmartEnemy; }
	
	sf::Texture& get_bomb() { return m_Bomb ; } 
	sf::Texture& get_flame() { return m_Falme ; }


	sf::Texture& get_startgame() { return m_StartGame; }
	sf::Texture& get_exitgame() { return m_ExitGame; }
	sf::Texture& get_helpgame() { return m_HelpGame; }
	sf::Texture& get_infogame() { return m_InfoGame; }
	sf::Texture& get_gameover() { return m_Gameover; }
	sf::Texture& get_back() { return m_Back; }
	sf::Texture& get_wordsgameover() { return m_wordGameover; }
	sf::Texture& get_gameoverbackground() { return m_GameOverBackGround; }
	sf::Texture& get_QuitGame() { return m_QuitGame; }
	sf::Texture& get_won() { return m_won; }



	//**********************************************************
private:
	SingletonTextures();

	static SingletonTextures m_instance;
	sf::Texture m_LeftPacman;
	sf::Texture m_RightPacman;
	sf::Texture m_UpPacman;
	sf::Texture m_DownPacman;
;
	sf::Texture m_RandomEnemy;
	sf::Texture m_SmartEnemy;
	sf::Texture m_Bluemonster;
	sf::Texture m_Wall;
	sf::Texture m_Gift;
	sf::Texture m_Door;
	sf::Texture m_Brick;
	sf::Texture m_emptyCell;
	sf::Texture m_Bomb;
	sf::Texture m_Falme;
	sf::Texture m_StartGame;
	sf::Texture m_ExitGame;
	sf::Texture m_HelpGame;
	sf::Texture m_InfoGame;
	sf::Texture m_Gameover;
	sf::Texture m_wordGameover;
	sf::Texture m_GameOverBackGround;
	sf::Texture m_Back;
	sf::Texture m_QuitGame;
	sf::Texture m_won;

	
};


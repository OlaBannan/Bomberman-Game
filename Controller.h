#pragma once
#include "macros.h"
#include "GameBoard.h"
#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include "Bomb.h"
#include "Collision.h"
#include "Buttons.h"
#include "Flame.h"
#include "Back.h"
#include "Start.h"
#include "Quit.h"
#include "Help.h"


class Controller
{
private:
	int length;
	int width;
	string stageName;
	int numofStage;
	ifstream UpdatestagefileName();
	GameBoard Board;
	void readFile(ifstream &stage);
	void openFile(ifstream &stage);
	void buildLevel(int N, int M, vector<vector<char>> charMatrix);
	vector<UnMoveable*> m_unMovable;
	vector<Moveable *>m_moveable;
	sf::RectangleShape m_play, m_exit, m_help, m_info, m_gameover, m_won;	
	vector<Bomb *>m_bomb;
	vector<Flame *> m_flame;
	void spreadFlames(sf::Vector2i centerpos);
	int m_count_bomb;
	void draw(sf::RenderWindow &win) const ;
	int robot_pos;
	void collisions();
	void Gameover();
	sf::Vector2i nextRobotPos;
	bool isValid(int i, int j);
	bool makeCollision(Moveable * m, GameObject* u, sf::Vector2f nextPos);
	sf::Vector2i getRobotPos();
	map<pair<string, string>, Collision*> mymap;
	bool placeBomb(sf::RenderWindow &win);
	void restDefault();
	void deleteKilled();
	void deleteArrays();
	sf::Vector2u getLimits();
	int time;
	int m_time;
	GameBoard* board;
	sf::Clock GameTimer;
	void setTime(int time);
	int getTime();
	int numofBombs;
	bool nonLimitsTime;
	bool nonLimitsBombs;
	void Won(int score) ;
	void removeFalmes(sf::Vector2f robotdefault);
	void removeBombs(sf::Vector2f m);
	int endStagenum;
	void resetMoveableDefault();
	static int TotalScore;
	
public:
	
	int open();
	bool startGame();
	void help();
	~Controller();
	int getTotalScore() const ;
	Controller(int num, int end);

};


#pragma once

#ifdef _DEBUG
#pragma comment(lib, "sfml-main-d.lib")
#pragma comment(lib, "sfml-system-d.lib")
#pragma comment(lib, "sfml-window-d.lib")
#pragma comment(lib, "sfml-graphics-d.lib")
#pragma comment ( lib , "sfml-audio-d.lib" )
#elif defined(NDEBUG)
#pragma comment(lib, "sfml-main.lib")
#pragma comment(lib, "sfml-system.lib")
#pragma comment(lib, "sfml-window.lib")
#pragma comment(lib, "sfml-graphics.lib")
#else
#error "Unrecognized configuration!"
#endif
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <windows.h>
#include <conio.h> 
#include <stdio.h>


using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::vector;
using std::ifstream;


const char CROBOT = '/';
const char CRANDOMENMEY = '%';
const char CSMARTENEMY = 'S';
const char CWALL = '#';
const char CSPACE = ' ';
const char CGIFT = '+';
const char CBRICK = '@';
const char CDOOR = 'D';

enum DIRECTION { RIGHT, LEFT, UP, DOWN };

const int KB_UP = 72;
const int KB_DOWN = 80;
const int KB_LEFT = 75;
const int KB_RIGHT = 77;
const int KB_SPACE = 32;
const int KB_b = 62;
const int SPECIAL_KEY = 224;


const std::string TEXT_FILEPATH = "board.txt";
const std::string LEFTPACMAN = "icon/left_robot.png";
const std::string RIGHTPACMAN = "icon/right_robot.png";
const std::string UPPACMAN = "icon/up_robot.png";
const std::string DOWNPACMAN = "icon/down_robot.png";
const std::string RANDOMENEMY = "icon/randomEnemy.png";
const std::string SMARTENEMY = "icon/smartEnemy.png";
const std::string WALL = "icon/Wall.png";
const std::string BRICK = "icon/brick.png";
const std::string DOOR = "icon/door.png";
const std::string EMPTY = "icon/empty.png";
const std::string GIFT = "icon/gift.png";
const std::string BOMB = "icon/bomb.png";
const std::string FLAME = "icon/flame.png";

const std::string STARTGAME = "icon/play.png";
const std::string EXITGAME = "icon/exit.png";
const std::string HELPGAME = "icon/help.png";
const std::string INFOGAME = "icon/information.png";
const std::string BACK = "icon/bb.png";
const std::string QUIT = "icon/Quitgame.png";
const std::string GAMEOVER = "icon/gameover.png";
const std::string WORDGAMEOVER = "icon/wordgameover.png";
const std::string WON= "icon/won.png";
const std::string GAMEOVERBACKGROUND = "icon/gameoverbackground.png";




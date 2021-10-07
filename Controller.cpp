#include "Controller.h"
#include "GameBoard.h"
#include "Brick.h"
#include "Gift.h"
#include "Wall.h"
#include "Door.h"
#include "EmptyCell.h"
#include "RandomEnemy.h"
#include "SmartEnemy.h"
#include "Robot.h"
#include "GiftUnderBrick.h"
#include "SEnemyRobotColl.h"
#include "RobotREnemyColl.h"
#include "RobotSEnemyColl.h"
#include "RobotGiftColl.h"
#include "REnemyFlameColl.h"
#include "RobotFlameColl.h"
#include "SEnemyFlameColl.h"
#include "REnemyRobotColl.h"
#include "RobotDoorColl.h"
#include "QuitGame.h"
#include <time.h>  


using std::pair;

//constructer for the controller 
Controller::Controller(int num, int end)
	:numofStage(num), endStagenum(end)
{
	mymap.insert(pair<pair<string, string>, Collision*>(pair<string, string>(typeid(SmartEnemy).name(), typeid(Robot).name()), new SEnemyRobotcoll()));
	mymap.insert(pair<pair<string, string>, Collision*>(pair<string, string>(typeid(Robot).name(), typeid(SmartEnemy).name()), new RobotSEnemyColl()));
	mymap.insert(pair<pair<string, string>, Collision*>(pair<string, string>(typeid(RandomEnemy).name(), typeid(Robot).name()), new REnemyRobotColl()));
	mymap.insert(pair<pair<string, string>, Collision*>(pair<string, string>(typeid(Robot).name(), typeid(RandomEnemy).name()), new RobotREnemyColl()));
	mymap.insert(pair<pair<string, string>, Collision*>(pair<string, string>(typeid(Robot).name(), typeid(Door).name()), new RobotDoorColl()));
    mymap.insert(pair<pair<string, string>, Collision*>(pair<string, string>(typeid(Robot).name(), typeid(Gift).name()), new RobotGiftColl()));
	mymap.insert(pair<pair<string, string>, Collision*>(pair<string, string>(typeid(Robot).name(), typeid(Flame).name()), new RobotFlameColl()));
	mymap.insert(pair<pair<string, string>, Collision*>(pair<string, string>(typeid(RandomEnemy).name(), typeid(Flame).name()), new REnemyFlameColl()));
	mymap.insert(pair<pair<string, string>, Collision*>(pair<string, string>(typeid(SmartEnemy).name(), typeid(Flame).name()), new SEnemyFlameColl()));
	board = new GameBoard();


	m_count_bomb = 0;
	stageName = "stage";
	//build the Game's Board
	board->insertTomenu(new Start(sf::Vector2f(300, 800)));
	board->insertTomenu(new Help(sf::Vector2f(900, 800)));
	board->insertTomenu(new Quit(sf::Vector2f(1500, 800)));
	
}

Controller::~Controller()
{
}

//the main function of the controller, that take one stage and work on it 
bool Controller::startGame()
{
	//get the name stage 
	 ifstream currStage = UpdatestagefileName();
	 //open the file and build the level
	 openFile(currStage);
	 bool quitGame = false;

	 // ----  all the relates to the design of the window ----------------------
	 Buttons* quit = new QuitGame(0);
	 sf::RenderWindow window(sf::VideoMode::getDesktopMode(), "Bomberman");
	 sf::Event event;
	 sf::Font font1, font2, font3;// fonts to write
	 sf::Text score, live, bombPutted, bombRemain,numScore,numLives,timeText,timer, numPutted, numRemain,stageWord, stageN;

	 // play the background music 
	 sf::Music music_background;
	 if (!music_background.openFromFile("sound/stage.ogg"))
		 exit(EXIT_FAILURE); // error
	 music_background.play();
	


	 window.clear();
	 Robot * robot = dynamic_cast<Robot *>(m_moveable[robot_pos]);
	 bool bombPlaced = false;
	 setTime(time);
	 robot->setBombNum(numofBombs + 1);
	
	 font2.loadFromFile("icon/capitals.ttf");
	 font1.loadFromFile("icon/arial.ttf");
	 font3.loadFromFile("icon/Pacifico.ttf");
	 score.setFont(font2);
	 live.setFont(font2);
	 bombPutted.setFont(font2);
	 bombRemain.setFont(font2);
	 timeText.setFont(font2);
	 stageWord.setFont(font3);
	 score.setString("your score = ");
	 timeText.setString("time = ");
	 live.setString("your lives = ");
	 bombPutted.setString("you have put  = ");
	 bombRemain.setString("bombs remain =");
	 stageWord.setString("Stage number ");
	 stageWord.setStyle(sf::Text::Underlined);
	 numScore.setFont(font1);
	 timer.setFont(font1);
	 numLives.setFont(font1);
	 numPutted.setFont(font1);
	 numRemain.setFont(font1);
	 stageN.setFont(font1);

	 score.setPosition(20, 600);
	 numScore.setPosition(200, 600 );
	 live.setPosition(20, 750);
	 numLives.setPosition(200, 750);
	 bombPutted.setPosition(20, 900);
	 numPutted.setPosition(250, 900);
	 timeText.setPosition(400, 600);
	 timer.setPosition(500, 600);
	 bombRemain.setPosition(400, 750);
	 numRemain.setPosition(620, 750);
	 stageWord.setPosition( 1400, 20);
	 stageN.setPosition(1600,20);
	


	 //--- Main loop ---------------------------------------------------
	 while (window.isOpen())
	 {
		// bool find = false;
		 int lives = robot->getLives();

		 for (int i = 0; i < (int)m_bomb.size(); i++) {

			 bool expired = m_bomb[i]->setbomb();
			 if (expired == TRUE) {
				 spreadFlames(m_bomb[i]->get_pos());
				 sf::SoundBuffer background_s;
				 music_background.setVolume(0);
	         if (!background_s.loadFromFile("sound/explode.wav"))
	            	return EXIT_FAILURE;
	              sf::Sound sound1(background_s);
	                  sound1.play();
					  Sleep(250);
	               sound1.setLoop(true);
				   sound1.setVolume(100);
				   music_background.setVolume(100);

			 }
		 }

		
		 sf::Vector2i movment = sf::Vector2i(0, 0);

		 while (window.pollEvent(event))
		 {//up down right left keys

			 switch (event.type)
			 {
			 case sf::Event::KeyPressed: {
				 if (event.key.code == sf::Keyboard::Up)
					 movment = sf::Vector2i(0, -1);
				 else if (event.key.code == sf::Keyboard::Down)
					 movment = sf::Vector2i(0, 1);
				 else if (event.key.code == sf::Keyboard::Left)
					 movment = sf::Vector2i(-1, 0);
				 else if (event.key.code == sf::Keyboard::Right)
					 movment = sf::Vector2i(1, 0);
				 else if (event.key.code == sf::Keyboard::B) {
					 if (nonLimitsBombs == false && robot->getBombNum() == 0)
						 break;
					 bombPlaced = placeBomb(window);
					 if (bombPlaced == true) {
						 robot->setBombNum(robot->getBombNum() - 1);
						 if(nonLimitsBombs== false && m_count_bomb == numofBombs)
						 m_count_bomb += 1;
						 else 
							 m_count_bomb += 1;
					 }
				 }
				 break;
			 }
			 case sf::Event::MouseButtonPressed:
				 if (quit->isclick(sf::Vector2f((float)event.mouseButton.x, (float)event.mouseButton.y)))
				 {
					 robot->kill();
					 restDefault();
					 robot = dynamic_cast<Robot *>(m_moveable[robot_pos]);
					 robot->startScore();
					 robot->setBombNum(numofBombs);
					 setTime(time);
				 }
				 break;
			 case sf::Event::Closed: {
				 // if clicked on X then exit.
				 deleteArrays();
				 TotalScore -= TotalScore;
				 quit->~Buttons();
				 return false;
				 window.clear(sf::Color::Transparent);
				 window.close();
				 
		     	 }
		     	 break;
									 
			 }
		

			 robot->setmovment(movment, getLimits());


			 for (int i = 0; i < (int)m_flame.size(); i++)
				 if (robot->get_pos() == m_flame[i]->get_pos())
					 robot->kill();
		 }
		 
		 // check collisions between the game's objects 
			 collisions();

			 // if there is no lives for the robot
			 if (lives <= 0) {
				 window.clear(sf::Color::Transparent);
				 window.close();
				 deleteArrays();
				 Gameover();
				 return false;
			 }
			 //if robot won on the current stage, but there is another stages to complete 
			 if (numofStage < endStagenum && robot->getSuccess() == true)
			 {
				
				 numofStage++;
				 stageName = "stage";
				 deleteArrays();
				 quit->~Buttons();
				 window.clear(sf::Color::Transparent);
				 window.close();
				 return true;

			 }
			 //if robot won on the whole game
			 if (numofStage == endStagenum && robot->getSuccess() == true)
			 {
				 deleteArrays();
				 window.clear(sf::Color::Transparent);
				 window.close();
				 Won(getTotalScore());
				 return false;
			 }
			 //delete the objects that have been killed (delete == make there boolian variable kill == true)
			 deleteKilled();

			 // check the situation of the flames
			 for (int i = 0; i < (int)m_flame.size(); i++) {
				 m_flame[i]->setFlame();
			 }

			 //if there is a limits on time and the time <=0 
			 if (nonLimitsTime == false && this->getTime()<= 0) {
				 robot->kill();
				 restDefault(); 
				 robot = dynamic_cast<Robot *>(m_moveable[robot_pos]);
				 robot->startScore();
				 robot->setBombNum(numofBombs);
				 setTime(time);
			 }
			 //------------- Update all the Text ---------------------
			numScore.setString(std::to_string(TotalScore));
			numLives.setString(std::to_string(robot->getLives()));

			if (nonLimitsBombs == false)
			numRemain.setString(std::to_string(robot->getBombNum()));

			numPutted.setString(std::to_string(m_count_bomb));

			if(nonLimitsTime == false)
			timer.setString(std::to_string(this->getTime()));

			stageN.setString(std::to_string(numofStage));

	    
		//---------- Draw all the Texts and the Objects -------------------------
		quit->draw(window);
		window.draw(score);
		window.draw(numScore);
		window.draw(live);
		window.draw(numLives);
		window.draw(bombPutted);
		window.draw(numPutted);
		window.draw(stageWord);
		window.draw(stageN);
		if (nonLimitsBombs == false) {
			window.draw(bombRemain);
			window.draw(numRemain);
		}
		if (nonLimitsTime == false) {
			window.draw(timeText);
			window.draw(timer);
		}
		 draw(window);
		 window.display();
		 window.clear(sf::Color::Transparent);
		

	 }
	 return EXIT_SUCCESS;
}

// for updating the file stage name
ifstream Controller::UpdatestagefileName()
{
	char stageNum = '0' + numofStage;
	stageName += stageNum;	
	
	stageName += ".txt";

	ifstream stage(stageName);
	return(stage);
}

// open the file that it's name has been updated 
void Controller::openFile(ifstream &stage) 
{

	if (stage.is_open()) {
		readFile(stage);
		stage.close();
	}
	
	else {
		std::cout << "Can not open the stage file\n";
		exit(EXIT_SUCCESS);
	}

}

//read the file and keepi it's elements 
void Controller::readFile(ifstream &stage)
{
	
	stage >> length;
	stage >> width;
	stage >> time;
	
	if (time == -1)
		nonLimitsTime = true;
	else 
		nonLimitsTime = false ;
	time = (time+1) * 1000;

	stage >> numofBombs;

	if (numofBombs == -1)
		nonLimitsBombs = true;
	else {
		nonLimitsBombs = false;
		numofBombs -= 1;
	}

	vector<vector<char>>Charmatrix(length);
	for (int i = 0; i < length; i++)
	{
		
		stage.get();
		Charmatrix[i].resize(width);
		for (int j = 0; j < width; j++)
			stage >> std::noskipws >> Charmatrix[i][j];
	}
     buildLevel(length, width, Charmatrix); 
}

// set the game's clock time 
void Controller::setTime(int time)
{
	m_time = time;
	//GameTimer.restart();
}

// get the time 
int Controller::getTime()
{
	m_time =  (m_time)-(GameTimer.restart().asSeconds());
	return (m_time/1000);
}

// build the stage ( build the moveable & unmovable vectors)
void Controller::buildLevel(int N, int M, vector<vector<char>> charMatrix)
{

	int random;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			//Creation* element;
			switch (charMatrix[i][j])
			{
			case '#':
				m_unMovable.push_back(new Wall(i, j, '#'));
				break;
			case '+':
				m_unMovable.push_back(new EmptyCell(i, j, ' '));
				m_unMovable.push_back(new Gift(i, j, '+'));
				break;
			case '&':
				m_unMovable.push_back(new EmptyCell(i, j, ' '));
				m_unMovable.push_back(new GiftUnderBrick(i, j, '&'));
				break;
			case 'D':
				m_unMovable.push_back(new EmptyCell(i, j, ' '));
				m_unMovable.push_back(new Door(i, j, 'D'));
				break;
			case '@':
				m_unMovable.push_back(new EmptyCell(i, j, ' '));
				m_unMovable.push_back(new Brick(i, j, '@'));
				break;
			case'%': {
				m_unMovable.push_back(new EmptyCell(i, j, ' '));
				random = (rand()% 4)+1;
				if(random % 2 == 0)
					m_moveable.push_back(new SmartEnemy(i, j, 'S'));
				else 
					m_moveable.push_back(new RandomEnemy(i, j, '%'));	
			}
				break;
			case'/':
				m_moveable.push_back(new Robot(i, j, '/'));
				m_unMovable.push_back(new EmptyCell(i, j, ' '));
				robot_pos =  (int)m_moveable.size() - 1;
				break;
			case ' ':
				m_unMovable.push_back(new EmptyCell(i, j, ' '));
				break;
			}
		}
	}

}

// draw the stage 
void Controller::draw(sf::RenderWindow &win) const {


	for (int i = 0; i < (int)m_unMovable.size(); i++) {
		if (m_unMovable[i]->isKill() == true)
			continue;
		m_unMovable[i]->draw(win);
	}

	for (int i = 0; i < (int)m_bomb.size(); i++) {
		m_bomb[i]->draw(win);
	}
	
	for (int i = 0; i < (int)m_flame.size(); i++) {
		m_flame[i]->draw(win);
	}


	for (int i = 0; i < (int)m_moveable.size(); i++) {
		if (m_moveable[i]->isKill() == true)
			continue;
		m_moveable[i]->draw(win);
	}

	
}

//check all the collisions between all the objects 
void Controller::collisions()
{
	bool reset = false;
	for (int i = 0; i < (int)m_moveable.size(); i++)
	{
		if ((m_moveable[i]->getType() != '/' &&  m_moveable[i]->isKill() == true))
			continue;
		bool isCollide = false;

		sf::Vector2f nextPos = m_moveable[i]->getnext(getRobotPos(), getLimits());

		for (int j = 0; j < (int)m_flame.size(); j++) {
			if (isCollide = makeCollision(m_moveable[i], m_flame[j], nextPos))
				break;
		
		}

			if (!isCollide) {
				for (int j = 0; j < (int)m_moveable.size(); j++) {
					if (i != j) {
						if (m_moveable[j]->isKill() == false) {

							if (isCollide = makeCollision(m_moveable[i], m_moveable[j], nextPos))
							{
								if ((m_moveable[i]->getType() == '/' && m_moveable[i]->die() == true) || (m_moveable[j]->getType() == '/'&& m_moveable[j]->die() == true)) {
									if (m_moveable[i]->getType() == '/')
										m_moveable[i]->setDefault();
									else
										m_moveable[j]->setDefault();

									reset = true;
									break;
								}
								if (isCollide = makeCollision(m_moveable[i], m_moveable[j], nextPos)) {
							
									break;
								}
							}

						}

					}
				}
			}
		
		if (!isCollide) {
			for (int j = 0; j < (int)m_unMovable.size(); j++) {
				
				if(m_unMovable[j]->isKill() == false)
			     	if (isCollide = makeCollision(m_moveable[i], m_unMovable[j], nextPos))
					break;
			}
		}
		

		if (!isCollide) 
			m_moveable[i]->setNewPos(nextPos);
	}
}

//pass to the situable class according to the type of the objects 
bool Controller::makeCollision(Moveable * m, GameObject* u, sf::Vector2f nextPos)
{
	bool isCollide = false;

	if (u->isContain(m->getDirectionPos()))
	{

		if (u->getType() == '#' || u->getType() == '@')
			return true;
		if (u->getType() == ' ')
			return false;
			
		if ((m->getType() == '%' || m->getType() == 'S') && (u->getType() == 'D' || u->getType() == '+'))
			return false;


		if (m->getType() == '/' && u->getType() == 'D') {
			m->setSuccess(true);
			int num;
			num = (Enemy::getEnemyNum());
			m->setScore((num + 1) * 20);
			TotalScore += m->getScore();
			return false;
		}

		
            
		isCollide = true;
		try {
			Collision* col = mymap.at(std::pair<string, string>(typeid(*m).name(),
				typeid(*u).name()));
			col->collide(m, u, getLimits());

			if (m->getType() == '/' && m->changed() == true) {
				removeFalmes(m->getDefault());
				removeBombs(m->getDefault());
				resetMoveableDefault();
				m->setChanged();
			}
			if ((m->getType() == '%' || m->getType() == 'S') && (u->getType() == '^')) {
				int num;
				num = (Enemy::getEnemyNum());
				m_moveable[robot_pos]->setScore((num + 1) * 5);
				TotalScore += m_moveable[robot_pos]->getScore();

			}

		}
		catch (exception e) {}
	}
	return isCollide;
}

// get the robot position on the board 
sf::Vector2i Controller::getRobotPos()
{
	return(m_moveable[robot_pos]->get_pos());
}

// get the limits of the stage (length & width that have been read from the stage file)
sf::Vector2u Controller::getLimits()
{
	sf::Vector2u size;
	
	size.x = length * 55;
	size.y = width * 55;
	return (size);
}

//place the bomb 
bool Controller::placeBomb(sf::RenderWindow &win)
{
	sf::Vector2i tempPos;

	//tempPos = win.mapPixelToCoords(m_moveable[robot_pos]->get_pos());
	tempPos = m_moveable[robot_pos]->get_pos();
	

	tempPos.x = (int)(tempPos.x / 55);

	 tempPos.y = (int)(tempPos.y / 55);


		

		
	//check that there is no bomb in the same position 
	for (int k = 0; k < (int)m_bomb.size(); k++)
		if (m_bomb[k]->getX() == tempPos.x && m_bomb[k]->getY() == tempPos.y)
			if(m_bomb[k]->getX() < 0 || m_bomb[k]->getX() > (int)getLimits().x || m_bomb[k]->getY() < 0 || m_bomb[k]->getY() > (int)getLimits().y)
			return false;

	
	m_bomb.push_back(new Bomb(tempPos.y, tempPos.x, 'B'));
	return true;
}

// reset the game, like the beginning 
void Controller::restDefault()
{

	/*for (int i = m_unMovable.size() - 1; i >= 0; i--)
	{
		if (m_unMovable[i]->getOrginalsitution() == false)
			m_unMovable[i]->kill();
	}*/
	for (int i = (int)m_unMovable.size() - 1; i >= 0 ; i--)
	{
		if (m_unMovable[i]->getOrginalsitution() == false)
			continue;
		m_unMovable[i]->setDefault();
		m_unMovable[i]->setAlive();
        
	}

	for (int i = (int)m_moveable.size() - 1; i >= 0; i--)
	{
		m_moveable[i]->setDefault();
		m_unMovable[i]->setAlive();
	}
}

//spread all the flames (center, up, down, right, left)
void Controller::spreadFlames(sf::Vector2i centerpos)
{
	int centerX = centerpos.x;
	int centerY = centerpos.y;
	bool change = false;

	
	if(isValid((centerX + 1), centerY) == TRUE && change == false)
	  m_flame.push_back(new Flame((centerX + 1), centerY,'^'));
	
	if (isValid(centerX ,( centerY+1)) == TRUE && change == false)
	m_flame.push_back(new Flame( centerX ,( centerY+1), '^'));
	
	if (isValid((centerX - 1), centerY) == TRUE && change == false)
	m_flame.push_back(new Flame((centerX - 1), centerY, '^'));
	 
	if (isValid(centerX , (centerY -1)) == TRUE && change == false)
	m_flame.push_back(new Flame(centerX, (centerY - 1), '^'));
	
	m_flame.push_back(new Flame(centerX, centerY, '^'));

}

//check if its vaild to put flame in the position (i , j)
bool Controller::isValid(int i, int j)
{
	int x, y;
	

	//	//kill the enemy with the flames 
	for (int k = 0; k < (int)m_unMovable.size(); k++) {
		x = m_unMovable[k]->getX();
		y = m_unMovable[k]->getY();
		if (i < 0 || i >= ((int)getLimits().x / 55) || j < 0 || j >= (int)getLimits().y / 55)
			return false;
		//wall will not remove 
		else if (m_unMovable[k]->getType() == '#' && (x == i && y == j))
			return false;
		//kill the Brick and the GiftBrick
		else if ((m_unMovable[k]->getType() == '@' || m_unMovable[k]->getType() == '&') && (x == i && y == j)){
			m_unMovable[k]->kill();
		return true;
	     }
	}
		for (int k = 0; k < (int)m_moveable.size(); k++) {
			//if (m_moveable[k]->getType() == '%') 
			sf::Vector2i tempPos = m_moveable[k]->get_pos();
			
			x = (tempPos.x / 55);
			y = (tempPos.y / 55);

			if (i < 0 || i >= ((int)getLimits().x / 55) || j < 0 || j >= (int)getLimits().y / 55)
				return false;

			else if (m_moveable[k]->getType() == '/' && (x == j && y == i))
			{
				m_moveable[k]->kill();
				return true;
			}
			 else if ((m_moveable[k]->getType() == 'S' || m_moveable[k]->getType() == '%') && (x == j && y == i)) {
				m_moveable[k]->kill();
				int num;
				num = (Enemy::getEnemyNum());
				m_moveable[robot_pos]->setScore((num + 1) * 5);
				TotalScore += m_moveable[robot_pos]->getScore();
				return true;
			}
		}
	

	return true;
}

//delete all the objects that have been killed (delete mean to update their boolien variable kill == true)
void Controller::deleteKilled()
{
	sf::Vector2i tempPos;
	
	for (int i = (int)m_unMovable.size() - 1; i >= 0; i--)
	{
		
		if (m_unMovable[i]->isKill() == true) {
			if (m_unMovable[i]->getType() == '&'  && m_unMovable[i]->isCheck() == false) {
				m_unMovable[i]->checked();
				tempPos = m_unMovable[i]->get_pos();
				m_unMovable.push_back(new Gift(tempPos.x, tempPos.y, '+'));
				m_unMovable[(int)m_unMovable.size() - 1]->setOrginalsitution(false);
			}
			else if (m_unMovable[i]->getType() == '+' && m_unMovable[i]->getOrginalsitution() == false) {
				m_unMovable[i]->~UnMoveable();
				m_unMovable.erase(m_unMovable.cbegin() + i);
			}
			
			
		}
	}

	for (int i = (int)m_bomb.size() - 1; i >= 0; i--)
	{
		if (m_bomb[i]->isKill()) {
			m_bomb[i]->~Bomb();
			m_bomb.erase(m_bomb.cbegin() + i);
		}
	}

	for (int i = (int)m_flame.size() - 1; i >= 0; i--)
	{
		if (m_flame[i]->isKill()) {
			m_flame[i]->~Flame();
			m_flame.erase(m_flame.cbegin() + i);
		}
	}

}

//open the board, (board has play, help, quit buttons )
int Controller::open()
{

	sf::Music music_begin;
	if (!music_begin.openFromFile("sound/bomberman_beginning.ogg"))
		exit(EXIT_FAILURE); // error
	music_begin.play();

	sf::RenderWindow Menu(sf::VideoMode::getDesktopMode(), "Bomberman");
	sf::Texture tex;
	tex.loadFromFile("icon/Background.jpg");
    sf::Sprite sprite(tex);

	while (Menu.isOpen())
	{
		
		Menu.draw(sprite);
		board->drawMenu(Menu);
		Menu.display();
		sf::Event event;
		while (Menu.pollEvent(event))
		{
			//int i=board->checkButtons(event);
			switch (event.type)
			{
			case sf::Event::MouseButtonPressed:
				for (int i = 0; i < (int)(signed)board->m_menu.size(); i++) {
					if (board->m_menu[i]->isclick((sf::Vector2f((float)(event.mouseButton.x), (float)(event.mouseButton.y)))))
						return (int)i;
				}
				break;
			case sf::Event::Closed:
				return 3;
			}
		}
		Menu.clear(sf::Color::Transparent);

	}

	return 0;
}

// the game is over 
void Controller::Gameover()
{
	sf::RenderWindow gameover(sf::VideoMode(700,900), "Game Over");
	TotalScore -= TotalScore;
	m_info.setPosition(100, 100);
	m_info.setSize(sf::Vector2f(550, 600));
	m_info.setTexture(&(SingletonTextures::instance().get_gameover()));
	
	m_gameover.setPosition(100, 600);
	m_gameover.setSize(sf::Vector2f(500, 300));
	m_gameover.setTexture(&(SingletonTextures::instance().get_wordsgameover()));


	TotalScore -= TotalScore;
	while (gameover.isOpen())
	{
		gameover.draw(m_info);
		gameover.draw(m_gameover);
		//temp->draw(gameover);
		gameover.display();
		sf::Event event;
		while (gameover.pollEvent(event))
		{
			switch (event.type)
			{	
			case sf::Event::Closed: {
				TotalScore -= TotalScore;
				gameover.close();
			}
				break;
			}
		}
		gameover.clear(sf::Color::Transparent);
	}

}

// the robot won the game 
void Controller::Won(int score ) 
{
	sf::Font font4;
	font4.loadFromFile("icon/GrandHotel-Regular.otf");
	sf::Text scorestr, scorenum;
	scorestr.setFont(font4);
	scorestr.setPosition(200, 400);
	scorestr.setScale(4.f, 1.6f);
	scorenum.setFont(font4);
	scorenum.setPosition(700, 400);
	scorenum.setScale(4.f, 1.6f);
	scorestr.setString("Your score: ");
	scorenum.setString(std::to_string(score));
	scorenum.setFillColor(sf::Color::Cyan);
	scorestr.setFillColor(sf::Color::Cyan);
	



	sf::RenderWindow won(sf::VideoMode(1000, 500), "WON!");
	m_info.setPosition(100, 100);
	m_info.setSize(sf::Vector2f(800, 300));
	m_info.setTexture(&(SingletonTextures::instance().get_won()));

	while (won.isOpen())
	{
		won.draw(m_info);
		won.draw(scorestr);
		won.draw(scorenum);
		won.display();
		sf::Event event;
		while (won.pollEvent(event))
		{
			switch (event.type)
			{
			case sf::Event::Closed:
				won.close();
				break;
			}
		}
		won.clear(sf::Color::Transparent);
	}

}

// help screen 
void Controller::help() 
{
	sf::Music music_instruction;
	if (!music_instruction.openFromFile("sound/instrc.ogg"))
		exit(EXIT_FAILURE); // error
	


	sf::RenderWindow Help(sf::VideoMode::getDesktopMode(), "Bomberman Help");
	Buttons* temp = new Back(0);
	m_info.setPosition(100, 100);
	m_info.setSize(sf::Vector2f(1000, 800));
	m_info.setTexture(&(SingletonTextures::instance().get_infogame()));
	music_instruction.play();

	while (Help.isOpen())
	{
		Help.draw(m_info);
		temp->draw(Help);
		Help.display();
		sf::Event event;
		while (Help.pollEvent(event))
		{
			switch (event.type)
			{
			case sf::Event::MouseButtonPressed:
				if (temp->isclick((sf::Vector2f((float)(event.mouseButton.x), (float)(event.mouseButton.y)))))
				{
					temp->~Buttons();
					Help.close();
					break;
				}
				break;
			case sf::Event::Closed:
				temp->~Buttons();
				Help.close();
				break;
			}
		}
		Help.clear(sf::Color::Transparent);
	}
}

//remove the falmes that is close to the robot default position
void Controller::removeFalmes(sf::Vector2f m)
{
	for (int i = (int)m_flame.size() - 1; i >= 0; i--) {
			if (m_flame[i]->getX() == (m.y / 55) && m_flame[i]->getY() == (m.x / 55)){
			m_flame[i]->~Flame();
	     	m_flame.erase(m_flame.cbegin() + i);
          	}
			else if ((m_flame[i]->getX() == (m.y / 55) && m_flame[i]->getY() == (m.x / 55) + 1)){
				m_flame[i]->~Flame();
				m_flame.erase(m_flame.cbegin() + i);
		    }
			else if ((m_flame[i]->getX() == (m.y / 55) && m_flame[i]->getY() == (m.x / 55) - 1)){
				m_flame[i]->~Flame();
				m_flame.erase(m_flame.cbegin() + i);
		    }
			else if ((m_flame[i]->getX() == (m.y / 55) - 1 && m_flame[i]->getY() == (m.x / 55))){
				m_flame[i]->~Flame();
				m_flame.erase(m_flame.cbegin() + i);
		    }
			else if ((m_flame[i]->getX() == (m.y / 55) + 1 && m_flame[i]->getY() == (m.x / 55))){
				m_flame[i]->~Flame();
				m_flame.erase(m_flame.cbegin() + i);
		    }
		}
}

//remove the Bombs that is close to the robot default position
void Controller::removeBombs(sf::Vector2f m)
{
	for (int i = (int)m_bomb.size() - 1; i >= 0; i--) {
		if (m_bomb[i]->getX() == (m.y / 55) && m_bomb[i]->getY() == (m.x / 55)) {
			m_bomb[i]->~Bomb();
			m_bomb.erase(m_bomb.cbegin() + i);
		}
		else if ((m_bomb[i]->getX() == (m.y / 55) && m_bomb[i]->getY() == (m.x / 55) + 1)) {
			m_bomb[i]->~Bomb();
			m_bomb.erase(m_bomb.cbegin() + i);
		}
		else if ((m_bomb[i]->getX() == (m.y / 55) && m_bomb[i]->getY() == (m.x / 55) - 1)) {
			m_bomb[i]->~Bomb();
			m_bomb.erase(m_bomb.cbegin() + i);
		}
		else if ((m_bomb[i]->getX() == (m.y / 55) - 1 && m_bomb[i]->getY() == (m.x / 55))) {
			m_bomb[i]->~Bomb();
			m_bomb.erase(m_bomb.cbegin() + i);
		}
		else if ((m_bomb[i]->getX() == (m.y / 55) + 1 && m_bomb[i]->getY() == (m.x / 55))) {
			m_bomb[i]->~Bomb();
			m_bomb.erase(m_bomb.cbegin() + i);
		}
	}
}
// at the end of the game, delete all the vectors, using destructor 
void Controller::deleteArrays()
{
	for (int i = (int)m_moveable.size() - 1; i >= 0; i--)
	{
		m_moveable[i]->~Moveable();
		m_moveable.erase(m_moveable.cbegin() + i);
	}
	for (int i = (int)m_unMovable.size() - 1; i >= 0; i--)
	{
		m_unMovable[i]->~UnMoveable();
		m_unMovable.erase(m_unMovable.cbegin() + i);
	}
	for (int i = (int)m_flame.size() - 1; i >= 0; i--) {
		m_flame[i]->~Flame();
	    m_flame.erase(m_flame.cbegin() + i);
	}
	for (int i = (int)m_bomb.size() - 1; i >= 0; i--) {
		m_bomb[i]->~Bomb();
		m_bomb.erase(m_bomb.cbegin() + i);
	}
}

int Controller::getTotalScore() const 
{
	return TotalScore;
}
int Controller::TotalScore = 0;

void Controller::resetMoveableDefault()
{
  for (int i = (int) m_moveable.size() - 1; i >= 0; i--)
	{
	  if (m_moveable[i]->isKill() == false) {
		  m_moveable[i]->setDefault();
		  m_unMovable[i]->setAlive();
	  }
	}
}
# 🔰 Bomberman-Game 🔰
[![](https://img.shields.io/badge/author-@OlaBannan-blue.svg?style=flat)](www.linkedin.com/in/ola-bannan-98a667175)


A simulation of the Bomber-man game using C++11, SFML media lib, and Object-Oriented concepts.
In this projet I implemented the Bomberman game with inheritance realization and polymorphism as well as use the SFML graphics library.


<div align="center"><img src="https://drive.google.com/uc?export=view&id=1z9fKNOHI7Yc0BXVRBGLJc1c3U1lY3N79" width="500" height="300"/></div>

<br>

## Game's Brief Explanation:
Note: The game is played "in real time" according to the clock, In each turn a object can move to one of 
the four  directions (but not diagonally). 

The main goal in the games is to always finish all the stages in the game by strategically placing bombs
to kill the enemies and destroy all obstacles on the way. Exploding bombs can also trigger other bombs,
kill or hurt enemies,and destroy the obstacles. However, they can also kill or hurt the player's character.

## Characters:
- ***Robot*** - This is the character that represents the player.
The goal of the game is to bring the robot to the exit door in
a limited number of steps and without being caught by the enemies/guards.

- ***Guards/Enemies*** - figures controlled by the computer. 
Try to prevent the player  from reaching the exit door. If they
Touching the player - the player is disqualified ("his life goes down").

- ***The exit door*** - the desired goal. A stage ends with the robot reaching the exit door.

- ***Walls*** - no figure can pass through a wall. Nor the bombs affect walls.

- ***Rocks*** - other obstacles standing in the way of the objects. No figure can cross a
rock, though the bombs the player assumes exploded the rocks and then the passage 
is available to everyone.

- ***Gift*** - every gift will give the robot 5 bombs.

- ***Bombs*** -  Every bomb the player assumes explodes after four seconds and destroys any figure 
(robot or guardian) or rock in its square Or one of the four squares adjacent to it 
(up, down, left and right).
When the player "passes through the door", he successfully completed the current stage, and the program should load
The next steage (if there is one like that). If there is no further stage, the player wins the game.
However, if the player "wasted" all the time assigned to this stage and has not yet finished it, he is
"alive" and the stage begins again.
If the player is "injured" by a enemies or a bomb, he loses his "life". If he had no more life, the game ends in 
the failure of the player. If they remain alive, the stage does not start over, he continues from the same place,
but the charactersre-commission where they were at the beginning of the stage. 


## Design:

- ***Controller:*** <br>
It holds all the other objects (the board, the Robot , the Enemies , etc ..) and contains 
the main loop of the game (print, move each character, and again print until the stage is over).
note: all the Controller's functions are a private functions except one ot two. 


- ***GameObject:*** <br>
Holding the game object, it is  who reads from a file, and keeps
file's data, any change in Vertex's char passes through it and makes the change, it is responsible
for displaying the board's objects in a correct way.
called from the Controller's class.


- ***Gameboard:*** <br>
Holding the game board, a two-dimensional vector of char, it is  who reads from a file, and keeps
file's data, any change in Vertex's char passes through it and makes the change, it is responsible
for displaying the board's char in a correct way.
called from the Controller's class.


- ***Robot:*** <br>
Saves the robot's data, the number of his lifeand his place(x,y).
The player moves his character with the arrow keys , puts down a bomb by pressing 'b'
or presses space bar to drop the queue.
called from the  Gameboard's class.


- ***Enemies:*** <br>
enemy's place and all other proprties that related to the enemy.
The method of moving the guards is:
called from the Gameboard's class.
note: I chose to use a random number, so that a program will not always run in the same way, 
and so that the algorithm be undetectable after tracking the enemies' movements and so it will
not be too difficult to win.
  -  If the robot and the enemy in the same row:
  If the enemy is righter than the robot , then according to the random number(0/1) 
  the enemy go left or right. 

  - If the robot and the enemy in the same column:
  If the enemy is higher than the robot, then according to the random number(0/1)
  the enemy go down or up to the direction of the robot .

  - If the enemy is righter than the robot, but they are not on the same row:
  Then according to the random number(0/1) the enemy go left or up to the direction
  of the robot. 

  - If the robot is righter than the enemy, but they are not on the same row:
  Then according to the random number(0/1) the enemy go right or down to the direction
  of the robot.


- ***Bombs:*** <br>
Saves the bomb's data, bomb's place and all other proprties that related to the bomb like
the bomb's timer, bomb can kill robot, enemy, brick.
called from the Controller's class.

- ***Flames:*** <br>
Saves the flame's data, bomb's place and all other proprties that related to the flame like
the flame's timer.
called from the Controller's class.

- ***Brick:*** <br>
Saves the brick's data, brick's place and all other proprties that related to the brick.
called from the GameObject's class.


- ***GiftUnderBrick:*** <br>
Saves the brick's data, brick's place and all other proprties that related to the brick.
called from the GameObject's class, when a bomb exploded it, it will disapear and instead 
it will shown a Gift


- ***Wall:*** <br>
Saves the wall's data, wall's place and all other proprties that related to the wall.
called from the GameObject's class.

- ***Door:*** <br>
Saves the door's data, door's place and all other proprties that related to the door.
called from the GameObject's class.

- ***Gift:*** <br>
Saves the Gift's data, Gift's place and all other proprties that related to the Gift.
called from the GameObject's class, every gift gives the robot 5 bombs, if there is a limit 
on the number of the bomb.


## List of files:


- Controller.h + Controller.cpp = controller class
- GameBoard.h + GameBoard.cpp = GameBoard class ---> abstract class 

- Buttons.h + Buttons.cpp = Buttons class - base class 
- Back.h + Back.cpp = Back Button - derived class 
- QuitGame.h + QuitGame.cpp = QuitGame class - derived class 

- Collision.h + Collision.cpp = Collision class ---> abstract class - Base class
- MoveCollision.h + MoveCollision.cpp =  MoveCollision class - derived class - base class
- UnmoveCollison.h + UnmoveCollison.cpp = UnmoveCollison class ---> abstract class - Base class
- REnemyFlameColl.h + REnemyFlameColl.cpp = REnemyFlameColl class - derived class
- REnemyRobotColl.h + REnemyRobotColl.cpp = REnemyRobotColl class - derived class
- REnemyRobotColl.h + REnemyRobotColl.cpp = REnemyRobotColl class - derived class
- RobotBrickColl.h + RobotBrickColl.cpp  = RobotBrickColl class - derived class
- RobotDoorColl.h + RobotDoorColl.cpp =  RobotDoorColl class - derived class
- RobotEmptyColl.h + RobotEmptyColl.cpp = RobotEmptyColl class - derived class
- RobotFlameColl.h + RobotFlameColl.cpp = RobotFlameColl class - derived class
- RobotGiftColl.h + RobotGiftColl.cpp = RobotGiftColl class - derived class
- RobotREnemyColl.h + RobotREnemyColl.cpp = RobotREnemyColl class - derived class
- RobotSEnemyColl.h + RobotSEnemyColl.cpp = RobotSEnemyColl class  - derived class
- RobotWallColl.h + RobotWallColl.cpp = RobotWallColl class - derived class
- SEnemyFlameColl.h + SEnemyFlameColl.cpp = SEnemyFlameColl class - derived class
- SEnemyRobotcoll.h + SEnemyRobotcoll.cpp = SEnemyRobotcoll class - derived class

- GameObject.h + GameObject.cpp = GameObject class  ---> abstract class - Base class
- Help.h + Help.cpp = Help class - derived class 
- Quit.h + Quit.cpp = Quit class - derived class 
- Start.h + Start.cpp = Start class - derived class 


- Moveable.h + Moveable.cpp = Moveable class ---> abstract class - base class
- Robot.h + Robot.cpp = Robot class - derived class 
- Enemy.h + Enemy.cpp = Enemy class - Base class - derived class 
- RandomEnemy.h + RandomEnemy.cpp =  RandomEnemy class - derived class from Enemy 
- SmartEnemy.h + SmartEnemy.cpp = SmartEnemy class - derived class from Enemy

- UnMoveable.h + UnMoveable.cpp = UnMoveable class ---> abstract class - Base class
- Wall.h + Wall.cpp = Wall class  - derived class 
- Flame.h + Flame.cpp = Flame class - derived class 
- Gift.h + Gift.cpp = Gift class  - derived class 
- GiftUnderBrick.h + GiftUnderBrick.cpp = GiftUnderBrick class - derived class 
- Bomb.h + Bomb.cpp = Bomb class - derived class 
- Brick.h + Brick .cpp = Brick class - derived class 
- Door.h + Door.cpp = Door class - derived class 
- EmptyCell.h + EmptyCell.cpp = EmptyCell class - derived class 

- Texture.h + Texture.cpp =  Texture class
- main.cpp 
- macros.h 

## Adding A Stage To The Game:
To add new stage, open file from type ".txt", the stage name should be = "stageN.txt",
N is the number of the stage, already there is 5 stages,
you can add stages as much as you want, but you have to start 
from number 6 stage6.txt , stage7.txt , etc ...

***IMPORTANT NOTE:***
after adding the txt file (stage), go to the main and in rows number 9, int numofstages = 5;
change 5 to the num of the stages that you want.


## Main Data Structures:
Vectors 

## Algorithms:
mymap 

## Known bugs:
Unknown


## Other Notes:
- To add new stage, open file from type ".txt", the stage name should be = "stageN.txt",
N is the number of the stage, already there is 5 stages,
you can add stages as much as you want, but you have to start 
from number 6 stage6.txt , stage7.txt , etc ...

- ***Importnat Note:***
After adding the txt file (stage), go to the main and in rows number 9, int numofstages = 5;
change 5 to the num of the stages that you want.


- ***Music:***
There is a music on the begning screen, on the help screen , and on the stage itself,
and there is a sound of bomb when it will exploded.
Don't enter quickly on play button, the music has to take time to uplode, either you will not hear it 

 - Score that appears in the screen, is the total score.


## References

[`VisualStudio`](https://visualstudio.microsoft.com/)
[`CPP`](https://en.cppreference.com/w/cpp/language)

## License

GPL License

Copyright (c) [2020] [Ola Bannan]

  The licenses for most software and other practical works are designed
to take away your freedom to share and change the works.  By contrast,
the GNU General Public License is intended to guarantee your freedom to
share and change all versions of a program--to make sure it remains free
software for all its users.  We, the Free Software Foundation, use the
GNU General Public License for most of our software; it applies also to
any other work released this way by its authors.  You can apply it to
your programs, too.

  When we speak of free software, we are referring to freedom, not
price.  Our General Public Licenses are designed to make sure that you
have the freedom to distribute copies of free software (and charge for
them if you wish), that you receive source code or can get it if you
want it, that you can change the software or use pieces of it in new
free programs, and that you know you can do these things.

  To protect your rights, we need to prevent others from denying you
these rights or asking you to surrender the rights.  Therefore, you have
certain responsibilities if you distribute copies of the software, or if
you modify it: responsibilities to respect the freedom of others.

  For example, if you distribute copies of such a program, whether
gratis or for a fee, you must pass on to the recipients the same
freedoms that you received.  You must make sure that they, too, receive
or can get the source code.  And you must show them these terms so they
know their rights.



---
## Author Info

- Github - [Ola Bannan](https://github.com/OlaBannan)
- Linkedin - [Ola Bannan](www.linkedin.com/in/ola-bannan-98a667175)


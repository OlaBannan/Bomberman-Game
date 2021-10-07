#include "Controller.h"

int main()
{

	int c = 10;
	bool closed = false;

	int numofstages = 5;

	while (c!=3) {
		int stage_num = 1; // first stage has number 1 
		Controller GameControl(stage_num, numofstages);
		c = GameControl.open();
		while (c != 3)
		{
			// if c == 0 means that player want to play  
			if (c == 0) {

				bool win = true;
				while (win)
				{
					if (stage_num > numofstages)//if there is no remain stages, exit 
						break;
					win = GameControl.startGame();
					// if the player won the stage, move to the next stage 
					if (win) 
						stage_num++;
				}
				break;

			}
			// id c==1 means that teh player wants help
			else if (c == 1)
			{
				GameControl.help();
				c = GameControl.open();
				continue;
			}
			// id c==2 means that teh player wants to exit 
			else if (c == 2)
				return EXIT_SUCCESS;
		
		}
	}
	return 0;

}
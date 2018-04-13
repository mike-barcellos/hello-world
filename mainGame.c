

/*
	The size the game was built on is 120 x 30. 
*/

#pragma once
#define _CRT_SECURE_NO_WARNINGS

void startBattle(void);
void mainGame(void);
void buildMap(void);
int buildInfoBox(void);
void StartMenu(void);
void buildStoryInfoBox(int dialougeSelection);

#include <curses.h>
#include <Windows.h>
#include "header.h"

int main() {

	//Makes the standard screen.
	initscr();

	//hides the cursor
	curs_set(0);

	//Start the splash screen
	splashScreen();

	endwin();

	return 0;
}

void mainGame(void)
{

	//This is the keyboard input character
	char ch;

	//Makes sure the key input is not typed on the screen.
	noecho();

	//Not really sure what these do, BUT IT WORKS!
	cbreak();
	raw();

	//Draw the "man in the box"
	mvprintw(mainCharacter.yLoc, mainCharacter.xLoc, "O");

	//Draw monsters
	mvprintw(testMonster.yLoc, testMonster.xLoc, "M");

	//Maybe turn this into a function to clean up the code. 

	//When working with the invisible part of the map, this will probably
	//be the place where that function goes.

	while ((ch = getch()) != 'q' && mainCharacter.health > 0) {

		//W is up
		if (ch == 'w') {
			if (mvinch(mainCharacter.yLoc - 1, mainCharacter.xLoc) != '-' && mvinch(mainCharacter.yLoc - 1, mainCharacter.xLoc != '|')) {
				mainCharacter.yLoc--;	
			}
		}
		//S is down
		else if (ch == 's') {
			if (mvinch(mainCharacter.yLoc + 1, mainCharacter.xLoc) != '-' && mvinch(mainCharacter.yLoc + 1, mainCharacter.xLoc) != '|') {
				mainCharacter.yLoc++;
			}
				
		}
		//A is left
		else if (ch == 'a') {
			if (mvinch(mainCharacter.yLoc, mainCharacter.xLoc - 1) != '|' && mvinch(mainCharacter.yLoc, mainCharacter.xLoc - 1) != '-') {
				mainCharacter.xLoc--;
			}
				
				
		}
		//D is right
		else if (ch == 'd') {
			if (mvinch(mainCharacter.yLoc, mainCharacter.xLoc + 1) != '|' && mvinch(mainCharacter.yLoc, mainCharacter.xLoc + 1) != '-') {
				mainCharacter.xLoc++;
			}
				
		}
		//Pressing 'q' will quit the game. 
		else if (ch == 'q') {
			endwin();
		}

		//Pressing 'm' will take to back to the main menu 
		else if (ch == 'm') {
			splashScreen();
		}

		//Game winning code
		if (mvinch(mainCharacter.yLoc, mainCharacter.xLoc) == 'X' && mainCharacter.hasKey > 0) {
			clear();
			youWonScreen();
		}
		else {
			buildStoryInfoBox(6);
		}

		//Monster fighting code
		if (mvinch(mainCharacter.yLoc, mainCharacter.xLoc) == 'M') {
			startBattle();
		}

		//Clear the screen then reprint everything including the map
		clear();

		//keep building the map contunuously 
		buildInfoBox();


		if (mainCharacter.yLoc == 2) {
			buildStoryInfoBox(6);
		} 
		else if (mainCharacter.yLoc <= 10) {
			buildStoryInfoBox(5);
		}
		else if (mainCharacter.yLoc <= 20) {
			buildStoryInfoBox(4);
		}
		else {
			buildStoryInfoBox(0);
		}

		buildMap();

		//draw character
		mvprintw(mainCharacter.yLoc, mainCharacter.xLoc, "O");

		//Draw monsters
		mvprintw(testMonster.yLoc, testMonster.xLoc, "M");

		refresh();
	}

	//If dead
	if (mainCharacter.health <= 0) {
		endwin();
	}
}

void buildMap(void) {
	//Box size is 0 < x < 61 and 0 < y < 27
	int xMin = 1;
	int xMax = 61;
	int yMin = 1;
	int yMax = 27;

	mvprintw(2, 2, "--------------------------------X---------------------------");
	mvprintw(3, 2, "------------------               ---------------------------");
	mvprintw(4, 2, "------------------     -------------------------------------");
	mvprintw(5, 2, "------------------     -------------------------------------");
	mvprintw(6, 2, "------------------     -------------------------------------");
	mvprintw(7, 2, "--------                                              ------");
	mvprintw(8, 2, "--------                            -------------     ------");
	mvprintw(9, 2, "--------     ------------------     -------------     ------");
	mvprintw(10, 2, "--------     ------------------     -------------     ------");
	mvprintw(11, 2, "---          ------------           --------          ------");
	mvprintw(12, 2, "---          ------------           --------          ------");
	mvprintw(13, 2, "-------------------------     --------------     -----------");
	mvprintw(14, 2, "------          ---------     --------------     -----------");
	mvprintw(15, 2, "------          ---------     --------------     -----------");
	mvprintw(16, 2, "------     --------------     --------------          ------");
	mvprintw(17, 2, "------     --------------     --------------          ------");
	mvprintw(18, 2, "------     --------------     -------------------     ------");
	mvprintw(19, 2, "------     --------------     -------------------     ------");
	mvprintw(20, 2, "------     --------------     -------------------     ------");
	mvprintw(21, 2, "                                                            ");
	mvprintw(22, 2, "                                                            ");
	mvprintw(23, 2, "-------------------------     ------------------------------");
	mvprintw(24, 2, "-------------------------     ------------------------------");
	mvprintw(25, 2, "-------------------------     ------------------------------");


	for (int i = 1; i < yMax; i++) {
		mvprintw(i, xMin, "|");
		mvprintw(i, xMax, "|");
	}

	for (int i = 1; i <= xMax; i++) {
		mvprintw(yMin, i, "-");
		mvprintw(yMax, i, "-");
	}
}

int buildInfoBox(void) {
	//Box size is 0 < x < 61 and 0 < y < 27
	int xMin = 63;
	int xMax = 113;
	int yMin = 1;
	int yMax = 14;
	int randNumber = (rand() + 1) % (100 + 1);

	for (int i = yMin; i < yMax; i++) {
		mvprintw(i, xMin, "|");
		mvprintw(i, xMax, "|");
	}

	for (int i = xMin; i <= xMax; i++) {
		mvprintw(yMin, i, "-");
		mvprintw(yMax, i, "-");
	}

	mvprintw(2, 64, "Location:");
	mvprintw(3, 64, "X = %d, Y = %d", mainCharacter.xLoc, mainCharacter.yLoc);

	mvprintw(5, 64, "Random Number:");
	mvprintw(6, 64, "Number is %d", randNumber);

	mvprintw(8, 64, "Player Health:");
	mvprintw(9, 64, "Your health: %d", mainCharacter.health);

	mvprintw(10, 64, "Name: %s", mainCharacter.name);

	return randNumber;
}

void buildStoryInfoBox(int dialougeSelection) {
	//This box should take an integer. That int will tell it what to display on the screen.
	//Keep all of the dialouge in here and when something happens puch the required dialog to the screen.

	//Box size is 0 < x < 113 and 0 < y < 27
	int xMin = 63;
	int xMax = 113;
	int yMin = 15;
	int yMax = 27;

	for (int i = yMin; i < yMax; i++) {
		mvprintw(i, xMin, "|");
		mvprintw(i, xMax, "|");
	}

	for (int i = xMin; i <= xMax; i++) {
		mvprintw(yMin, i, "-");
		mvprintw(yMax, i, "-");
	}

	//Dialouge selection
	if (dialougeSelection == 1) {
		battleDialouge();
	}
	else if (dialougeSelection == 2) {
		battleWinDialouge();
	}
	else if (dialougeSelection == 3) {
		battleLoseDialouge();
	}
	else if (dialougeSelection == 4) {
		monsterCloseDialouge();
	}
	else if (dialougeSelection == 5) {
		endCloseDialouge();
	}
	else if (dialougeSelection == 6) {
		needKeyDialouge();
	}
	else {
		testDialouge();
	}
}

void StartMenu(void) {

	char ch = NULL;
	//start at y + 9
	int y = 5;
	int x = 15;

	//Makes sure the key input is not typed on the screen.
	noecho();

	//Not really sure what these do, BUT IT WORKS!
	cbreak();
	raw();

	mvprintw(y + 9, x, "                                          (P)lay");
	mvprintw(y + 10, x, "                                      (I)nstructions");
	mvprintw(y + 11, x, "                                        (B)ackstory");
	mvprintw(y + 12, x, "                                          (E)xit");

	//keyboard input for the splash screen
	while ((ch = getch()) != 'q') {
		if (ch == 'p') {

			clear();
			endwin();

			//Build the name character screen, it then builds the map
			nameCharacterScreen();
		}
		else if (ch == 'i') {
			clear();
			instructionsScreen();
		}
		else if (ch == 'b') {
			clear();
			backStoryScreen();
		}
		else if (ch == 'e') {
			clear();
			endwin();
		}

	}
	refresh();
}

void startBattle(void) {

	char ch = '[';

	flash();
	flash();
	flash();
	flash();
	flash();

	clear();
	buildInfoBox();

	buildMap();

	buildStoryInfoBox(1);
	refresh();

	//keyboard input for battle screen
	while ((ch = getch()) != 'q' && testMonster.health > 0 && mainCharacter.health > 0) {

		int battleNumber = buildInfoBox();

		//attack
		if (ch == 'a') {

			if (battleNumber > 50) {
				mvprintw(17, 64, " You hit!!!                                            ");
				mvprintw(18, 64, "                                                       ");
				testMonster.health--;
			}
			else {
				mvprintw(17, 64, " You missed and the monster countered                  ");
				mvprintw(18, 64, "                                                       ");
				flash();
				mainCharacter.health--;
			}

		}
		//block
		else if (ch == 'b') {

			if (battleNumber > 50) {
				mvprintw(17, 64, " You blocked and monster hit.                          ");

				if (battleNumber > 75) {
					mvprintw(18, 64, " Moster did 1 damage!                              ");
					flash();
					mainCharacter.health--;
				}
				else {
					mvprintw(18, 64, "  No damage but no counter.                        ");
				}

			}
			else {
				mvprintw(17, 64, " You blocked and monster missed.                       ");
				mvprintw(18, 64, " Counter for double damage.                            ");
				testMonster.health--;
				testMonster.health--;
			}
		}
		//run
		else if (ch == 'r') {
			mainGame();
		}

		int randNumber = buildInfoBox();
		buildStoryInfoBox(1);
		refresh();
	}

	if (testMonster.health <= 0) {
		mainCharacter.hasKey = 1;
		buildStoryInfoBox(2);
		refresh();
		mainGame();
	}
	else if (mainCharacter.health <= 0) {
		buildStoryInfoBox(3);
		refresh();
		gameOverScreen();
	}

	refresh();
}
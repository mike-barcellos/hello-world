#pragma once

#include <curses.h>
#include <Windows.h>
#include "screens.h"
#include "dialouge.h"
#include "characters.h"
#include "screens.h"

void monsterCloseDialouge(void);
void endCloseDialouge(void);
void testDialouge(void);
void battleDialouge(void);
void battleWinDialouge(void);
void battleLoseDialouge(void);
void needKeyDialouge(void);

void testDialouge(void) {
	mvprintw(16, 64, " This is some test dialouge to test out the     ");
	mvprintw(17, 64, "sizing and create a template. You arrive  in the");
	mvprintw(18, 64, "cave. It is dark and erie but you swallow your  ");
	mvprintw(19, 64, "fear and continue into the darkenss. You have a ");
	mvprintw(20, 64, "feeling that something is watching you but there");
	mvprintw(21, 64, "is nothing in site. Suddenly the idea that this ");
	mvprintw(22, 64, "could be the last cave you will ever see strikes");
	mvprintw(23, 64, " home. Is today the day you die?                ");
	mvprintw(24, 64, "                                                ");
	mvprintw(25, 64, "                                                ");
	mvprintw(26, 64, "This is the bottom of the box.                  ");
}

void battleDialouge(void) {
	mvprintw(16, 64, " You are engaged in combat!                     ");

	mvprintw(19, 64, " %s's Health: %d                                ",mainCharacter.name, mainCharacter.health);
	mvprintw(20, 64, " %s's Health: %d                                ", testMonster.name, testMonster.health);

	mvprintw(22, 64, " Press 'a' to attack.                           ");
	mvprintw(23, 64, " Press 'b' to block.                            ");
	mvprintw(24, 64, " Press 'r' to run.                              ");
	mvprintw(25, 64, "                                                ");
	mvprintw(26, 64, "This is the bottom of the box.                  ");
	refresh();
}

void battleWinDialouge(void) {

	mvprintw(16, 64, " You have defeated the monster!                 ");
	mvprintw(17, 64, "                                                ");
	mvprintw(18, 64, " Your health: %d                                ", mainCharacter.health);
	mvprintw(19, 64, " Monster Health: %d                             ", testMonster.health);
	mvprintw(20, 64, "                                                ");
	mvprintw(21, 64, " You have picked up a key!                      ");
	mvprintw(22, 64, "                                                ");
	mvprintw(23, 64, " Press anykey to continue                       ");
	mvprintw(24, 64, "                                                ");
	mvprintw(25, 64, "                                                ");
	mvprintw(26, 64, "This is the bottom of the box.                  ");
	getch();
	refresh();

}

void battleLoseDialouge(void) {

	mvprintw(16, 64, " You have been defeated!!!                      ");
	mvprintw(17, 64, "                                                ");
	mvprintw(18, 64, " Your health: %d                                ", mainCharacter.health);
	mvprintw(19, 64, " Monster Health: %d                             ", testMonster.health);
	mvprintw(20, 64, "                                                ");
	mvprintw(21, 64, " Press anykey to continue                       ");
	mvprintw(22, 64, "                                                ");
	mvprintw(23, 64, "                                                ");
	mvprintw(24, 64, "                                                ");
	mvprintw(25, 64, "                                                ");
	mvprintw(26, 64, "This is the bottom of the box.                  ");
	getch();
	gameOverScreen();
	refresh();

}

void monsterCloseDialouge(void) {

	mvprintw(16, 64, " As you wade through the darkness, you can hear ");
	mvprintw(17, 64, "raspy breathing. The hairs on your neck start to");
	mvprintw(18, 64, "stand up and your heart starts to race.         ");
	mvprintw(19, 64, "				                                  ");
	mvprintw(20, 64, " A dim outline starts to form around something  ");
	mvprintw(21, 64, "up ahead. It's big. Very big. It knows you're   ");
	mvprintw(22, 64, "here and starts to look up towards you.         ");
	mvprintw(23, 64, "                                                ");
	mvprintw(24, 64, " Approach with caution...                       ");
	mvprintw(25, 64, "                                                ");
	mvprintw(26, 64, "                                                ");
}

void endCloseDialouge(void) {

	mvprintw(16, 64, " Up ahead you can see a light at the end of the ");
	mvprintw(17, 64, "tunnel. There is ancient writing on the wall    ");
	mvprintw(18, 64, "that seems to be indicating treasure ahead.     ");
	mvprintw(19, 64, "				                                  ");
	mvprintw(20, 64, " Has the moment finally come?                   ");
	mvprintw(21, 64, "                                                ");
	mvprintw(22, 64, "                                                ");
	mvprintw(23, 64, "                                                ");
	mvprintw(24, 64, "                                                ");
	mvprintw(25, 64, "                                                ");
	mvprintw(26, 64, "                                                ");
}

void needKeyDialouge(void) {

	mvprintw(16, 64, " You need to get the key in order to open the   ");
	mvprintw(17, 64, "treasure gate.                                  ");
	mvprintw(18, 64, "                                                ");
	mvprintw(19, 64, "				                                  ");
	mvprintw(20, 64, "                                                ");
	mvprintw(21, 64, "                                                ");
	mvprintw(22, 64, "                                                ");
	mvprintw(23, 64, "                                                ");
	mvprintw(24, 64, "                                                ");
	mvprintw(25, 64, "                                                ");
	mvprintw(26, 64, "                                                ");
}
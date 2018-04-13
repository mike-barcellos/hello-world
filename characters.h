#pragma once
#include <curses.h>
#include <Windows.h>
#include "screens.h"
#include "dialouge.h"
#include "characters.h"
#include "screens.h"

typedef struct playerCharacter
{
	char name[50];
	int health;
	int strength;
	int speed;
	int xLoc;
	int yLoc;
	int hasKey;

} player;

typedef struct monsterCharacter
{
	char name[50];
	int health;
	int strength;
	int speed;
	int xLoc;
	int yLoc;

} monster;

//Global Variables (at least for now)
player mainCharacter = { "Mike", 5, 50, 50, 31, 26, 0 };
monster testMonster = { "Grrrr", 5, 50, 50, 29, 15 };
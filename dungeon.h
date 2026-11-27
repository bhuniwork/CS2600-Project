#ifndef DUNGEON
#define DUNGEON

#include <stdbool.h>

bool initializeAudio(void);
void shutdownAudio(void);


//Method Headers
//
int positionX(void); //- returns a random position X
int positionY(void); //- returns a random position Y
void initializeDungeon(void); //- returns a 2D array of blank spaces and a border
void printDungeon(void); //- returns a dungeon with randomized item, walls, enemies, and centered player
void playerControl(char key); //- method determines player movement, where movement is represented by "WASD" and returns a dungeon with that new movement modification. Key represents WASD

/*
//Local variables
char blank_space; //- black space character in dungeon
char wall; //- wall character in dungeon
char player; //- player character in dungeon
int numberCount; //- enemy spawn count (is random)
int numberCountItem; //- item spawn count (is random)
char enemy; //- enemy character in dungeon
char item; //- item character in dungeon
int tempRow; //- temporary row, allows for movement in dungeon.
int tempCol; //- temporary column, allows for movement in dungeon.
char key; //- 'WASD representation
char stop; //- TESTS function, kills game
*/

//Global Variables

extern char dungeon_platform[12][12]; //- 2d array representing the GRID of dungeon (Empty)
extern int health; //- Health of the player (initial: 100, subject to change)
extern int playerX; //- gives the center X of the player in the dungeon
extern int playerY; //- gives the center Y of the player in the dungeon
extern bool hitWall; //- returns true if player hits '#' character.

#endif

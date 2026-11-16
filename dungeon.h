#ifndef DUNGEON
#define DUNGEON


/*

Method Headers
int positionX() - returns a random position X
int positionY() - returns a random position Y
void initializeDungeon() - returns a 2D array of blank spaces and a border
void printDungeon() - returns a dungeon with randomized item, walls, enemies, and centered player
int main() - TEST function, 
void playerControl(char key) - method determines player movement, where movement is represented by "WASD" and returns a dungeon with that new movement modification. Key represents WASD


Local variables
 char blank_space = '.'; - black space character in dungeon
char wall = '#'; - wall character in dungeon
char player = 'P'; - player character in dungeon
int numberCount = 0; - enemy spawn count (is random)
int numberCountItem = 0; - item spawn count (is random)
char enemy = 'e'; - enemy character in dungeon
char itemP = '@'; - item character in dungeon
char r - (for ITEMS) checks rows if item is present
int c - (for ITEMS) checks columns if item is present
enemyInSameRow - true if position contains 'e'
bool isBlankSpace - true if character is a '.'
int randomX - (for ENEMY) returns a random coordinate X in (rand() % 10) + 1;
int randomY - (for ENEMY) returns a random coordinate Y in (rand() % 10) + 1;
bool itemsInSameRow - returns true t
int tempRow - temporary row, allows for movement in dungeon.
int tempCol - temporary column, allows for movement in dungeon.
char key - 'WASD" representation
stop - TESTS function, kills game

Global Variables
char dungeon_platform[12][12]; - 2d array representing the GRID of dungeon (Empty)
int health; - Health of the player (initial: 100, subject to change)
int playerX; - gives the center X of the player in the dungeon
int playerY; - gives the center Y of the player in the dungeon
bool hitWall; - returns true if player hits '#' character.
*/

#endif

#ifndef PLAYER_H
#define PLAYER_H

#define MAX_ITEMS 100
#include "Items.h"
#include "enemy.h"

//Defines who turn it is
typedef enum {
	TURN_WAITING, //Not the player's turn
	TURN_ACTIVE   //The Player can perform an action
} TurnState;

//Describes what happened when the player tries to do something
typedef enum {
	ACTION_NOT_ALLOWED, //Nothing happened and player's turn was not used
	ACTION_DONE, //Action completed successfully and player's turn has ended
	ACTION_ENEMY_DEFEATED //Player's action caused enemy to be defeated
} ActionResult;

//Defines fields such as the player's health, damage, weapon, and the player's item. Index is used to indicate the next index in the array to put a player item in
typedef struct player {
    int  playerHealth;
    int  playerDamage;
    int index;
    Items playerWeapon;
    Items playerItems[MAX_ITEMS];
    TurnState turnState;
}player;

//These function definitions define the functions that will be used in player.c. These will be described more in detail within player.c alongside their implementation
void playerDefaultConfiguration(player *player);

int getPlayerHealth(player *player);
void setPlayerHealth(player *player, int hp);

int getPlayerDamage(player *player);
void setPlayerDamage(player *player, int damage);

Items *getPlayerWeapon(player *player);
void setPlayerWeapon(player *player, Items item);

int getIndex(player *player);
void addPlayerItem(player *player, Items item);
void removePlayerItem(player *player, Items *item);
void displayPlayerItems(player *player);

bool isPlayerAlive(player *player);
void playerTakeDamage(player *player, int amount);
int getPlayerAttackDamage(player *player);
void displayPlayerStatus(player *player);

bool canPlayerAct(player *player);
bool isPlayerWaitingForEnemy(player *player);
void startPlayerTurn(player *player);
void endPlayerTurn(player *player);

ActionResult playerAttack(player *player, Enemy *target);
ActionResult playerUseItem(player *player, int slot);

#endif

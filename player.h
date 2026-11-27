#ifndef PLAYER_H
#define PLAYER_H

#define MAX_ITEMS 100
#include "Items.h"

//Defines fields such as the player's health, damage, weapon, and the player's item. Index is used to indicate the next index in the array to put a player item in
typedef struct player {
    int  playerHealth;
    int  playerDamage;
    int index;
    Items playerWeapon;
    Items playerItems[MAX_ITEMS];
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

#endif

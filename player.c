#include <stdio.h>
#include <string.h>
#include "player.h"

//Fills the array with a placeholder value. This will be used as an indicator that a specific element of the array has no items for the player to use.
void fillPlayerItemsPlaceholderValues(player* player){
	for(int i = 0 ; i<100 ; i++) {
		player->playerItems[i] = "Placeholder";
	}
}

//This is essentially a default constructor. Call this function when you create a player object
void playerDefaultConfiguration(player* player) {
	player->playerHealth = 50;
	player->index=0;
	player->playerDamage = 30;
	player->playerWeapon = "undefined";
	fillPlayerItemsPlaceholderValues(player);
}

//Gets the player's health.
int getPlayerHealth(player* player){
	return player->playerHealth;
}

//Allows to change the player's health
void setPlayerHealth(player* player, int hp){
	player->playerHealth = hp;
}

//Return the index, which is used to refer to the next index in the player item array to add a player item
int getIndex(player* player){
	return player->index;
   }

//Get how much damage the player can inflict on the enemy
int getPlayerDamage(player* player) {
	return player->playerDamage;
}

//Change how much damage a player can deal.
void setPlayerDamage(player* player, int damage){
	player->playerDamage = damage;
}

//Get the weapon that player currently possesses.
char *getPlayerWeapon(player* player) {
	return player->playerWeapon;
}

//Set or change the weapon the player has.
void setPlayerWeapon(player* player, char *item){
	player->playerWeapon = item;
}

//Add a player item, such as a healing item, to the player's inventory(array)
void addPlayerItem(player* player, char item[]){
	if(player->index >= MAX_ITEMS) {
		return;
	   }
	player->playerItems[player->index] = item;
	player->index++;
}

//Displays the items in the player items array, excluding any placeholder items
void displayPlayerItems(player* player){
	for(int i = 0 ; i < player->index ; i++){
		if(strcmp(player->playerItems[i], "Placeholder") != 0) {
                   printf("%s\n" , player->playerItems[i]);
	     } else {
	      continue;
            }	      
	}
}

//Removes a specified player item in the player item array and replaces it with a placeholder item
void removePlayerItem(player* player, char item[]) {
	for(int i = 0 ; i < player->index ; i++) {
              if(strcmp(player->playerItems[i], item) == 0) {
		     player-> playerItems[i] = "Placeholder";
		     break;
		  }
	  }
}


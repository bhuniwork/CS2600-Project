/*
Group 2:
	Matthew Zelaya
	Brandon Ho
	Chloe Lirio
	Logan Quon
	Derrehn Robles
*/

#include <stdio.h>
#include <string.h>
#include "player.h"
#include "Items.h"
#include "enemy.h"

static const Items placeholderItem = { .name = "Placeholder" };
static const Items placeholderWeapon = { .name = "Undefined" };

//Fills the array with a placeholder value. This will be used as an indicator that a specific element of the array has no items for the player to use.
void fillPlayerItemsPlaceholderValues(player* player) {
	for(int i = 0 ; i<MAX_ITEMS ; i++) {
		player->playerItems[i] = placeholderItem;
	}
}

//This is essentially a default constructor. Call this function when you create a player object.
void playerDefaultConfiguration(player* player) {
	player->playerHealth = 50;
	player->index=0;
	player->playerDamage = 30;
	player->playerWeapon = placeholderWeapon;
	player->turnState = TURN_WAITING;
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
void setPlayerDamage(player* player, int  damage){
	player->playerDamage = damage;
}

//Get the weapon that player currently possesses.
Items *getPlayerWeapon(player* player) {
	return &player->playerWeapon;
}

//Set or change the weapon the player has.
void setPlayerWeapon(player* player, Items item){
	player->playerWeapon = item;
}

//Add a player item, such as a healing item, to the player's inventory(array)
void addPlayerItem(player* player, Items item){
	if(player->index >= MAX_ITEMS) {
		return;
	}
	player->playerItems[player->index] = item;
	player->index++;
}

//Displays the items in the player items array, excluding any placeholder items
void displayPlayerItems(player* player){
	for(int i = 0 ; i < player->index ; i++){
		if(strcmp(player->playerItems[i].name, "Placeholder") != 0) {
                   printf("%s\n" , player->playerItems[i].name);
	     } else {
	      continue;
	     }
	}
}

//Removes a specified player item in the player item array and replaces it with a placeholder item
void removePlayerItem(player* player, Items *item) {
	for(int i = 0 ; i < player->index ; i++) {
		if(strcmp(player->playerItems[i].name, item->name) == 0) {
		     player->playerItems[i] = placeholderItem;
		     break;
		}
	}
}

//Ensures player is alive
bool isPlayerAlive(player* player) {
	return player->playerHealth > 0;
}

//Allows player to take damage by enemy and checks after whether the health is a negative number and if so, sets it to zero.
void playerTakeDamage(player *player, int amount) {
	if(amount < 0) {
		return;
	}
	player->playerHealth -= amount;
	if(player->playerHealth < 0) {
		player->playerHealth = 0;
	}
}

//Calculates the amount of damage a player does from its player damage plus the player's weapon damage
int getPlayerAttackDamage(player* player) {
	return player->playerDamage + (int) player->playerWeapon.weapon.damage;
}

//Display's player's current HP, whether they are alive, and their damage
void displayPlayerStatus(player* player) {
	printf("--- Player Status ---\n");
	printf("HP: %d (%s)\n", player->playerHealth, isPlayerAlive(player) ? "alive" : "defeated");

	if(strcmp(player->playerWeapon.name, "Undefined") == 0) {
		printf("Attack %d (no weapon equipped)\n" , getPlayerAttackDamage(player));
	} else {
	   printf("Attack: %d base + %d from %s = %d\n", player->playerDamage, (int) player->playerWeapon.weapon.damage, player->playerWeapon.name, getPlayerAttackDamage(player));
	}
}

//Checks whether player is alive and that it is their turn before they can make an action.
bool canPlayerAct(player* player) {
	return isPlayerAlive(player) && player->turnState == TURN_ACTIVE;
}

//Checks whether player is waiting for enemy to make its turn.
bool isPlayerWaitingForEnemy(player* player) {
	return player->turnState == TURN_WAITING;
}

//Gives player ability to take their turn. Calls this function at start of a battle and when the enemy has finished their turn.
void startPlayerTurn(player* player) {
   if(isPlayerAlive(player)) {
	   player->turnState = TURN_ACTIVE;
   }
}

//Ends player turn and makes player wait for next turn.
void endPlayerTurn(player* player) {
	player->turnState = TURN_WAITING;
}

static bool requireTurn(player* player) {
	if(!isPlayerAlive(player)) {
		printf("You are out of turns, you have been slained by the enemy\n");
		return false;
	}
	if(player->turnState != TURN_ACTIVE) {
		printf("It isn't your turn yet.\n");
		return false;
	}
	return true;
}
//Function that allows player to attack enemy. First ensures the move is allowed, then attacks the enemy. If enemy is defeated, the program acknowledges it
ActionResult playerAttack(player* player, Enemy *target) {
	if(target == NULL || !requireTurn(player)) {
		return ACTION_NOT_ALLOWED;
	}

	if(isDefeated(target)) {
	    printf("That enemy has been slained!\n");
	    return ACTION_NOT_ALLOWED;
	   }

	char *name = getName(target) != NULL ? getName(target) : "the enemy";
	int damage = getPlayerAttackDamage(player);
	takeDamage(target, damage);
	printf("You attacked %s for %d damage. Enemy HP: %d/%d\n", name, damage, getHealth(target), target->maxHealth);

	ActionResult result = ACTION_DONE;
	if(isDefeated(target)) {
		printf("%s has been slained!\n" , name);
		result = ACTION_ENEMY_DEFEATED;
       }

       displayPlayerStatus(player);
       endPlayerTurn(player);
       return result;
} 

//Allows player to use item. Checks to see if action is allowed and then consumes the item if it exists within the player's inventory. Then fills that slot with a placeholder value.
ActionResult playerUseItem(player* player, int slot) {
	if(!requireTurn(player)) {
		return ACTION_NOT_ALLOWED;
	}

	if(slot < 0 || slot >= player->index || strcmp(player->playerItems[slot].name, "Placeholder") == 0) {
		printf("There is no item in the slot.\n");
		return ACTION_NOT_ALLOWED;
	}

	Items *item = &player->playerItems[slot];
	int amount = item->healingItem.healingAmount;
	if(amount == 0) {
		printf("%s can't be sued right now.\n" , item->name);
		return ACTION_NOT_ALLOWED;
	}

	printf("You used %s. ", item->name);
	if(amount > 0) {
		printf("You recovered %d HP. \n", amount);
	} else {
	  printf("You lost %d HP.\n", -amount);
      }

	player->playerHealth += amount;
	if(player->playerHealth < 0) {
		player->playerHealth = 0;
	}

	player->playerItems[slot] = placeholderItem;

	displayPlayerStatus(player);
	endPlayerTurn(player);
	return ACTION_DONE;
}







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
#include "dungeon.h"
#include "Items.h"
#include "enemy.h"
#include "miniaudio.h"

//Stats of enemy. Please change the values if needed.
#define ENEMY_HEALTH 60
#define ENEMY_DAMAGE 8

//Makes the enemy appear to the player, giving vital information such as its health, total health, enemy name and enemy type.
static void spawnEnemy(Enemy *enemy) {
	*enemy = (Enemy){ .name = "James", .health = ENEMY_HEALTH, .maxHealth = ENEMY_HEALTH, .damage = ENEMY_DAMAGE, .type = "Grunt" };
	printf("%s the %s appears! (HP %d/%d)\n" , getName(enemy), getType(enemy), getHealth(enemy), enemy->maxHealth);
}

//Used to clear the input line whenever a bad number is typed by the user.
static void clearInputLine(void) {
	int c;
	while ((c = getchar()) != '\n' && c != EOF) { }
}

//Provides the UI and user ability to choose an item in their ability
static int chooseItemsSlot(player *player) {
	int shown = 0;
	printf("Your items:\n");
	for(int i = 0 ; i < player->index ; i++) {
		if(strcmp(player->playerItems[i].name, "Placeholder") != 0) {
			printf(" %d. %s\n", i + 1, player->playerItems[i].name);
			shown++;
		}
	}
	
	if(shown == 0) {
		printf("You have no items to use.\n");
		return -1;
	}

	printf("Enter the item number or press 0 to cancel action\n");
	int userChoice;
	if(scanf("%d", &userChoice) != 1) {
		clearInputLine();
		return -1;
	}
	return userChoice-1;
}

//Handles turn based logic (For now, enemy damage is fixed to one value, but random damage can be implemented later)
//Verifies that the player's action is valid
//Checks whether the player defeated an enemy or has been defeated themselves
//Includes the enemy attacking the player as well (it is a fixed to one value, but can be changed to randomized)
//Includes basic UI elements related to the turn-based battling system
static bool handleFightInput(char key, player *player, Enemy *enemy) {
	ActionResult result;

	if(key=='1') {
		result = playerAttack(player, enemy);
	} else if(key =='2') {
		int slot = chooseItemsSlot(player);       
	     if(slot < 0) {
		     printf("Action cancelled.\n");
		     return false;
	}
	result = playerUseItem(player, slot);
      } else {
	  printf("\nChoose 1 (Attack) or 2 (Use Item).\n");
	  return false;
     }

       if(result == ACTION_ENEMY_DEFEATED) {
	       printf("\nYou have won the battle!\n");
	       fightingEnemy = false;
	       return false;
	}

       if(result == ACTION_NOT_ALLOWED) {
	       return false;
	}

       if(!isPlayerAlive(player)) {
	       printf("You have been slained! Game over.\n");
	       return true;
	}

       printf("\n%s attacks you for %d damage!\n", getName(enemy), getDamage(enemy));
       playerTakeDamage(player, getDamage(enemy));
       printf("Your HP: %d\n", getPlayerHealth(player));

       if(!isPlayerAlive(player)) {
	       printf("\nYou were defeated. Game over. \n");
	       return true;
	 }

      startPlayerTurn(player);
      return false;
 }


int main()
{
    char key;
    //Starts game audio.
    initializeAudio();
    
    //Initializes UI elements that ought to be present when the game launches
    //Initializes the player with its default values. Also creates an array that serves as the items the player currently has.
    //Initializes the dungeon object and prints it out in standard output.
    UIGameStart();
    player p1;
    playerDefaultConfiguration(&p1);
    initializeDungeon();
    printDungeon();
    
    //Creates an enemy object, which refers to the current enemy the player is fighting
    //gameOver is used to indicate whether the player has been defeated or not
    Enemy currentEnemy;
    bool gameOver = false;
    
    
    while (!gameOver && scanf(" %c", &key) == 1 && key !='Q') {
          if(!fightingEnemy) {
		  playerControl(key, &p1);   //If player is not engaged in battle, then the player interacts with program so they can move around the dungeon
		  if(fightingEnemy) {
			  spawnEnemy(&currentEnemy);  //If the player encounters an enemy, then the program spawns the enemy and begins the player's first turn.
			  startPlayerTurn(&p1);
		   }
	     } else {
		 gameOver = handleFightInput(key, &p1, &currentEnemy);
	    }

	  if(!gameOver) {
		printDungeon();  //If the player is victorous in the battle, the program will reprint the dungeon.
	   }
    }
    
    //Stops game audio, put everything else above this line
    shutdownAudio();
    return 0;
}

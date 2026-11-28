/*
Group 2:
    Matthew Zelaya
    Brandon Ho
    Chloe Lirio
    Logan Quon
    Derrehn Robles
*/

#include <stdio.h>
#include <stdbool.h>
#include "player.h"
#include "enemy.h"


char *getName(Enemy *self) {
  return self->name;
}

int getHealth(Enemy *self) {
  return self->health;
}

int getDamage(Enemy *self) {
  return self->damage;
}

char *getType(Enemy *self) {
  return self->type;
}

// This method checks if an enemy's health is 0.
bool isDefeated(Enemy *self) {
  // REMEMBER: a returned value of 0 means FALSE while 1 MEANS TRUE.
  return self->health <= 0;
}

//Function that allows enemy to take damage by player. Ensures enemy health can never be less than 0.
void takeDamage(Enemy *self, int amount) {
	if(amount < 0) {
		return;
	}

	self->health -= amount;
	if(self->health < 0) {
		self->health = 0;
	}
}

void resetHealth(Enemy *self) {
  self->health = self->maxHealth;

}

/*
int main() {
  // main is used for TESTING only
  Enemy grunt = {.name = "James", .health = 0, .damage = 4, .type="Grunt"};

  // Initializes enemy with certain maxHealth.
  // Then, it gives the enemy full health to begin with
  grunt.maxHealth = 55;
  grunt.health = grunt.maxHealth;
  printf("%d\n\n", getHealth(&grunt));
  resetHealth(&grunt);
  return 0;
}
*/

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
typedef struct {
  char * name;
  // health measure the CURRENT health of the enemy. Does NOT have to be equal to maxHealth
  int health;
  // maxHealth measures the total health of the enemy
  int maxHealth;
  // This measures HOW MUCH damage an enemy can deal to a player
  // (Ex: if damage was the integer 5, an enemy can deal 5 damage to the player.)
  int damage;
  char * type;
} Enemy;

typedef struct {
  Enemy boss;
  int bounty;
  int specialDamage;
} Boss;

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
  return self->health == 0;
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

#include <stdio.h>
#include <stdbool.h>
#include "player.h"
typedef struct {
  char * name;
  int health;
  // This measures HOW MUCH damage an enemy can deal to a player
  // (Ex: if damage was the integer 5, an enemy can deal 5 damage to the player.)
  int damage;
  char * type;
} Enemy;

typedef struct {
  Enemy boss;
  float bounty;
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

int main() {
  // main is used for TESTING only
  Enemy grunt = {.name = "James", .health = 0, .damage = 4, .type="Grunt"};

  
  printf("%s\n\n", getName(&grunt));
  printf("%d\n\n", isDefeated(&grunt));
  return 0;
}

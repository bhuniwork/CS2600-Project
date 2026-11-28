#ifndef ENEMY_H
#define ENEMY_H

#include <stdbool.h>

typedef struct {
	char *name; //Enemy name
	int health; //Measures current health of enemy
	int maxHealth; //Measures how much damage an enemy caan deal to playeer
	int damage; //Enemy damage amount
	char *type;
}Enemy;

typedef struct {
	Enemy boss;
	int bounty;
	int specialDamage;
}Boss;

//Function headers for enemy class. Will be implemented in Enemy.c
char *getName(Enemy *self);
int getHealth(Enemy *self);
int getDamage(Enemy *self);
char *getType(Enemy *self);
bool isDefeated(Enemy *self);
void resetHealth(Enemy *self);
void takeDamage(Enemy *self, int amount);

#endif


	

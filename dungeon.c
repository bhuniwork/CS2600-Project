/*
Group 2:
    Matthew Zelaya
    Brandon Ho
    Chloe Lirio
    Logan Quon
    Derrehn Robles
*/
#define MINIAUDIO_IMPLEMENTATION
#include "miniaudio.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "dungeon.h"
#include "player.h"
#include "Items.h"
#include "enemy.h"

// Define the audio engine (Implemented by Derrehn)
static ma_engine engine;
static bool audioReady = false;

int x = 0;
int y = 0;

char dungeon_platform[12][12];
int health = 3;
int playerX = 0;
int playerY = 0;
bool hitWall = false;
bool fightingEnemy = false;

//Starts game audio. Returns false if unable to start
bool initializeAudio(void) {
  audioReady = (ma_engine_init(NULL, &engine) == MA_SUCCESS);
  return audioReady;
}

void printAsciiArt(char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening file: %s\n", filename);
        return;
    }
    char line[256];
    while (fgets(line, sizeof(line), file)) {
        printf("%s", line);
    }
    fclose(file);
}

//Terminates game audio
void shutdownAudio(void) {
	if(audioReady) {
	   ma_engine_uninit(&engine);
	   audioReady = false;
	}
}
            

// character positions ONLY

int positionX(void){
    
   return (rand() % 10) + 1;
}

int positionY(void){
    
   return (rand() % 10) + 1;
}



void initializeDungeon(void){
        //play game start sound effect
        ma_engine_play_sound(&engine, "SoundClips/stone_push_medium.wav", NULL);
        // The Grid itself with assets
        char blank_space = '.';
        char wall = '#';
        char playerChar = 'P'; 
        char enemy = 'e';
        char item = '$';
        
    
        //char enemies_bosses[3][10] = {"G3CK13","D0NC1C","K31THL3Y"}; //bosses holds 3 bosses, up to 10 characters characters MAX
        //char enemies_Boss = 'B';
        

        //initialize the blank 2d array

        //will initialize a full blank dungeon.
        for (int r = 0; r < 12; r++){
            for (int c = 0; c < 12; c++){
                if(r == 0 || r == 11 || c == 0 || c == 11){
                    dungeon_platform[r][c] = wall;
                    } else {
                    dungeon_platform[r][c] = blank_space;
                    }
                }
            }

         dungeon_platform[10][11] = blank_space;

         playerX = 6;
         playerY = 6;
         dungeon_platform[playerX][playerY] = playerChar;
        
        // NON-Randomized spawns start here, beware for mess!
	
        //Vertical walls in the dungeon (longer than 2)
         for (int r = 0; r <= 2; r++){
            dungeon_platform[r][2] = wall;
         }
         
         for (int r = 0; r <=2 ; r++){
            dungeon_platform[r][5] = wall;
         }

          for (int r = 4; r <= 6; r++){
            dungeon_platform[r][8] = wall;
         }

         //Single walls + diagonal wall
        
        dungeon_platform[3][3] = wall;
        dungeon_platform[10][7] = wall;
        dungeon_platform[10][9] = wall;
        dungeon_platform[1][7] = wall;
        dungeon_platform[10][5] = wall;
        dungeon_platform[6][10] = wall;

        //diagonals are assigned
        for (int i = 0; i < 3; i++){
            dungeon_platform[5+i][4-i] = wall;
        }

        //horizontal walls
        for (int c = 7; c <= 10; c++) {
            dungeon_platform[8][c] = wall;
        }

        for (int c = 2; c <= 4; c++) {
            dungeon_platform[9][c] = wall;
        }
//enemies and items spawn, refered to item and enemy classes

//enemy spawnPoints
dungeon_platform[2][1] = enemy;
dungeon_platform[2][9] = enemy;
dungeon_platform[3][4] = enemy;
dungeon_platform[7][5] = enemy;
dungeon_platform[9][7] = enemy;

//item spawnPoints
dungeon_platform[1][1] = item;
dungeon_platform[1][6] = item;
dungeon_platform[5][10] = item;
dungeon_platform[10][8] = item;
dungeon_platform[10][6] = item;


}


void printDungeon(void){
    
    printf("\n");
    
    if (fightingEnemy){
        printAsciiArt("AsciiGrapics/dragon.txt");
        printf("------------------------\n");
        printf("What will you do?\n");
        printf("1. Attack\n");
        printf("2. Use Item\n");
        printf("Enter Q to quit\n");
    
    } else {
    for (int r = 0; r < 12; r++){
        for (int c = 0; c < 12; c++){
            printf("%c ", dungeon_platform[r][c]);
            }
        printf("\n");
        }
        printf("------------------------\n");
        printf("Enter Q to quit\n");
        printf("Enter W A S D to move ");
    }        
    
}


void playerControl(char key, player *p1){
    
    int tempRow = playerX;
    int tempCol = playerY;
    
    if (key == 'W' || key == 'w'){
        tempRow--;
    } else if (key == 'A' || key == 'a'){
        tempCol--;
    } else if (key == 'S' || key == 's'){
        tempRow++;
    } else if (key == 'D' || key == 'd'){
        tempCol++;
    } else {
        return;
    }
    
    //Player movement here (Centered) 
    //&& dungeon_platform[tempRow][tempCol] != 'e' removed to allow player to encounter enemy
    if (dungeon_platform[tempRow][tempCol] != '#' && !fightingEnemy){
         //Play sound effect for item collection
        if (dungeon_platform[tempRow][tempCol] == '$'){
            //player collects and item
            ma_engine_play_sound(&engine, "SoundClips/coin_collect.wav", NULL);
            Items item = getRandomItem();
            printf("\n!!Collected an item: %s!!\n", item.name);
            addPlayerItem(p1, item);
        } else if (dungeon_platform[tempRow][tempCol] == 'e'){
            //player encounters an enemy
            ma_engine_play_sound(&engine, "SoundClips/weapon_pick_up.wav", NULL);
            printf("\n!!Encountered an enemy!!\n");
            fightingEnemy = true;
            Enemy grunt = {.name = "James", .health = 0, .damage = 4, .type="Grunt"};
            
            
        } else {
            //play movement sound effect different for direction
            if(key == 'W' || key == 'w'){
                ma_engine_play_sound(&engine, "SoundClips/foley_footstep_vinyl_4.wav", NULL);
            } else if (key == 'A' || key == 'a'){
                ma_engine_play_sound(&engine, "SoundClips/foley_footstep_vinyl_3.wav", NULL);
            } else if (key == 'S' || key == 's'){
                ma_engine_play_sound(&engine, "SoundClips/foley_footstep_vinyl_4.wav", NULL);
            } else if (key == 'D' || key == 'd'){
                ma_engine_play_sound(&engine, "SoundClips/foley_footstep_vinyl_3.wav", NULL);
            }
           
        }
        dungeon_platform[playerX][playerY] = '.';
        playerX = tempRow;
        playerY = tempCol;
        dungeon_platform[playerX][playerY] = 'P';
       
        

    } else if (dungeon_platform[tempRow][tempCol] == '#'){
        
        ma_engine_play_sound(&engine, "SoundClips/cancel.wav", NULL);
        printf("\n!!Hit a wall!!\n");
        
    }

}

void UIGameStart(void){
    
    printf("Welcome to the Insert Game Name!\n");
    printf("Instructions:\n");
    printf("Use W A S D keys to move your character through the dungeon (Marked by P)\n");
    printf("Collect items($) and avoid enemies (e).\n");
    printf("Press Q to quit the game at any time.\n");
    printf("Good luck and have fun!\n");
    printf("Enter S to start the game...\n");
    char key;
    while(scanf(" %c", &key) == 1 && key != 'S') {
        UIGameStart();
    }
}

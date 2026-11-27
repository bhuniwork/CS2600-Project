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

// Define the audio engine (Implemented by Derrehn)
ma_engine engine;

int x = 0;
int y = 0;

char dungeon_platform[12][12];
int health = 3;
bool hitWall = false;
            

// character positions ONLY

int positionX(){
    
   return (rand() % 10) + 1;
}

int positionY(){
    
   return (rand() % 10) + 1;
}



void initializeDungeon(){

        // The Grid itself with assets
        char blank_space = '.';
        char wall = '#';
        char player = 'P'; 
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
         dungeon_platform[playerX][playerY] = player;
        
        // NON-Randomized spawns start here, beware for mess!
//------------------------------------------------------------------------------------
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
//------------------------------------------------------------------------------
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


//------------------------------------------------------------------------------
void printDungeon(){
    
    printf("\n");
    
    for (int r = 0; r < 12; r++){
        for (int c = 0; c < 12; c++){
            printf("%c ", dungeon_platform[r][c]);
            }
        printf("\n");
        }
            
    printf("---------------------\n");
}


//-------------------------------------------------------------------------------
void playerControl(char key){
    
    int tempRow = playerX;
    int tempCol = playerY;
    
    if (key == 'W' || key == 'w'){
        ma_engine_play_sound(&engine, "SoundClips/foley_footstep_concrete_1.wav", NULL);
        tempRow--;
    } else if (key == 'A' || key == 'a'){
        ma_engine_play_sound(&engine, "SoundClips/foley_footstep_vinyl_4.wav", NULL);
        tempCol--;
    } else if (key == 'S' || key == 's'){
        ma_engine_play_sound(&engine, "SoundClips/foley_footstep_concrete_1.wav", NULL);
        tempRow++;
    } else if (key == 'D' || key == 'd'){
        ma_engine_play_sound(&engine, "SoundClips/foley_footstep_vinyl_4.wav", NULL);
        tempCol++;
    } else {
        return;
    }
    
    //Player movement here (Centered)
    if (dungeon_platform[tempRow][tempCol] != '#' && dungeon_platform[tempRow][tempCol] != 'e'){
        
        dungeon_platform[playerX][playerY] = '.';
        playerX = tempRow;
        playerY = tempCol;
        dungeon_platform[playerX][playerY] = 'P';

    } else if (dungeon_platform[tempRow][tempCol] == '#'){
        
        ma_engine_play_sound(&engine, "SoundClips/foley_footstep_vinyl_3.wav", NULL);
        printf("\n!!Hit a wall!!\n");
        
    }

}

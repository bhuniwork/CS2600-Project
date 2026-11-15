
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int x = 0;
int y = 0;

char dungeon_platform[12][12];
int health = 3;
bool hitWall = false;

// will become important in regards to moving things.
int playerX = 6;
int playerY = 6;
            

// characters

int positionX(){
    
   return rand() % 11;
}

int positionY(){
    
   return rand() % 11;
}



void initializeDungeon(){

        // The Grid itself with assets
        char blank_space = '.';
        char wall = '#';
        char player = 'P'; 
        int numberCount = 0;
        int numberCountItem = 0;
        char enemy = 'e';
        char itemP = '@';
        //putting player for now until classes for player comes.
        //char enemies_bosses[3][10] = {"G3CK13","D0NC1C","K31THL3Y"}; //bosses holds 3 bosses, up to 10 characters characters MAX
        //char enemies_generic = 'e';
        //char enemies_Boss = 'B';
        

        //initialize the blank 2d array

        //will intitialize a full blank dungeon.
        for (int r = 0; r < 12; r++){
            for (int c = 0; c < 12; c++){
                if(r == 0 || r == 11 || c == 0 || c == 11){
                    dungeon_platform[r][c] = wall;
                    
                    }else{
                    dungeon_platform[r][c] = blank_space;
                }
            }
        }
        
        // vertical walls
        for (int r = 3; r <=7; r++){
            dungeon_platform[r][3] = wall;
            dungeon_platform[r][8] = wall;
            
            }
            
                        
        //spawns enemies in the dungeon
         
        while (numberCount < 4){
            bool enemyInSameRow = false;
            bool isBlankSpace = false;
            
            int randomX = (rand() % 10) + 1;
            int randomY = (rand() % 10) + 1;
        
            if(dungeon_platform[randomX][randomY] == blank_space) {
                isBlankSpace = true;
                    }
            
            for (int c = 0; c < 12; c++){
                if (dungeon_platform[randomX][c] == enemy){
                        enemyInSameRow = true;
                    }
            }    
            
                if (enemyInSameRow == false && isBlankSpace == true){
                    dungeon_platform[randomX][randomY] = enemy;
                    numberCount++;
                    }
                }
                
                
        while (numberCountItem < 3){
            bool itemsInSameRow = false;
            bool isBlankSpace = false;
            
            int randomX = (rand() % 10) + 1;
            int randomY = (rand() % 10) + 1;
        
            if(dungeon_platform[randomX][randomY] == blank_space) {
                isBlankSpace = true;
                    }
            
            for (int c = 0; c < 12; c++){
                if (dungeon_platform[randomX][c] == itemP){
                        itemsInSameRow = true;
                    }
            }    
            
                if (itemsInSameRow == false && isBlankSpace == true){
                    dungeon_platform[randomX][randomY] = itemP;
                    numberCountItem++;
                    }
                }
        dungeon_platform[playerX][playerY] = player;
}

void printDungeon(){
    
    printf("\n");
    
    for (int r = 0; r < 12; r++){
        for (int c = 0; c < 12; c++){
            printf("%c ", dungeon_platform[r][c]);
            }
        printf("\n");
        }
            
    printf("\n Health: %d, Class: Player(filler)\n Your next Move?", health);
}
        

void playerControl(char key){
    
    int tempRow = playerY;
    int tempCol = playerX;
    
    if (key == 'A'){
        tempRow--;
    } else if (key == 'W'){
        tempCol--;
    } else if (key == 'D'){
        tempRow++;
    } else if (key == 'S'){
        tempCol++;
    }
    
    if (dungeon_platform[tempRow][tempCol] != '#'){
        
        dungeon_platform[playerX][playerY] = '.';
        playerY = tempRow;
        playerX = tempCol;
        dungeon_platform[playerX][playerY] = 'P';
    } else {
        printf("Hit a wall!");
    }

}

int main()
{
    
    char stop;
    
    initializeDungeon();
    printDungeon();
    
    while (true)
    {
        printf("\nTEST: press q to quit: (HOLD SHIFT THEN WASD)");
        scanf(" %c", &stop);
    
        if (stop != 'q') {
        
        playerControl(stop);
        printDungeon();
        } else {
        
        break;
        
        }
    }

    return 0;

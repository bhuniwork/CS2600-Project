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

int main()
{

    //Starts game audio. Do not put anything above this line.
    initializeAudio();
    //Initializes the player with its default values. Also creates an array that serves as the items the player currently has. Use the functions in the player class to get/modify/remove the values
    player p1;
    playerDefaultConfiguration(&p1);
    initializeDungeon();
    printDungeon();
    
    //Stops game audio, put everything else above this line
    shutdownAudio();
    return 0;
}

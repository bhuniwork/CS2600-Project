# CS2600-Project
CS2600 Project
------------------------
# PROJECT PROPOSAL 
ASCII Dungeon, Group Two 

Our group proposes a dungeon-style game where the user descends through many levels in a dungeon, fighting dangerous foes of increasing difficulty, and culminating in a boss's battle. Our game will be turn-based, so the user and enemy will take turns attacking each other.  Before each round, the user will be given a randomized item that may impact the course of the battle. For each turn, the user will have the choice to either attack the enemy or use an item (similar to Pokémon and older Final Fantasy games).  We chose a dungeons-style game for our final project because many members in our group enjoy programming games as a hobby. Therefore, we want to showcase our group's passion for programming games by making a dungeon-style game as our final project. We also chose this as our final project because it allows a high amount of interactivity from the user, thus making the game feel unpredictable each time it is played. For example, on a given turn, a user might decide to attack the enemy or use a consumable item (healing potion or a damage buff). In addition, the user will receive a randomized item that may help them in battle before the start of each battle. Because we plan to use the rand() function from the <stdlib.h> library, the item the user receives may be different in each round. We will also use the rand() function when it comes to damage inflicted by the player and the damage inflicted to the player to add another degree of unpredictability to each battle. We are also looking into implementing object-oriented (OOP) programming to better organize a player’s attributes/abilities. Our group expects two main challenges with this project. The first is balancing the difficulty of the game. We don't want the game to be so easy that it gets boring fast. However, we don't want the game to be impossible to beat to the point where the game is not enjoyable to play. Another challenge is collaboration since we all have different schedules and routines, making it difficult to work on the project simultaneously. To address these challenges and any potential conflicts, we have set up a group chat, which allows for instant communication with all of our group members. Our plan to handle group work is to figure out all the components needed to make this game and divide it evenly between the 5 of us. This ensures that each of us is equally contributing to the project and making sure no one has an overwhelming amount of work to do. 

--------------------------
# TIMELINE 

Week 1:  

Start defining and programming object-oriented classes (Player, Enemy, DungeonRoom, Boss etc.) 

Define the variables used in our various classes (playerHealth, playerDamage, enemyHealth, enemyDamage, enemyType, etc.)  

Define functions in our various classes that will be reused. The following includes (but not limited to): getPlayerHealth(), getEnemyHealth(), setPlayerHealth(int n), setEnemyHealth(int n), setPlayerDamage(int n), setEnemyDamage(int n), etc. 

Program object-oriented methods to create objects of the player, enemy, and any weapons used in gameplay.  Ex: getPlayerhealth() will be in the Player class that returns the health attribute). Each class definition will use typedef struct {} [name of class] 

Week 2: 

Create a GitHub to allow for collaborative effort between the team. 

Decide number of levels our dungeon will have, how much health each enemy will have, the damage range each enemy has, and the items the user can receive each round.  

Define and implement an array that will store the items the user can receive each round (ex: Healing items, Damage Buffs, etc.).  

Program and test the logic that will allow the player and enemy to take turns until one of their health reaches 0. Once the logic succeeds, we will implement the rand() method so player damage and enemy damage differs for each turn. (most likely through while loops) We will also give the user the option to use an item during battle 

Give our game a more unique identity. Start listing boss name concepts. (Ex: G3CK13  D0NC1C, K31THL3Y, etc.). Come up with a name for our game. 

Week 3: 

Adding sound effects for actions in the mage (Attacking sounds, Getting attacked sound, Defeat sound, Victory sound, Item use sound, Blocking attack sound, Battle Beguin sound, Menu browsing sound, Start menu theme song). 

Basic ascii pattern graphics (Finalizing UI elements). Ex: Enemy and boss character scenes, Enemy reaction to damage graphic, Enemy attacking graphic, User main character graphic, Game start screen graphic 

Week 4: 

Program a function that displays instructions on how to play the game and create a makefile for our project. 

Playtest / Debug our game to ensure that the difficulty is balanced, that is, ensure the game is not too easy nor too hard. Make adjustments to player / boss health and damage as necessary 

Work on our project report (explaining how our program works and citing all of the references we used throughout our project). Create a readme file and tar.gz archive. 

Get together and practice our live demo presentation to ensure everything works as intended and that we are prepared to speak in front of the class. 

 

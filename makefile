all: game

game: player.c enemy.c Items.c dungeon.c main.c player.h Items.h dungeon.h enemy.h
	gcc -o game player.c enemy.c Items.c dungeon.c main.c -lm -lpthread -ldl

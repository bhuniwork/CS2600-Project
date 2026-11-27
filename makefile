all: game

game: player.c enemy.c Items.c dungeon.c main.c
	gcc -o game player.c enemy.c Items.c dungeon.c main.c player.h Items.h dungeon.h -lm -lpthread -ldl

#include "Structs_and_enum.h"
#include <random>
#include <iostream>
#include <ctime>

int map[30][10];
enum tile_type entrance = 	ENTRANCE;
enum tile_type end = 		END;
enum tile_type spike_trap = 	SPIKE_TRAP;
enum tile_type spike_trap_ex = 	SPIKE_TRAP_EX;
enum tile_type qs_trap = 	QS_TRAP;
enum tile_type qs_trap_ex = 	QS_TRAP_EX;
enum tile_type insult_trap = 	INSULT_TRAP;
enum tile_type insult_trap_ex = INSULT_TRAP_EX;
enum tile_type good_potion = 	GOOD_POTION;
enum tile_type good_potion_ex = GOOD_POTION_EX;
enum tile_type bad_potion = 	BAD_POTION;
enum tile_type bad_potion_ex = 	BAD_POTION_EX;
enum tile_type empty = 		EMPTY;
enum tile_type empty_explored = EMPTY_EX;

int randomInt(int x, int y)
{
	std::random_device rd;
	std::mt19937 eng(rd());
	std::uniform_int_distribution<> uni(x,y);
	return uni(eng);
}

void fillArray()
{
	//fill entire array with empty tiles
	for(int i = 0; i < 30; i++)
	{
		for(int j = 0; j < 10; j++)
		{
			map[i][j] = empty;
		}
	}

	for(int i = 0; i < 30; i++)
	{
		for(int j = 0; j < 5; j++)
		{
			//random column to fill, to limit unbeated maps
			int col = randomInt(0,9);		
			
			//generate random 'trap' tile to place
			int r = randomInt(0, 4);
			if(r == 0){map[i][col] = spike_trap;}
			if(r == 1){map[i][col] = qs_trap;}
			if(r == 2){map[i][col] = insult_trap;}
			if(r == 3){map[i][col] = good_potion;}
			if(r == 4){map[i][col] = bad_potion;}
		}
	}
	map[0][0] = entrance;
	map[29][9] = end;
}

int main()
{
	fillArray();
	for(int i = 0; i < 30; i++)
	{
		for(int j = 0; j < 10; j++)
		{
			std::cout << map[i][j] << "\t";
		}
		std::cout << "\n";
	}
}

/*
Created by Parker Evans on 9/19
with the help of Skyler Clark 

This is the map file we are creating a char array to fill all of the field with an '*' and then when explored to a 'space'


*/

#include <iostream>
#include <random>



/*
Here we created the map as a global two dimensional array, since we will never change its size.
*/
int map[30][10];
enum tile_type entrance = 	ENTRANCE;
enum tile_type exit = 		EXIT;
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
enum tile_type empty_explored = EMPTY_EXPLORED;

//generates unbiased random number between specified range
tile_type randomInt()
{
	std::random_device rd;
	std::mt19937 rng(rd());
	std::uniform_int_distriubution<int> uni(0,5);

	//if()
	int random_integer = uni(rng);
}

void fillArray()
{
	for(int i = 0; i < 30; i++)
	{
		for(int j = 0; j < 10; j++)
		{
			if(i == 0 && j == 0){map[i][j] = entrance; continue;}
			if(i == 29 && j == 9){map[i][j] = EXIT; continue;}
			map[i][j] = randomInt();
		}
	}
}

/*
Here we are creating the explored room method to change the tile. Need to add change of status to tiles.
*/
void found_empty(x,y){
	map[x][y] = 32;	// This is a space for empty
}

void found_spike(x,y){
	map[x][y] = 94;	 // This is a carrot for spike
}

void found_qs(x,y){
	map[x][y] = 33;	// This is and exclamation mark
}

void found_insult(x,y){
	map[x][y] = 63;	// This is the question mark
}
void found_good_potion(x,y){
	map[x][y] = 43;	// This is the plus signal
}

void found_bad_potion(x,y){
	map[x][y] = 35; // This is the pound sign
}

void set_entrance(){
	map[0][0] = 91; // This is the open bracket for the start space
}

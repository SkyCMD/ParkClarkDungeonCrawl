#include "Structs_and_enum.h"
#include <random>
#include <iostream>
#include "Hero.h"
#include "Map.h"

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
//////MAPS.CPP METHODS
//fills array first with blanks, then with randomized special tiles, then creates static entrance and exit
int randomInt(int x, int y)
{
	//srand(time(NULL));
	std::random_device rd;
	std::mt19937 eng(rd());
	std::uniform_int_distribution<> uni(x,y);
	return uni(eng);
}

//fills array first with blanks, then with randomized special tiles, then creates static entrance and exit
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
			//random column to fill, up to 5 special tiles per row, limits unbeatable maps
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
	//place entrance and exit
	map[0][0] = entrance;
	map[29][9] = end;
}

/*
Here we are creating the explored room method of change the tile. Need to add change of status to tiles.
*/
void found_empty(hero h){
	map[h.y][h.x] = empty_ex;	// This is a space for empty
}

hero found_spike(hero h){
	map[h.y][h.x] = spike_trap_ex;	 // This is a carrot for spike
	h = take_damage(h);
	return h;
}

hero found_qs(hero h){
	map[h.y][h.x] = qs_trap_ex;	// This is and exclamation mark
	return take_damage(h);			// come back and change
}

void found_insult(hero h){
	map[h.y][h.x] = insult_trap_ex;	// This is the question mark
}
hero found_good_potion(hero h){
	map[h.y][h.x] = good_potion_ex;	// This is the plus signal
	return gain_health(h);
}

hero found_bad_potion(hero h){
	map[h.y][h.x] = bad_potion_ex; // This is the asterix
	return confuse(h);
}

void set_entrance(){
	map[0][0] = 91; // This is the open bracket for the start space
}

// Parker: I have written up the code for printing the array. Here we are
// using the various ASCII codes to print characters to the array where the 
// enum type corresponds.
void print_array(hero h){
	for(int i=0;i<30;i++){
		for(int j = 0; j<10;j++){
			if(i == h.y && j == h.x){
				std::cout<<"H";
				continue;
			}
			if(map[i][j] <= 5){
				std::cout << char(35);
			}
			if(map[i][j] == 6){
				std::cout<<char(94);
			}
			if(map[i][j] == 7){
				std::cout<< char(33);
			}
			if(map[i][j] == 8){
				std::cout<<char(63);
			}
			if(map[i][j] == 9){
				std::cout<<char(43);
			}
			if(map[i][j] == 10){
				std::cout<<char(42);
			}
			if(map[i][j] == 11){
				std::cout<< char(32);
			}
			if(map[i][j] == 12){
				std::cout<<char(123);
			}
			if(map[i][j] == 13){
				std::cout<<"E";
			}
			
			
		}
		std::cout<<" "<< std::endl;
	}
	
}

int get_tile(hero h)
{
	return map[h.y][h.x];
}
///////HERO.CPP METHODS
hero hero_select()
{
	hero h;
	std::cout << "Ready player 1? Select your hero.\n"
	"A: Indiana Jones. Less health, average movement speed, chance to avoid traps.\n"
	"B: Lightning McQueen. Average health, double movement speed.\n"
	"C: Waxillium. Double health, average movement speed.\n"
	"Please enter A, B, or C.\n\n";
	char mander; 
	std::cin >> mander; 

	while(mander!= 'A' && mander != 'B' && mander != 'C')
	{
		std::cout << "Please eneter a valid selection.\n";
		std::cin >> mander;
	}
	if(mander == 'A'){h.name="Indiana Jones"; h.x=0; h.y=0; h.health=20; h.speed=1;}
	if(mander == 'B'){h.name="Lightning McQueen"; h.x=0; h.y=0; h.health=50; h.speed=2;}
	if(mander == 'C'){h.name="Waxillium"; h.x=0; h.y=0; h.health=100; h.speed=1;}

	return h;
}

// P -- Creating the methods that affect the hero by potions and traps.
hero take_damage(hero h){
	h.health --;
	
	return h;
}

hero gain_health(hero h){
	h.health ++;
	std::cout<<"HP: "<<h.health<<std::endl;
	return h;
}

hero confuse(hero h){
	h.speed*=-1;
	return h;
}


hero move_hero(hero h){

	std::cout<< "Please enter a NSEW direction to move"<<std::endl;
	char step;
	std::cin >> step;
	
	while(step!= 'N' && step!= 'S' && step!= 'E' && step!='W'){
		std::cout<< "That is not a valid direction, learn directions Better! Please enter a N,S,E, or W."<<std::endl;
		std::cin>>step;
	}
	
	if(step == 'N'){
		h.y-=h.speed;
		if(h.y>29){
			std::cout<<"Ouch, you ran into the wall"<<std::endl;
			h = take_damage(h);
			h.y = 29;
		}
		if(h.y<0){
			std::cout<<"Ouch, you ran into the wall"<<std::endl;
			h = take_damage(h);
			h.y=0;
		}
	}
	if(step == 'S'){
		h.y+=h.speed;
		if(h.y>29){
			std::cout<<"Ouch, you ran into the wall"<<std::endl;
			h = take_damage(h);
			h.y = 29;
		}
		if(h.y<0){
			std::cout<<"Ouch, you ran into the wall"<<std::endl;
			h = take_damage(h);
			h.y=0;
		}
	}
	if(step == 'E'){
		h.x+=h.speed;
		if(h.x>9){
			std::cout<<"Ouch, you ran into the wall"<<std::endl;
			h = take_damage(h);
			h.x = 9;
		}
		if(h.x<0){
			std::cout<<"Ouch, you ran into the wall"<<std::endl;
			h = take_damage(h);
			h.x=0;
		}
	}
	if(step == 'W'){
		h.x-=h.speed;
		if(h.x>9){
			std::cout<<"Ouch, you ran into the wall"<<std::endl;
			h = take_damage(h);
			h.x = 9;
		}
		if(h.x<0){
			std::cout<<"Ouch, you ran into the wall"<<std::endl;
			h = take_damage(h);
			h.x=0;
		}
	}
	return h;
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
	hero h1;
	h1.x =0;
	h1.y = 0;
	h1.health = 1000;
	h1.speed = 2;
	h1.name = "Alex";
	print_array(h1);
	
	
	
	move_hero(h1);
	print_array(h1);
	cout<<h1.x<<endl;
	move_hero(h1);
	
	print_array(h1);
	
}

#include "Structs_and_enum.h"
#include <random>
#include <iostream>
#include "Hero.h"

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
using namespace std;
void print_array(hero h){
	int x = h.x;
	int y = h.y;
	for(int i=0;i<30;i++){
		
		for(int j = 0; j<10;j++){
			
			if(map[i][j] == map[h.y][h.x]){
				cout<<"H";
				continue;
			}
			if(map[i][j] <= 5){
				cout << char(35);
			}
			if(map[i][j] == 6){
				cout<<char(94);
			}
			if(map[i][j] == 7){
				cout<< char(33);
			}
			if(map[i][j] == 8){
				cout<<char(63);
			}
			if(map[i][j] == 9){
				cout<<char(43);
			}
			if(map[i][j] == 10){
				cout<<char(42);
			}
			if(map[i][j] == 11){
				cout<< char(32);
			}
			if(map[i][j] == 12){
				cout<<char(123);
			}
			if(map[i][j] == 13){
				cout<<"E";
			}
			
			
		}
		cout<<" "<< endl;
	}
}
///////HERO.CPP METHODS
void take_damage(hero h){
	h.health --;
	cout<<"HP: "<<h.health<<endl;
}

void gain_health(hero h){
	h.health ++;
	cout<<"HP: "<<h.health<<endl;
}

void confuse(hero h){
	h.speed*=-1;
}

void move_hero(hero& h){
	
	
	cout<< "Please enter a NSEW direction to move"<<endl;
	char step;
	cin >> step;
	
	while(step!= 'N' && step!= 'S' && step!= 'E' && step!='W'){
		cout<< "That is not a valid direction, learn directions Better! Please enter a N,S,E, or W."<<endl;
		cout<<step;
		cin>>step;
	}
	
	if(step == 'N'){
		h.y-=h.speed;
		if(h.y>29){
			cout<<"Ouch, you ran into the wall"<<endl;
			take_damage(h);
			h.y = 29;
		}
		if(h.y<0){
			cout<<"Ouch, you ran into the wall"<<endl;
			take_damage(h);
			h.y=0;
		}
	}
	if(step == 'S'){
		h.y+=h.speed;
		if(h.y>29){
			cout<<"Ouch, you ran into the wall"<<endl;
			take_damage(h);
			h.y = 29;
		}
		if(h.y<0){
			cout<<"Ouch, you ran into the wall"<<endl;
			take_damage(h);
			h.y=0;
		}
	}
	if(step == 'E'){
		h.x+=h.speed;
		if(h.x>9){
			cout<<"Ouch, you ran into the wall"<<endl;
			take_damage(h);
			h.x = 9;
		}
		if(h.x<0){
			cout<<"Ouch, you ran into the wall"<<endl;
			take_damage(h);
			h.x=0;
		}
	}
	if(step == 'W'){
		h.x-=h.speed;
		if(h.x>9){
			cout<<"Ouch, you ran into the wall"<<endl;
			take_damage(h);
			h.x = 9;
		}
		if(h.x<0){
			cout<<"Ouch, you ran into the wall"<<endl;
			take_damage(h);
			h.x=0;
		}
	}
	
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

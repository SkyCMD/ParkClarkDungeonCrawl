/***************************************

Project: Dungeon Crawl
Authors: Parker Evans and Skyler Clark
Class:	 CS 3150
Date: 	 21-Sep-2019

***************************************/
#include "Structs_and_enum.h"
#include "Map.h"
#include "Hero.h"
#include <iostream>

int main()
{

	
	hero h;
	fillArray();
	h = hero_select(h);
	
	
	while(h.health > 0 && map[h.y][h.x] != map[29][9]){
		print_array(h);
		move_hero(h);
		int temp = get_tile(h);
		if(temp == 0)
		{
			void found_spike(h);
		}
		if(temp == 1){
			void found_qs(h);
		}
		if(temp == 2)
		{
			void found_insult(h);
		}
		if(temp == 3)
		{
			void found_good_potion(h);
		}
		if(temp == 4)
		{
			void found_bad_potion(h);
		}
		if(temp == 5)
		{
			void found_empty(h);
		}
	}
	std::cout<<"You win maybe";
	return 0;
}

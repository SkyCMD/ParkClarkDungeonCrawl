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
#include <cstdlib>

int main()
{

	
	hero h;
	h = hero_select();
	fillArray();
	h.health = 1;
	 while(h.health > 0){
		 print_array(h);
		 h = move_hero(h);
		 int temp = get_tile(h);
		 if(temp == 13)
		 {
			 break;
		 }
		 if(temp == 0)
		 {
			 h = found_spike(h);
		 }
		 if(temp == 1){
			 h = found_qs(h);
		 }
		 if(temp == 2)
		 {
			 h = found_insult(h);
		 }
		 if(temp == 3)
		 {
			 h = found_good_potion(h);
		 }
		 if(temp == 4)
		 {
			 h = found_bad_potion(h);
		 }
		 if(temp == 5)
		 {
			 h = found_empty(h);
		 }
		 std::cout<<"HP: "<<h.health<<std::endl;
	 }

	std::cout<<"You win maybe";
	return 0;
}

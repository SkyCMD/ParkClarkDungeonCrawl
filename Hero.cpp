#include "Structs_and_enum.h"
#include <string>
#include <iostream>


void hero_select(hero &h)
{
	std::cout << "Ready player 1? Select your hero.\n"
	"A: Indiana Jones. Less health, average movement speed, chance to avoid traps.\n"
	"B: Lightning McQueen. Average health, double movement speed.\n"
	"C: Waxillium. Double health, average movement speed.\n"
	"Please enter A, B, or C.\n\n";
	char mander; 
	std::cin >> mander; 

	if(mander == 'A'){h.name="Indiana Jones"; h.x=0; h.y=0; h.health=20; h.speed=1;}
	if(mander == 'B'){h.name="Lightning McQueen"; h.x=0; h.y=0; h.health=50; h.speed=2;}
	if(mander == 'C'){h.name="Waxillium"; h.x=0; h.y=0; h.health=100; h.speed=1;}
}

// P -- Creating the methods that affect the hero by potions and traps.
void take_damage(hero h){
	h.health --;
	std::cout<<"HP: "<<h.health<<std::endl;
}

void gain_health(hero h){
	h.health ++;
	std::cout<<"HP: "<<h.health<<std::endl;
}

void confuse(hero h){
	h.speed*=-1;
}

void move_hero(hero& h){
	
	
	std::cout<< "Please enter a NSEW direction to move"<<std::endl;
	char step;
	std::cin >> step;
	
	while(step!= 'N' && step!= 'S' && step!= 'E' && step!='W'){
		std::cout<< "That is not a valid direction, learn directions Better! Please enter a N,S,E, or W."<<std::endl;
		std::cout<<step;
		std::cin>>step;
	}
	
	if(step == 'N'){
		h.y-=h.speed;
		if(h.y>29){
			std::cout<<"Ouch, you ran into the wall"<<std::endl;
			take_damage(h);
			h.y = 29;
		}
		if(h.y<0){
			std::cout<<"Ouch, you ran into the wall"<<std::endl;
			take_damage(h);
			h.y=0;
		}
	}
	if(step == 'S'){
		h.y+=h.speed;
		if(h.y>29){
			std::cout<<"Ouch, you ran into the wall"<<std::endl;
			take_damage(h);
			h.y = 29;
		}
		if(h.y<0){
			std::cout<<"Ouch, you ran into the wall"<<std::endl;
			take_damage(h);
			h.y=0;
		}
	}
	if(step == 'E'){
		h.x+=h.speed;
		if(h.x>9){
			std::cout<<"Ouch, you ran into the wall"<<std::endl;
			take_damage(h);
			h.x = 9;
		}
		if(h.x<0){
			std::cout<<"Ouch, you ran into the wall"<<std::endl;
			take_damage(h);
			h.x=0;
		}
	}
	if(step == 'W'){
		h.x-=h.speed;
		if(h.x>9){
			std::cout<<"Ouch, you ran into the wall"<<std::endl;
			take_damage(h);
			h.x = 9;
		}
		if(h.x<0){
			std::cout<<"Ouch, you ran into the wall"<<std::endl;
			take_damage(h);
			h.x=0;
		}
	}
}

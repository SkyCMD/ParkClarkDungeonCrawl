#include "Structs_and_enum.h"
#include <string>
#include <iostream>

double score{0};
double percent_health{100.00};
int health;
int steps{0};
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
	if(mander == 'A'){h.name="Indiana"; h.x=0; h.y=0; h.health=30; h.speed=1;}
	if(mander == 'B'){h.name="Lightning"; h.x=0; h.y=0; h.health=50; h.speed=2;}
	if(mander == 'C'){h.name="Waxillium"; h.x=0; h.y=0; h.health=80; h.speed=1;}
	health = h.health;

	return h;
}

// P -- Creating the methods that affect the hero by potions and traps.
hero take_damage(hero h){
	h.health --;
	
	return h;
}

hero gain_health(hero h){

	int rint = rand()%6;
	h.health += rint;
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
	steps++;	
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

int calc_score(hero h) 
{
	
	std:: cout<< " YOur hero's start health is "<<health<<"Your ending health is "<< h.health<<std::endl;
	
	return (1/static_cast<double>(steps)) * (static_cast<double>(h.health) * 1000 / static_cast<double>(health));

}

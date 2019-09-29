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

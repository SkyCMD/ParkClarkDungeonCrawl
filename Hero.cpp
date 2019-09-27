#include <string>
#include <iostream>

hero hero_select()
{
	std::cout << "Ready player 1? Select your hero.\n"
	"A: Indiana Jones. Less health, average movement speed, chance to avoid traps.\n"
	"B: Lightning McQueen. Average health, double movement speed.\n"
	"C: Waxillium. Double health, average movement speed.\n"
	"Please enter A, B, or C.\n\n";

	cin >> char hero; 

	if(hero == 'A'){hero h; h.name="Indiana Jones"; h.x=0; h.y=0; h.health=20; h.speed=1;}
	if(hero == 'B'){hero h; h.name="Lightning McQueen"; h.x=0; h.y=0; h.health=50; h.speed=2;}
	if(hero == 'C'){hero h; h.name="Waxillium"; h.x=0; h.y=0; h.health=100; h.speed=1;}
	return h;
}

// P -- Creating the methods that affect the hero by potions and traps.
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

void move(hero h){
	
	cout<< "Please enter a NSEW direction to move"<<endl;
	char step;
	cin >> step;
	
	while(step!='N'||step!'S'||step!='E'||step!='W'){
		cout<< "That is not a valid direction, learn directions Better! Please enter a N,S,E, or W."<<endl;
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

#include <string>
#include <iostream>



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
		cout<< "That is not a valid direction, Learn Directions Better! Please enter a N,S,E, or W."<<endl;
		cin>>step;
	}
	
	if(step == 'N'){
		h.y-=h.speed;
		if(h.y>30){
			cout<<"Ouch, you ran into the wall"<<endl;
			take_damage(h);
		}
		if(h.y<0){
			cout<<"Ouch, you ran into the wall"<<endl;
			take_damage(h);
		}
	}
	if(step == 'S'){
		h.y+=h.speed;
	}
	if(step == 'E'){
		h.x+=h.speed;
	}
	if(step == 'W'){
		h.x-=h.speed;
	}
	
	
}

/*
Created by Parker Evans on 9/19
with the help of 

This is the map file we are creating a char array to fill all of the field with an '*' and then when explored to a 'space'


*/

#include <iostream>



/*
Here we created the map as a global two dimensional array, since we will never change its size.
*/
char map[10][30];

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

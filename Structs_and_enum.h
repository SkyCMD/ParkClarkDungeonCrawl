#ifndef STRUCTSENUMS
#define STRUCTSENUMS

#include <string>


struct hero
{
	std::string name;
	int x;
	int y;
	int health;
	int speed;
};

enum tile_type
{
	SPIKE_TRAP, 	//0
	QS_TRAP,	//1	
	INSULT_TRAP,	//2
	GOOD_POTION,	//3	
	BAD_POTION,	//4
	EMPTY,		//5	//#	35
	SPIKE_TRAP_EX,	//6	//^	94
	QS_TRAP_EX,	//7	//!	33
	INSULT_TRAP_EX,	//8	//?	63
	GOOD_POTION_EX,	//9	//+	43
	BAD_POTION_EX,	//10	//*	42
	EMPTY_EX,	//11	//SPACE	32
	ENTRANCE,	//12	//{ 	123
	END,		//13
};
#endif


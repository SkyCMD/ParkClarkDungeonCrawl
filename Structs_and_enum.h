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
	SPIKE_TRAP,
	QS_TRAP,		
	INSULT_TRAP,
	GOOD_POTION,		
	BAD_POTION,
	EMPTY,
	SPIKE_TRAP_EX,		//^	94
	QS_TRAP_EX,		//!	33
	INSULT_TRAP_EX,		//?	63
	GOOD_POTION_EX,		//+	43
	BAD_POTION_EX,		//#	35
	EMPTY_EX,		//SPACE	32
	ENTRANCE,		//{ 	123
	EXIT,
};
#endif


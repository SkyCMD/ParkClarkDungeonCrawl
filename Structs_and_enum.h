#include <string>

struct hero
{
	std::string name;
	int x;
	int y;
	int health;
	int speed;
	bool isConfused;
};

enum tile_type
{
	SPIKE_TRAP,
	SPIKE_TRAP_EX,		//^	94
	QS_TRAP,		
	QS_TRAP_EX,		//!	33
	INSULT_TRAP,
	INSULT_TRAP_EX,		//?	63
	GOOD_POTION,		
	GOOD_POTION_EX,		//+	43
	BAD_POTION,
	BAD_POTION_EX,		//#	35
	EMPTY,
	EMPTY_EX,		//SPACE	32
	ENTRANCE,		//{ 	123
	EXIT,
};

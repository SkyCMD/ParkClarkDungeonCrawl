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
	SPIKE_TRAP_EX,		//^
	QS_TRAP,		
	QS_TRAP_EX,		//!
	INSULT_TRAP,
	INSULT_TRAP_EX,		//?
	GOOD_POTION,		
	GOOD_POTION_EX,		//+
	BAD_POTION,
	BAD_POTION_EX,		//#
	EMPTY,
	EMPTY_EX,		//SPACE	
};

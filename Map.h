#ifndef MAP
#define MAP

int map[30][10];
int randomInt(int, int);
void fillArray();
void print_array(hero);
void found_empty(hero);
void found_spike(hero);
void found_qs(hero);
void found_insult(hero);
void found_good_potion(hero);
void found_bad_potion(hero);
void found_set_entrance(hero);
int get_tile(hero);

#endif

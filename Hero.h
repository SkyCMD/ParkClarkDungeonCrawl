#ifndef HERO
#define HERO

hero take_damage(hero);
hero gain_health(hero);
hero confuse(hero);
hero hero_select();
hero move_hero(hero); 
int calc_score(hero);
extern double score;
extern double percent_health;
extern int steps; 
extern int health;

#endif

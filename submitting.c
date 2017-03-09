#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

void pointsHuman(struct players[]);
void pointsOgre(struct players[]);
void pointsElf(struct players[]);
void pointsWizard(struct players[]);
void slotType(struct slot[]);
void allocatePlayers(struct players[]);
void abs(int a);

struct playerFields
{
	char name[20];
	char player_type[10];
	int life_pts = 100;
	int smartness;
	int strength;
	int skill;
	int luck;
	int dexterity;
	int position;
};







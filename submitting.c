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

struct player
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

struct slot
{
	char type[20]; //The type of a slot could be: Level Ground, Hill or City.
};

void pointsHuman(struct players[])
{
	int smartness, strength, skill, luck, dexterity;
	int sum;
	int numPlayers;
	
	for(i=0; i<numPlayers; i++)
	{
		if(players[i].player_type ="Human")
		{
			players[i].smartness = 1 +(rand()%100);
			players[i].strength = 1 +(rand()%100);
			players[i].skill = 1 +(rand()%100);
			players[i].dexterity = 1 +(rand()%100);
			players[i].dexterity = 1 +(rand()%100);
			sum = players[i].smartness + players[i].strength + players[i].skill + players[i].luck + players[i].dexterity;
			
			int check = 1;
			while(check == 1){
				if(human.dexterity + human.luck + human.magicSkills + human.smartness + human.strength >=300){
					players[i].smartness = rand()%100 + 1;
					players[i].strength = rand()%100 + 1;
					players[i].skill = rand()%100 + 1;
					players[i].dexterity = rand()%100 + 1;
					players[i].luck = rand()%100 + 1;
				}
				else{
					check = 0;
				}
			}
		}
	}
	
}

void pointsOgre(struct players[])
{
	int smartness, strength, skill = 0, luck, dexterity;
	
	for(i=0; i<numPlayers; i++)
	{
		if(players[i].player_type = "Ogre")
		{
				players[i].strength = 1 +(rand()%80);
				
				players[i].dexterity = 1 +(rand()%80);
			
					do while(sum <= 50)
					{
						players[i].luck = 1 +(rand()%100);
						
						players[i].smartness = 1 +(rand()%20);
						
						sum = players[i].luck + players[i].smartness;
					}
		}
	}
	
	
}

void pointsElf(struct players[])
{
	int smartness, strength, skill = 0, luck, dexterity;
	
	for(i=0; i<numPlayers; i++)
	{
		if(players[i].player_type = "Elf")
		{
	
					players[i].luck = 60 +(rand()%40);
					
					players[i].smartness  = 70 +(rand()%30);
						
					players[i].strength = 1 +(rand()%50);
						
					players[i].skill = 50 +(rand()%30);
		}
	}
	
}

void pointsWizard(struct players[])
{
	int smartness, strength, skill, luck, dexterity;
	
	for(i=0; i<numPlayers; i++)
	{
		if(players[i].player_type = "Wizard")
		{
			players[i].luck = 50 +(rand()%50);
			
			players[i].smartness = 90 +(rand()%10);
				
			players[i].strength = 1 +(rand()%20);
			
			players[i].skill = 80 +(rand()%20);
		}
	}
		
}





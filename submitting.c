#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

void pointsHuman(struct players[]);
void pointsOgre(struct players[]);
void pointsElf(struct players[]);
void pointsWizard(struct players[]);
void slotType(struct slot[]);
void createPlayers(struct players[]);
void allocatePlayers(struct players[]);
void abs(int a);

int numplayers, numslots;

struct players
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

int main(void)
{
	createPlayers();
	
	
	
	
	
	
	
	
	
	
	
	return 0;
}

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
			while(check == 1)
			{
				if(human.dexterity + human.luck + human.magicSkills + human.smartness + human.strength >=300)
				{
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
			players[i].strength = (rand()%80);
			players[i].dexterity = (rand()%80);
			players[i].luck = (rand()%50);
			players[i].smartness = (rand()%20);
			sum = players[i].luck + players[i].smartness;
			
			int check = 1;
			while(check == 1)
			{
				if(players[i].luck + players[i].smartness > 50)
				{
					players[i].luck = rand()%50;
					players[i].smartness = rand()%20;
				}
				else{
					check = 0;
				}
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

void createPlayers(struct players[])
{
	printf("Please enter the number of players you would like to enter into the game (Maximum 6) : "); 
	scanf("%d", &numplayers);
	
	int invalid=0, invalid1=0;
	while(invalid==0)
	{
		if(numplayers>=0 && numplayers<=6)
		{
			while(invalid1==0)
			{
			for(i=0; i<numPlayers; i++)
			{
				//For each playerNumber, we ask for the the type and name.
				printf("Please enter the name and player type (elf, human, ogre or wizard) for player %d (in lowercase letters) :\n", &i);
				scanf("%s\n", &players[i].name, &players[i].player_type);
				invalid=1;
				
				if(players[i].player_type=="elf" || players[i].player_type=="human" || players[i].player_type=="ogre" || players[i].player_type=="wizard");
				{
					invalid1 = 1;
				}
				else
				{
					printf("Invalid player type.\n");
				}
			}
		}
		else
		{
			printf("Invalid number of players\n");
		}
	}
}
	
void allocatePlayers(struct players[]);
{
	printf("Please select a number of slots (max 20):\n");
	scanf("%d", &numslots);		
	
	int i, j;
	int checked[numplayers];
	
	for(i=0; i<slotsNumber; i++)
	{
		k = rand()%(numslots-1);
		checked[i] = k;
		strcpy(players.position[k], players[i].name);
	}
	
	for(i=0; i<numslots-1; i++)
	{
		j=i+1;
		while(j<numslots)
		{
			if(checked[i] == checked[j])
			{
				for(i=0; i<numslots; i++)
				{
					k = rand()%(numslots-1);
					checked[i] = k;
					strcpy(players.position[k], players[i].name);
				}
				i=-1, j=numslots; //return to start of all loops condition
			}
			else{
				j++;
			}
		}
	}
	
	
	
	
	
	
	

}
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	

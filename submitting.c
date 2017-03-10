#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

    //Function Prototype
void pointsHuman(struct player players[]);
void pointsOgre(struct player players[]);
void pointsElf(struct player players[]);
void pointsWizard(struct player players[]);
void slotType(struct slot slots[]);
void allocatePlayers(struct player players[]);
int abs(int a);
void makeMove(struct player players[], struct slot slots[]);

int numplayers, numslots;
int checked[];

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
	pointsHuman();
	pointsOgre();
	pointsElf();
	pointsWizard();
	createPlayers();
	allocatePlayers();
	slotsType();
	makeMove();
	
	return 0;
}

void pointsHuman(struct players[])
{
	int i;
	int smartness, strength, skill, luck, dexterity;
	int sum;
	
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
	int i;
	
	for(i=0; i<numPlayers; i++)
	{
		if(players[i].player_type = "Ogre")
		{
			players[i].strength = (rand()%80);
			players[i].dexterity = (rand()%80);
			players[i].luck = (rand()%50);
			players[i].smartness = (rand()%20);
			players[i].skill = 0;
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
	int i;
	
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
	int i;
	
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
	
	int i;
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
	
	int i, j, k;
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
	
void slotType(struct slot[])
{
	int i, j;
	
	for (i=0; i < slotsnum; i++).
	{
		j = 1 + rand() % 3; //j selects a random position between 1 and 3.
	
		if(j==1)
		{
			slots.type[i] = "Level Ground";
		}
	
		else if(j==2)
		{
			slots.type[i] = "Hill";
		}
	
		else
		{
			slots.type[i] = "City";
		}
	}
}	

void makeMove(struct player players[], struct slot slots[])
{	
	int move, invalid2, invalid3;
	int attackNumber, attackPlayer;
	int checked[numplayers], checked1[numplayers];
	int swap;
	
	for(gameEnd=0; i<numplayers; i++)
	{
		invalid2 = 0;
		while(invalid2 = 0)
		{
			// Give the option to move players to adjacent slots.
			printf("Player %d is in slot type : %s\n", gameEnd+1, slots[players[gameEnd].position]);
			
			if(checked[gameEnd] == 0)
			{
				printf("Next slot is of type %s (you are in the first slot)", slots[players[gameEnd].position + 1]);
				printf("Player %d: Enter 1 to move to the next slot, or 3 to attack the closest player.\n", i+1);
			}
			else if(checked[gameEnd] == 19)
			{
				printf("Previous slot is of type %s (you are in the final slot)", slots[players[gameEnd].position - 1]);
				printf("Player %d: Enter 2 to move to the previous slot, or 3 to attack the closest player.\n", gameEnd+1);
			}
			else
			{
				printf("Previous slot is of type %s and next slot is of type %s", slots[players[gameEnd].position - 1], slots[players[gameEnd].position + 1]);
				printf("Player %d: Enter 1 to move to the next slot, 2 to move to the previous slot, or 3 to attack the closest player.\n", gameEnd+1);
			}
			
			scanf("%d", &move);
			
			if(move == 1)
			{
				players[gameEnd].position = players[gameEnd].position + 1;
				
				if(slots[players[gameEnd].position].type == "Hill")
				{
					if(players[gameEnd].dexterity < 50)
					{
						players[gameEnd].strength -=10;
					}
					else if(players[gameEnd].dexterity >= 60)
					{
						players[gameEnd].strength +=10;
					}
				}
				else if(slots[players[gameEnd].position].type == "City")
				{
					if(players[gameEnd].smartness > 60)
					{
						players[gameEnd].skill +=10;
						}
					else if(players[gameEnd].smartness <= 50)
					{
						players[gameEnd].dexterity -=10;
					}
				}
				invalid2 = 1;
			}
			
			else if(move == 2)
			{
				players[gameEnd].position = players[i].position - 1;
				
				if(slots[players[gameEnd].position].type == "Hill")
				{
					if(players[gameEnd].dexterity < 50)
					{
						players[gameEnd].strength -=10;
					}
					else if(players[gameEnd].dexterity >= 60)
					{
						players[gameEnd].strength +=10;
					}
				}
				else if(slots[players[gameEnd].position].type == "City")
				{
					if(players[gameEnd].smartness > 60)
					{
						players[gameEnd].skill +=10;
					}
					else if(players[gameEnd].smartness <= 50)
					{
						players[gameEnd].dexterity -=10;
					}
				}
				invalid2 = 0;
			}	
				
			else if(move == 3)
			{
				attkr = gameEnd;
	
				//Find the closest player(The player of the shortest distance in the array of slots).
				for(i=0; i<numplayers-1; i++)
				{
					if(checked[gameEnd] > checked[i])
					{
						checkArr[i] = checked[gameEnd] - checked[i];
					}
					else if(checked[counter] < checked[i])
					{
						checkArr[i] = checked[i] - checked[counter];	
					}
					else
					{
						checkArr[i] = 999;
					}
				}
			
				for(i=0; i<numplayers; i++){
					checked1[i] = checked[i];
				}
			
				check = 0;
				for(i=0; i<numplayers-1; i++){
					for(j=i+1; j<numplayers; j++){
						if(checkArr[i] > checkArr[j]){
							swap = checkArr[i];
							checkArr[i] = checkArr[j];
							checkArr[j] = swap;
							swap = checked1[i];
							checked1[i] = checked1[j];
							checked1[j] = swap;
						}	
					}	
				}
				
				invalid3 = 0;
				while(invalid3 == 0)
				{
					if(checkArr[0] == checkArr[1]){
						printf("Would you like to attack %s (enter 1) or %s (enter 2) : ", players.position[checked1[0]], players.position[checked1[1]]);
						scanf("%d", &attackNumber);
						if(attackNumber == 1){
							attackPlayer = 0;
							printf("You have attacked %s.\n\n", player.position[checked1[attackPlayer]]);
							invalid3 = 1;
						}
						else if(attackNumber == 2){
							attackPlayer = 1;
							printf("You have attacked %s.\n\n", player.position[checked1[attackPlayer]]);
							invalid3 = 1;
						}
						else{
							printf("Invalid"\n\n);
						}
					}
					else{
						attackPlayer = 0;
						printf("You have attacked %s.\n\n", player.position[checked1[attackPlayer]]);
					}
				}
		
				if(players[attkd].strength <= 70)
				{
					players[attkd].life_pts -= players[attkd].strength*0.5;
				}
	
				else if(players[attkd].strength > 70)
				{
					players[attkd].life_pts -= players[attkd].strength*0.3;
				}
				invalid2 = 1;
			}
			else
			{
				printf("Invalid choice\n\n");
			}
		}
	}
	for(i=0; i < numPlayers; i++)
	{
		printf("%s \t %s \t %d", &players[i].name, &players[i].player_type, &players[i].life_pts);
	}
}	
	

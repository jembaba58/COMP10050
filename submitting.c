#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

struct player
{
	char name[15];
	char player_type[10];
	int life_pts;
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

    //Function Prototype
void pointsHuman(struct player players[]);
void pointsOgre(struct player players[]);
void pointsElf(struct player players[]);
void pointsWizard(struct player players[]);
void slotType(struct slot slots[]);
int abs(int a);
void makeMove(struct player players[], struct slot slots[]);

int numplayers, numslots;

int main(void)
{
	srand(time(NULL));
	
	printf("Please enter the number of players you would like to enter into the game (Maximum 6) : "); 
	scanf("%d", &numplayers);
	
	struct player players[numplayers];
	
	int i;
	int invalid=0, invalid1=0;
	
	while(invalid==0)
	{
		if(numplayers>=0 && numplayers<=6)
		{
			while(invalid1==0)
			{
				for(i=0; i<numplayers; i++)
				{
					//For each playerNumber, we ask for the the type and name.
					printf("Please enter the name and player type (elf, human, ogre or wizard) for player %d (in lowercase letters and in the format: player name player type) :\n", i+1);
					scanf("%s %s", players[i].name, players[i].player_type);
					
					if(strcmp(players[i].player_type, "elf") == 0 || strcmp(players[i].player_type, "human") == 0 || strcmp(players[i].player_type, "ogre") == 0 || strcmp(players[i].player_type, "wizard") == 0)
					{
						invalid1 = 1;
					}	
					else
					{
						printf("Invalid player type.\n");
						i--;
					}
				}					
			}
			invalid = 1;
		}
		else
		{
			printf("Invalid number of players\n");
		}
	}
	
	printf("Please select a number of slots (max 20):\n");
	scanf("%d", &numslots);

	struct slot slots[numslots];
	
	int j, k;
	
	for(i=0; i<numplayers; i++)
	{
		k = rand()%(numslots-1);
		players[i].position = k;
	}
	
	for(i=0; i<numplayers-1; i++)
	{
		j=i+1;
		while(j<numplayers)
		{
			if(players[i].position == players[j].position)
			{
				for(i=0; i<numplayers; i++)
				{
					k = rand()%(numslots-1);
					players[i].position = k;
				}
				i=-1, j=numplayers; //return to start of all loops condition
			}
			else{
				j++;
			}
		}
	}
	
	for(i=0; i<numplayers; i++)
	{
		players[i].life_pts = 100;
	}
	
	slotType(slots);
	pointsHuman(players);
	pointsOgre(players);
	pointsElf(players);
	pointsWizard(players);
	makeMove(players, slots);
	
	return 0;
}

void pointsHuman(struct player players[])
{
	printf("\nworking\n");
	
	int i;
	int smartness, strength, skill, luck, dexterity;
	int sum, check;
	
	for(i=0; i<numplayers; i++)
	{
		if(players[i].player_type == "human")
		{
			players[i].smartness = 1 +(rand()%100);
			players[i].strength = 1 +(rand()%100);
			players[i].skill = 1 +(rand()%100);
			players[i].dexterity = 1 +(rand()%100);
			players[i].dexterity = 1 +(rand()%100);
			sum = players[i].smartness + players[i].strength + players[i].skill + players[i].luck + players[i].dexterity;
			
			check = 0;
			while(check == 0)
			{
				if(players[i].dexterity + players[i].luck + players[i].skill + players[i].smartness + players[i].strength >=300)
				{
					players[i].smartness = rand()%100 + 1;
					players[i].strength = rand()%100 + 1;
					players[i].skill = rand()%100 + 1;
					players[i].dexterity = rand()%100 + 1;
					players[i].luck = rand()%100 + 1;
				}
				else{
					check = 1;
				}
			}
		}
	}
	
}

void pointsOgre(struct player players[])
{
	printf("\nworking\n");
	int smartness, strength, skill = 0, luck, dexterity;
	int i, sum;
	
	for(i=0; i<numplayers; i++)
	{
		if(players[i].player_type == "ogre")
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

void pointsElf(struct player players[])
{
	printf("\nworking\n");
	int smartness, strength, skill = 0, luck, dexterity;
	int i;
	
	for(i=0; i<numplayers; i++)
	{
		if(players[i].player_type == "elf")
		{
			players[i].luck = 60 +(rand()%40);
			players[i].smartness  = 70 +(rand()%30);
			players[i].strength = 1 +(rand()%50);
			players[i].skill = 50 +(rand()%30);
		}
	}
	
}

void pointsWizard(struct player players[])
{
	printf("\nworking\n");
	int smartness, strength, skill, luck, dexterity;
	int i;
	
	for(i=0; i<numplayers; i++)
	{
		if(players[i].player_type == "wizard")
		{
			players[i].luck = 50 +(rand()%50);
			players[i].smartness = 90 +(rand()%10);
			players[i].strength = 1 +(rand()%20);
			players[i].skill = 80 +(rand()%20);
		}
	}
		
}

void slotType(struct slot slots[])
{
	int i, j;
	
	for (i=0; i < numslots; i++)
	{
		j = 1 + rand() % 3; //j selects a random position between 1 and 3.
	
		if(j==1)
		{
			strcpy(slots[i].type, "Level Ground");
		}
	
		else if(j==2)
		{
			strcpy(slots[i].type, "Hill");
		}
	
		else
		{
			strcpy(slots[i].type, "City");
		}
	}
}	

void makeMove(struct player players[], struct slot slots[])
{	
	printf("\nMake move working\n");
	int move, invalid2, invalid3;
	int attackNumber, attackPlayer;
	int checked1[numplayers], checkArr[numplayers];
	int swap, num, num1;
	int gameEnd, i, j, d;
	
	for(gameEnd=0; gameEnd<numplayers; gameEnd++)
	{
		invalid2 = 0;
		while(invalid2 == 0)
		{
			// Give the option to move players to adjacent slots.
			printf("Player %d is in slot type : %s\n", gameEnd+1, slots[players[gameEnd].position]);
			
			if(players[gameEnd].position == 0)
			{
				printf("Next slot is of type %s (you are in the first slot)", slots[players[gameEnd].position + 1]);
				printf("Player %d: Enter 1 to move to the next slot, or 3 to attack the closest player.\n", gameEnd+1);
			}
			else if(players[gameEnd].position == 19)
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
				players[gameEnd].position = players[gameEnd].position - 1;
				
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
				
			else if(move == 3)
			{
				//Find the closest player(The player of the shortest distance in the array of slots).
				for(i=0; i<numplayers-1; i++)
				{
					if(players[gameEnd].position > players[i].position)
					{
						checkArr[i] = players[gameEnd].position - players[gameEnd].position;
					}
					else if(players[gameEnd].position < players[i].position)
					{
						checkArr[i] = players[gameEnd].position - players[gameEnd].position;	
					}
					else
					{
						checkArr[i] = 0;
					}
				}
			
				for(i=0; i<numplayers; i++)
				{
					checked1[i] = players[i].position;
				}
			
				for(i=0; i<numplayers-1; i++)
				{
					for(j=i+1; j<numplayers; j++)
					{
						if(checkArr[i] > checkArr[j])
						{
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
					for(d=0; d<numplayers; d++)
					{
						if(checked1[1] == players[d].position)
						{
							num = d;
						}
					}
					for(d=0; d<numplayers; d++)
					{
						if(checked1[1] == players[d].position)
						{
							num1 = d;
						}
					}
					if(checkArr[1] == checkArr[2]){
						printf("Would you like to attack %s (enter 1) or %s (enter 2) : ", players[checked1[num]].name, players[checked1[num1]].name);
						scanf("%d", &attackNumber);
						if(attackNumber == 1){
							attackPlayer = 1;
							printf("You have attacked %s.\n\n", players[checked1[num]].name);
							invalid3 = 1;
						}
						else if(attackNumber == 2){
							attackPlayer = 2;
							printf("You have attacked %s.\n\n", players[checked1[num1]].name);
							invalid3 = 1;
						}
						else{
							printf("Invalid\n\n");
						}
					}
					else{
						attackPlayer = 1;
						printf("You have attacked %s.\n\n", players[checked1[num]].name);
					}
				}
				
				for(d=0; d<numplayers; d++)
				{
					if(checked1[attackPlayer] == players[d].position)
					{
						num = d;
					}
				}
				
				if(players[num].strength <= 70)
				{
					players[num].life_pts -= players[num].strength*0.5;
				}
	
				else if(players[num].strength > 70)
				{
					players[num].life_pts -= players[num].strength*0.3;
				}
				
				invalid2 = 1;
			}
			else
			{
				printf("Invalid choice\n\n");
				i--;
			}
		}
	}
	printf("\n\n");
	for(i=0; i < numplayers; i++)
	{
		printf("%s \t %s \t %d\n", &players[i].name, &players[i].player_type, &players[i].life_pts);
	}
}	

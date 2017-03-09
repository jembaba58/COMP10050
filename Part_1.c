# include <stdio.h>
# include <stdlib.h>
//Function Prototypes
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
	int num;
}

int main()
{
	struct player players[5];// array of players
	struct slot slots[19]; // array of slots
	int direction;
	int i;
	int numPlayers, attkd;
	int min;
	int attkr;
	
	srand(time(NULL)); //Seeding the randomiser
	
	//Select the number of players to play the game.
	printf("Please select the number of players(Maximum 6): "); 
	scanf("%d", &numplayers);
	
	for(i=0; i<numPlayers; i++)
	{
		//For each playerNumber, we ask for the the type and name.
		printf("Please select the name and type for player %d:\n", &i);
		scanf("%s\n", &players[i].name, &players[i].player_type);
	}
	
	//Call the function to allocate the players to the 20 slots
	void allocatePlayers(players[])
	
	for(i=0; i<num_players; i++)
	{
		// Give the option to move players to adjacent slots.
		printf("Player %d is in slot type :%s", &i, &slots[players[i].position]);
		//Displaying the types of adjacent slots.
		printf("Adjacent slots are of type %s and %s", &slots[players[i].position -1], &slots[players[i].position +1]);
		
		//Give the option to move to the adjacent slot.
		printf("Please choose 1 to go forward or 2 to go backward, and 0 for no change");
		scanf("%d", &direction);
	}
	
		if(direction == 2)
		{
			players[i].position = players[i].position -1;
		}
	
			else if(direction == 1)
			{
				players[i].position = players[i].position +1;
			}
			
				if (direction != 0)
				{
					if(slots[players[i].position].type == "Hill")
					{
						if(players[i].dexterity < 50)
						{
							players[i].strength -=10;
						}
						
						else if(players[i].dexterity >= 60)
						{
							players[i].strength +=10;
						}
					}
					
					else if(slots[players[i].position].type == "City")
					{
						if(players[i].smartness > 60)
						{
							players[i].skill +=10;
						}
						
						else if(players[i].smartness <= 50)
						{
							players[i].dexterity -=10;
						}
					}
				}
							// Ask for the number of the attacker to be specified.
							printf("Which player will be the attacker: ");
							scanf("%d", &attkr);
							min = 19;
							
							//Find the closest player(The player of the shortest distance in the array of slots).
							for(i=0; i<numPlayers; i++)
							{
								//Check distance for each player in turn.
								if (min > abs(players[i].position - players[attkr].position))
								{
									min = abs(players[i].position - players[attkr].position);
									attkd = players[i].position; 
									
								}
								// Atacked player now identified
							}
							
							if(players[attkd].strength <= 70)
							{
								players[attkd].life_pts -= players[attkd].strength*0.5;
							}
							
							else if(players[attkd].strength > 70)
							{
								players[attkd].life_pts -= players[attkd].strength*0.3;
							}
							
					
}

void slotType(struct slot[])
{
	int i, j;
	
	for (i=0; i < 20; i++).
	{
        j = 1 + rand() % 3; //j selects a random position between 1 and 3.
	}
	
	if(j==1){
		slots.type[i] = "Level Ground";
	}
	
	if(j==2){
		slots.type[i] = "Hill";
	}
	
	if(j==3){
		slots.type[i] = "City";
	}
}

//If the player is a human, all his/her capabilities should be > 0
//Also, the total sum of the capabilities should be < 300.

void pointsHuman(struct players[])
{
	int smartness, strength, skill, luck, dexterity;
	int sum;
	int numPlayers;
	
	for(i=0; i<numPlayers; i++)
	{
		if(players[i].player_type ="Human")
		{
				do while(sum < 300)
					{
	
							players[i].smartness = 1 +(rand()%100);
						
							players[i].strength = 1 +(rand()%100);
						
							players[i].skill = 1 +(rand()%100);
						
							players[i].dexterity = 1 +(rand()%100);
						
							players[i].dexterity = 1 +(rand()%100);
							
							sum = players[i].smartness + players[i].strength + players[i].skill + players[i].luck + players[i].dexterity;
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
void allocatePlayers(struct players[])
{
	int chosen[19];
	int array[5]; //for 6 random numbers between 1 and 20 
    int i, j;
	
    for (i = 0; i < 20; i++){
		chosen[i] = 0; }      //initialise array of 20 integers, all = 0
     
    for (i = 0; i < 6; i++)
    {
        j = 1 + (rand () % 20);
        if (chosen[j] = 1)
            i--;          //already chosen so try again
        else
        {
            array[i] = j; // add the random number to the array. 
            chosen[j] = 1;  //Mark this element in the chosen array
                                
        }
     }
	 
	for(i=0; i < 6; i++)
	{
		players[i].position = array[i];
	}
}

void abs(int a)
{
	int x;
	
	if(a > 0)
	{
		x = a;
	}
	 
		else(x = -a)
		
	return x;
}



































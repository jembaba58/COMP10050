#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

int numplayers, numslots;
int checked[];

struct player
{
	char name[20];
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
                    printf("Please enter the name and player type (elf, human, ogre or wizard) for player %d (in lowercase letters) :\n", &i);
                    scanf("%s\n", &players[i].name, &players[i].player_type);
                    invalid=1;

                    if(players[i].player_type=="elf" || players[i].player_type=="human" || players[i].player_type=="ogre" || players[i].player_type=="wizard")
                    {
                        invalid1 = 1;
                    }
                    else
                    {
                        printf("Invalid player type.\n");
                    }
                }
            }
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
	int checked[numplayers];

	for(i=0; i<slotsNumber; i++)	

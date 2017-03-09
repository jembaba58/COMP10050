#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

int playerNumber, lifePoints=100;
char playerNames[6][15], playerTypes[6][10];

struct playerFields{
	char name[20];
	char type[20];
};

struct capabilities{
	int dexterity;
	int luck;
	int magicSkills;
	int smartness;
	int strength;
};



int main(void){
	
	time_t t;
	srand((unsigned) time(&t));
	
	struct capabilities elf;
	elf.dexterity = rand()%100 + 1;
	elf.luck = rand()%41 + 60;
	elf.magicSkills = rand()%31 + 50;
	elf.smartness = rand()%31 + 70;
	elf.strength = rand()%51 + 50;
	
	struct capabilities human;
	human.dexterity = rand()%100 + 1;
	human.luck = rand()%100 + 1;
	human.magicSkills = rand()%100 + 1;
	human.smartness = rand()%100 + 1;
	human.strength = rand()%100 + 1;
	int check = 1;
	while(check == 1){
		if(human.dexterity + human.luck + human.magicSkills + human.smartness + human.strength >=300){
			human.dexterity = rand()%100 + 1;
			human.luck = rand()%100 + 1;
			human.magicSkills = rand()%100 + 1;
			human.smartness = rand()%100 + 1;
			human.strength = rand()%100 + 1;
		}
		else{
			check = 0;
		}
	}

	struct capabilities ogre;
	ogre.dexterity = rand()%21 + 80;
	ogre.luck = rand()%50;
	ogre.magicSkills = 0;
	ogre.smartness = rand()%20;
	ogre.strength = rand()%21 + 80;
	check = 1;
	while(check == 1){
		if(ogre.luck + ogre.smartness > 50){
			ogre.luck = rand()%50;
			ogre.smartness = rand()%20;
		}
		else{
			check = 0;
		}
	}
	
	struct capabilities wizard;
	wizard.dexterity = rand()%100 + 1;
	wizard.luck = rand()%41 + 60;
	wizard.magicSkills = rand()%21 + 80;
	wizard.smartness = rand()%11 + 90;
	wizard.strength = rand()%20 + 1;
	

	printf("How many players would you like to enter? (must be <= 6)\n");
	scanf("%d", &playerNumber);
	
	struct playerFields players[playerNumber];
	
	int i, count=1, typeNumber;
	if(playerNumber>=0 && playerNumber<=6){
		for(i=0; i<playerNumber; i++){
			printf("For player number %d, enter 1, 2, 3 or 4 for player type elf, human, ogre or wizard respectfully\n", count);
			scanf("%d", &typeNumber);
			if(typeNumber == 1){
				players[i].type = "elf";
			}
			else if(typeNumber == 2){
				players[i].type = "human";
			}
			else if(typeNumber == 3){
				players[i].type = "ogre";
			}
			else if(typeNumber == 4){
				players[i].type = "wizard";
			}
			
			printf("Enter the name of player %d:\n", count);
			scanf("%s", &players[i].name);
			count++;
		}
	}
	else{
		printf("was not <= 6)\n");
	}
	
	printf("\n");
	for(int i=0; i<playerNumber; i++){
		printf("%s, %s\n", players[i].type, players[i].name);
	}
	
	
	
	
	
	
	
	int slotsNumber;
	printf("Please select a number of slots (max 20):\n");
	scanf("%d", &slotsNumber);
	
	int slotInt[slotsNumber], noRepeatShuffle[PlayerNumber];
	char slotsChar[slotsNumber][15], slotsPlayerPosition[slotsNumber][15];
	
	for(i=0; i<slotsNumber; i++){
		slotsInt[i] = rand()%3 + 1
	}
	
	for(i=0; i<slotsNumber; i++){
		if(slotsInt[i] == 1){
			slotsChar[i] = "Level Ground";
		}
		else if(slotsInt[i] == 2){
			slotsChar[i] = "Hill";
		}
		else{
			slotsChar[i] = "City";
		}
	}
	
	int k;
	for(i=0; i<slotsNumber; i++){
		k = rand()%(slotsNumber-1);
		noRepeatShuffle[i] = k;
		strcpy(slotsPlayerPosition[k], players[i].name);
	}
	
	int j;
	i=0;
	while(i<slotsNumber-1){
		j=i+1;
		while(j<slotsNumber){
			if(noRepeatShuffle[i] == noRepeatShuffle[j]){
				for(i=0; i<slotsNumber; i++){
					k = rand()%(slotsNumber-1);
					noRepeatShuffle[i] = k;
					strcpy(slotsPlayerPosition[k], players[i].name);
				}
				i=-1, j=slotsNumber;
			}
			else{
				j++;
			}
		}
		i++;
	}
	
	
	int p=0, q=1, counter = 0, nothing = 0, g=0;
	int checkArr[playerNumber];
	
	while(p<playerNumber){
		check = 0;
		while(p<q){
			for(j=p+1; j<playerNumber; j++){
				if(noRepeatShuffle[p] == noRepeatShuffle[j]+1 || noRepeatShuffle[p] == noRepeatShuffle[j]-1){
					check = 1;
				}
			}
		}
	
		int move;
		if(check == 1){
			printf("Player %d: Enter 1 to move to the next slot, 2 to move to the previous slot, 3 to attack the closest player, or 4 to do nothing.\n", check);
		}
		else{
			printf("Player %d: Enter 3 to attack the closest player, or 4 to do nothing.\n", check);	
		}
		scanf("%d", &move);
	
		if(move == 1){
			noRepeatShuffle[q] = noRepeatShuffle[q] + 1;
			slotsPlayerPosition[noRepeatShuffle[q]] = slotsPlayerPosition[noRepeatShuffle[q]] + 1;
		
			if(slotsChar[noRepeatShuffle[q]] == "Level Ground"){
			
			}
			else if(slotsChar[noRepeatShuffle[q]] == "Hill"){
			
			}
			else{
			
			}
		}
	
		else if(move == 2){
			noRepeatShuffle[q] = noRepeatShuffle[q] - 1;
			slotsPlayerPosition[noRepeatShuffle[q]] = slotsPlayerPosition[noRepeatShuffle[q]] - 1;
		
			if(slotsChar[noRepeatShuffle[q]] == "Level Ground"){
			
			}
			else if(slotsChar[noRepeatShuffle[q]] == "Hill"){
			
			}
			else{
			
			}
		}
	
		else if(move == 3){
			for(i=0; i<playerNumber-1; i++){
				if(noRepeatShuffle[counter] > noRepeatShuffle[i]){
					checkArr[i] = noRepeatShuffle[counter] - noRepeatShuffle[i];
				}
				else if(noRepeatShuffle[counter] < noRepeatShuffle[i]){
					checkArr[i] = noRepeatShuffle[i] - noRepeatShuffle[counter];	
				}
				else{
					checkArr[i] = 999;
				}
			}
			
			int noRepeatShuffle1[playerNumber];
			for(i=0; i<playerNumber; i++){
				noRepeatShuffle1[i] = noRepeatShuffle[i];
			}
			
			check = 0;
			int swap;
			for(i=0; i<playerNumber-1; i++){
				for(j=i+1; j<playerNumber; j++){
					if(checkArr[i] > checkArr[j]){
						swap = checkArr[i];
						checkArr[i] = checkArr[j];
						checkArr[j] = swap;
						swap = noRepeatShuffle1[i];
						noRepeatShuffle1[i] = noRepeatShuffle1[j];
						noRepeatShuffle1[j] = swap;
					}
				}
			}
			
			int attackNumber, attackPlayer;
			if(checkArr[0] == checkArr[1]){
				printf("Would you like to attack %s (enter 1) or %s (enter 2)", slotsPlayerPosition[noRepeatShuffle1[0]], slotsPlayerPosition[noRepeatShuffle[1]]);
				scanf("%d", &attackNumber);
				if(attackNumber == 1){
					attackPlayer = noRepeatShuffle1[0];
				}
				else if(attackNumber == 2){
					attackPlayer = noRepeatShuffle1[1];
				}
				else{
					printf("Invalid");
				}
			}
			else{
				printf("Attacking %s.", slotsPlayerPosition[noRepeatShuffle1[0]]);
			}
			
			
			
			
			
			
		}
	
		else{
			nothing++;
		}
		
		p++, q++, counter++; 
	}
	
	
	
	
	
	return 0;
}

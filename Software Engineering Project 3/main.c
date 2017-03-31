/*
 * main.c
 *
 *  Created on: 31 Mar 2017
 *      Author: vikin
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "crossfireOperations.h"

int main(void)
{
	int row, column, boardSize;

	struct slot *upLeft;
	struct slot *upRight;
	struct slot *downLeft;
	struct slot *downRight;

	boardSize = getBoardSize();

	createBoard(boardSize, &upLeft, &upRight, &downLeft, &downRight);

	getDesiredElement(boardSize, &row,&column);

	if(row >= boardSize/2){
		if(column >= boardSize/2){
			reachDesiredElement(row,column,downRight);
		}
		else{
			reachDesiredElement(row,column,downLeft);
		}
	}
	else{
		if(column >= boardSize/2){
			reachDesiredElement(row,column, upRight);
		}
		else{
			reachDesiredElement(row,column,upLeft);
		}
	}

	return 0;
}

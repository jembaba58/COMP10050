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

struct slot{
	int row;
	int column;
	struct slot *left;
	struct slot *right;
	struct slot *up;
	struct slot *down;
}slot;

int main(void)
{
	int row, column, boardSize;

	struct slot *upLeft;
	struct slot *upRight;
	struct slot *downLeft;
	struct slot *downRight;

	boardSize = getBoardSize();

	createBoard(boardSize, &upLeft, &upRight, &downLeft, &downRight);












	return 0;
}

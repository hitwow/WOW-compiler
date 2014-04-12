/*
 * main.c
 *
 *  Created on: 2014年3月26日
 *      Author: hitwow
 */
#include "lexer.h"
#include <stdio.h>

int main()
{
	char name[FNLEN];
	printf ("Welcome!\nPlease input the name of source code file!\n: ");
	scanf ("%s", name);

	lexer(name);
	/*
	int i;
	for (i=0; i<tokennum; i++)
		printf("%d, %d\n", optb[i].id, optb[i].num);
*/
	showas();

	return 0;
}


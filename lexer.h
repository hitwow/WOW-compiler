/*
 * lexer.h
 *
 *  Created on: 2014年3月26日
 *      Author: hitwow
 */

#ifndef LEXER_H_
#define LEXER_H_

#define FNLEN 10
#define KWLEN 20
#define SLEN 100
#define KWNUM 7

typedef struct
{
	int id;
	int num;
}token;

token optb[1000];
token wdtb[100];
char* strtb[200];
int tokennum;

void lexer(char*);
char get_ch();
void intokens(token);
void retract();
void inittb();
token gettoken(char*);
token getnum(char*);
token getstr(char*);
void showas();

#endif /* LEXER_H_ */

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
#define CLEN 4

void lexer(char*);
char get_ch();
void intokens(int, int);
void retract();

#endif /* LEXER_H_ */

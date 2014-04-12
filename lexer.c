/*
 * lexer.c
 *
 *  Created on: 2014年3月28日
 *      Author: hitwow
 */
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <malloc.h>
#include <string.h>

#include "lexer.h"
#include "kword.h"

FILE* fp;

int wdnum = 0;
int strnum = 0;

void lexer(char* name)
{
	char ch;
	char* word;
	char* tstr;
	char tch;
	int i;
	token tk;

	inittb();
	fp = fopen(name, "r+");

	while ((ch=get_ch())!=EOF)
	{
		if (ch==' '||ch=='\t'||ch=='\n'||ch=='\r')
			continue;
		else if (isalpha(ch))
		{
			word = (char*)malloc(KWLEN);
			i = 0;
			word[i++] = ch;
			ch = get_ch();
			while (isalnum(ch))
			{
				word[i++] = ch;
				ch = get_ch();
			}
			retract();
			word[i] = '\0';
			intokens(gettoken(word));
		}
		else if (isdigit(ch))
		{
			word = (char*)malloc(KWLEN);
			i = 0;
			word[i++] = ch;
			ch = get_ch();
			while (isdigit(ch))
			{
				word[i++] = ch;
				ch = get_ch();
			}
			retract();
			word[i] = '\0';
			intokens(getnum(word));
		}
		else
		{
			switch(ch)
			{
			case '#':
				tk.id = SHARP;
				tk.num = 0;
				intokens(tk);
				break;
			case '<':
				ch = get_ch();
				if (ch=='=')
				{
					tk.id = LE;
					tk.num = 0;
					intokens(tk);
				}
				else
				{
					retract();
					tk.id = LT;
					tk.num = 0;
					intokens(tk);
				}
				break;
			case '>':
				ch = get_ch();
				if (ch=='=')
				{
					tk.id = GE;
					tk.num = 0;
					intokens(tk);
				}
				else
				{
					retract();
					tk.id = GT;
					tk.num = 0;
					intokens(tk);
				}
				break;
			case '(':
				tk.id = LR_BRAC;
									tk.num = 0;
									intokens(tk);
				break;
			case ')':
				tk.id = RR_BRAC;
									tk.num = 0;
									intokens(tk);
				break;
			case '{':
				tk.id = LB_BRAC;
									tk.num = 0;
									intokens(tk);
				break;
			case '}':
				tk.id = RB_BRAC;
									tk.num = 0;
									intokens(tk);
				break;
			case ',':
				tk.id = COMMA;
									tk.num = 0;
									intokens(tk);
				break;
			case ';':
				tk.id = SEMIC;
									tk.num = 0;
									intokens(tk);
				break;
			case '=':
				ch = get_ch();
				if (ch=='=')
				{
					tk.id = DEQ;
										tk.num = 0;
										intokens(tk);
				}
				else
				{
					retract();
					tk.id = EQ;
										tk.num = 0;
										intokens(tk);
				}
				break;
			case '+':
				ch = get_ch();
				if (ch=='=')
				{
					tk.id = PE;
										tk.num = 0;
										intokens(tk);
				}
				else if (ch=='+')
				{
					tk.id = DPLUS;
										tk.num = 0;
										intokens(tk);
				}
				else
				{
					retract();
					tk.id = PLUS;
										tk.num = 0;
										intokens(tk);
				}
				break;
			case '-':
				ch = get_ch();
				if (ch=='=')
				{
					tk.id = MIE;
										tk.num = 0;
										intokens(tk);
				}
				else if (ch=='-')
				{
					tk.id = DMINUS;
										tk.num = 0;
										intokens(tk);
				}
				else
				{
					retract();
					tk.id = MINUS;
										tk.num = 0;
										intokens(tk);
				}
				break;
			case '*':
				ch = get_ch();
				if (ch=='=')
				{
					tk.id = MUE;
										tk.num = 0;
										intokens(tk);
				}
				else
				{
					retract();
					tk.id = MULTI;
										tk.num = 0;
										intokens(tk);
				}
				break;
			case '/':
				ch = get_ch();
				if (ch=='=')
				{
					tk.id = DE;
										tk.num = 0;
										intokens(tk);
				}
				else
				{
					retract();
					tk.id = RDIV;
										tk.num = 0;
										intokens(tk);
				}
				break;
			case '!':
				ch = get_ch();
				if (ch=='=')
				{
					tk.id = NE;
										tk.num = 0;
										intokens(tk);
				}
				else
					printf("Wrong letter \'!\'.\n");
				break;
			case '.':
				tk.id = POINT;
									tk.num = 0;
									intokens(tk);
				break;
			case '[':
				tk.id = LS_BRAC;
									tk.num = 0;
									intokens(tk);
				break;
			case ']':
				tk.id = RS_BRAC;
									tk.num = 0;
									intokens(tk);
				break;
			case '\'':
				tch = get_ch();
				ch = get_ch();
				if (ch!='\'')
				{
					printf("Wrong letter!\n");
					retract();
				}
				else
				{
					tk.id = CHR;
										tk.num = tch;
										intokens(tk);
				}
				break;
			case '\"':
				tstr = (char*)malloc(SLEN);
				i = 0;
				tstr[i++] = ch;
				ch = get_ch();
				while (ch!='\"')
				{
					tstr[i++] = ch;
					ch = get_ch();
				}
				tstr[i++] = ch;
				tstr[i] = '\0';
				intokens(getstr(tstr));
				break;
			default:
				printf("Wrong letter \'%c\'.\n", ch);
			}
		}
	}

	fclose(fp);
}

char get_ch()
{
	char ch;
	ch = getc(fp);

	return ch;
}


void inittb()
{
	int i;

	wdnum = KWNUM;
	tokennum = 0;

	wdtb[0].id = INCLUDE;
	wdtb[1].id = INT;
	wdtb[2].id = FOR;
	wdtb[3].id = WHILE;
	wdtb[4].id = IF;
	wdtb[5].id = ELSE;
	wdtb[6].id = RETURN;

	for (i=0; i<KWNUM; i++)
	{
		wdtb[i].num = 0;
	}

	for (i=0; i<200; i++)
		strtb[i] = NULL;
}

void intokens(token tk)
{
	optb[tokennum++] = tk;
}

void retract()
{
	fseek(fp, -1, 1);
}

token gettoken(char* word)
{
	token tk;
	int i = 0;

	if (!strcmp(word, "include"))
	{
		tk.id = INCLUDE;
		tk.num = 0;
	}
	else if (!strcmp(word, "int"))
	{
		tk.id = INT;
		tk.num = 0;
	}
	else if (!strcmp(word, "for"))
	{
		tk.id = FOR;
		tk.num = 0;
	}
	else if (!strcmp(word, "while"))
	{
		tk.id = WHILE;
		tk.num = 0;
	}
	else if (!strcmp(word, "if"))
	{
		tk.id = IF;
		tk.num = 0;
	}
	else if (!strcmp(word, "else"))
	{
		tk.id = ELSE;
		tk.num = 0;
	}
	else if (!strcmp(word, "return"))
	{
		tk.id = RETURN;
		tk.num = 0;
	}
	else
	{
		for (i=0; i<strnum; i++)
		{
			if (!strcmp(word, strtb[i]))
			{
				tk.id = ID;
				tk.num = i;
				break;
			}
		}

		if (i == strnum)
		{
			strtb[strnum++] = word;
			tk.id = ID;
			tk.num = i;
			wdtb[wdnum++] = tk;
		}
	}

	return tk;
}

token getnum(char* word)
{
	int num;
	token tk;

	num = atoi(word);
	tk.id = INT;
	tk.num = num;

	return tk;
}

token getstr(char* word)
{
	token tk;

	strtb[strnum] = word;
	tk.id = STR;
	tk.num = strnum;
	strnum++;

	return tk;
}

void showas()
{
	FILE* fp;
	int i;

	fp = fopen("optb.txt", "a");

	for (i=0; i<tokennum; i++)
	{
		fprintf(fp, "%d, %d\n", optb[i].id, optb[i].num);
	}

	fclose(fp);

	fp = fopen("wdtb.txt", "a");

	for (i=0; i<wdnum; i++)
	{
		fprintf(fp, "%d, %d\n", wdtb[i].id, wdtb[i].num);
	}

	fclose(fp);

	fp = fopen("str.txt", "a");

	for (i=0; i<strnum; i++)
	{
		fputs(strtb[i], fp);
		putc('\n', fp);
	}

	fclose(fp);
}

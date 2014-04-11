/*
 * lexer.c
 *
 *  Created on: 2014年3月28日
 *      Author: hitwow
 */
#include <stdio.h>
#include <ctype.h>

#include "lexer.h"
#include "kword.h"

FILE* fp;

void lexer(char* name)
{
	char ch;
	char word[KWLEN];
	char tstr[SLEN];
	char tch[CLEN];
	int i;

	fp = fopen(name, "r+");

	while ((ch=get_ch())!=EOF)
	{
		if (ch==' '||ch=='\t'||ch=='\n'||ch=='\r')
			continue;
		else if (isalpha(ch))
		{
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
			printf("%s\n", word);
		}
		else if (isdigit(ch))
		{
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
			printf("%s\n", word);
		}
		else
		{
			switch(ch)
			{
			case '#':
				intokens(SHARP, 0);
				break;
			case '<':
				ch = get_ch();
				if (ch=='=')
					intokens(LE, 0);
				else
				{
					retract();
					intokens(LT, 0);
				}
				break;
			case '>':
				ch = get_ch();
				if (ch=='=')
					intokens(GE, 0);
				else
				{
					retract();
					intokens(GT, 0);
				}
				break;
			case '(':
				intokens(LR_BRAC, 0);
				break;
			case ')':
				intokens(RR_BRAC, 0);
				break;
			case '{':
				intokens(LB_BRAC, 0);
				break;
			case '}':
				intokens(RB_BRAC, 0);
				break;
			case ',':
				intokens(COMMA, 0);
				break;
			case ';':
				intokens(SEMIC, 0);
				break;
			case '=':
				ch = get_ch();
				if (ch=='=')
					intokens(DEQ, 0);
				else
				{
					retract();
					intokens(EQ, 0);
				}
				break;
			case '+':
				ch = get_ch();
				if (ch=='=')
					intokens(PE, 0);
				else if (ch=='+')
					intokens(DPLUS, 0);
				else
				{
					retract();
					intokens(PLUS, 0);
				}
				break;
			case '-':
				ch = get_ch();
				if (ch=='=')
					intokens(MIE, 0);
				else if (ch=='-')
					intokens(DMINUS, 0);
				else
				{
					retract();
					intokens(MINUS, 0);
				}
				break;
			case '*':
				ch = get_ch();
				if (ch=='=')
					intokens(MUE, 0);
				else
				{
					retract();
					intokens(MULTI, 0);
				}
				break;
			case '/':
				ch = get_ch();
				if (ch=='=')
					intokens(DE, 0);
				else
				{
					retract();
					intokens(RDIV, 0);
				}
				break;
			case '!':
				ch = get_ch();
				if (ch=='=')
					intokens(NE, 0);
				else
					printf("Wrong letter \'!\'.\n");
				break;
			case '.':
				intokens(POINT, 0);
				break;
			case '[':
				intokens(LS_BRAC, 0);
				break;
			case ']':
				intokens(RS_BRAC, 0);
				break;
			case '\'':
				tch[0] = ch;
				tch[1] = get_ch();
				ch = get_ch();
				if (ch!='\'')
				{
					printf("Wrong letter!\n");
					retract();
				}
				else
				{
					tch[2] = ch;
					tch[3] = '\0';
					printf("%s\n", tch);
				}
				break;
			case '\"':
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
				printf("%s\n", tstr);
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

void intokens(int a, int b)
{
	printf("%d, %d\n", a, b);
}

void retract()
{
	fseek(fp, -1, 1);
}

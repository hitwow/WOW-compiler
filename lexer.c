/*
 * lexer.c
 *
 *  Created on: 2014年3月28日
 *      Author: hitwow
 */
#include <stdio.h>
#include <ctype.h>

#include "lexer.h"

void lexer(char* name)
{
	FILE* fp;
	char ch;

	fp = fopen(name, "r+");

	while ((ch=getc(fp))!=EOF)
	{

	}

	fclose(fp);
}





/*
void lexer(char* name)
{
	char ch;
	char* words;

	init_stable();
	init_buf(name);

	while (get_ch(&ch))
	{
		if (ch==' '||ch=='\t'||ch=='\n')
			continue;
		else if (isalpha(ch))
		{
			get_ch(&ch);
			while (isalnum(ch))
				get_ch(&ch);
			ep--;
			words = (char)malloc(ep-sp);
			gettoken(words);
			intokens(getcode(words), getid(words));
		}
		else if (isdigit(ch))
		{
			get_ch(&ch);
			while (isnum(ch))
				get_ch(&ch);
			ep--;
			words = (char)malloc(ep-sp);
			gettoken(words);
			intokens(INT, atoi(words));
		}
		else
		{
			switch(ch)
			{
			case '#':
				intokens(SHARP, 0);
				break;
			case '<':
				get_ch(&ch);
				if (ch=='=')
					intokens(LE, 0);
				else
				{
					ep--;
					intokens(LT, 0);
				}
				break;
			case '>':
				get_ch(&ch);
				if (ch=='=')
					intokens(GE, 0);
				else
				{
					ep--;
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
				get_ch(&ch);
				if (ch=='=')
					intokens(DEQ, 0);
				else
				{
					ep--;
					intokens(EQ, 0);
				}
				break;
			case '+':
				get_ch(&ch);
				if (ch=='=')
					intokens(PE, 0);
				else if (ch=='+')
					intokens(DPLUS, 0);
				else
				{
					ep--;
					intokens(PLUS, 0);
				}
				break;
			case '-':
				get_ch(&ch);
				if (ch=='=')
					intokens(MIE, 0);
				else if (ch=='+')
					intokens(DMINUS, 0);
				else
				{
					ep--;
					intokens(MINUS, 0);
				}
				break;
			case '*':
				get_ch(&ch);
				if (ch=='=')
					intokens(MUE, 0);
				else
				{
					ep--;
					intokens(MULTI, 0);
				}
				break;
			case '/':
				get_ch(&ch);
				if (ch=='=')
					intokens(DE, 0);
				else
				{
					ep--;
					intokens(RDIV, 0);
				}
				break;
			case '!':
				get_ch(&ch);
				if (ch=='=')
					intokens(NE, 0);
				else
					printf("Wrong letter \'!\'.\n");
				break;
			case '\"':
				intokens(D_MARK, 0);
				break;
			case '\'':
				intokens(Q_MARK, 0);
				break;
			default:
				printf("Wrong letter \'%c\'.\n");
			}
		}
		sp = ep;
		num++;
	}
}

int get_ch(char* ch)
{

}
*/

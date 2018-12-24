#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h> 
#include <stdlib.h> 
#include <windows.h> 
#define LETTER 1 
#define NOT_THE_LETTER 0 
#define MAXLEN 1000 
void main(void)
{
	HANDLE hStdout;
	FILE *fp;
	char line[MAXLEN];
	char word[MAXLEN];
	int i=0;
	int flag;
	int prev_flag;
	char *ptr;
	WORD foregroundColor0;
	WORD backgroundColor;
	WORD textAttribute;
	hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
	foregroundColor0 = FOREGROUND_INTENSITY | FOREGROUND_RED;
	backgroundColor = BACKGROUND_INTENSITY | BACKGROUND_GREEN;
	fp = fopen("input.txt", "rt");
	if (fp == NULL)
		return;
	while (!feof(fp))
	{
		ptr = fgets(line, MAXLEN, fp);
		if (ptr == NULL)
			break;
		prev_flag = flag = NOT_THE_LETTER;
		word[0] = '\0';
		while (*ptr != 0)
		{
			prev_flag = flag;
			SetConsoleTextAttribute(hStdout, foregroundColor0 | backgroundColor);
			if (*ptr == ' ' || *ptr == ',' || *ptr == '.' || *ptr == '\n' || *ptr == '(' || *ptr == ')' || *ptr == '!')
				flag = NOT_THE_LETTER;
			else
				flag = LETTER;
			if (flag != prev_flag)
			{
				word[i] = '\0';
				if (*ptr == '(')
				{
					textAttribute = foregroundColor0;
					SetConsoleTextAttribute(hStdout, textAttribute);
				}
				printf("%s", word);
				i = 0;
			}
			word[i++] = *ptr++;
		}
		if (i != 0)
		{
			word[i] = '\0';
			printf("%s", word);
		}
	}
	printf("\n");
	fclose(fp);
	system("pause");
}
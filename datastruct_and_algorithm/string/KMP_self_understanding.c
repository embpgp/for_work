/*
 *C style KMP algorithm
 *
 *author : rutk1t0r
 *
 *date:2016.8.9
 *
 *
 *GPL
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void GetNextArray(char *t, int next[]);
int KMP_StrIndex(char *s, char *t, int *next);

int main(int argc, char* argv[])
{
	int next[40] = {0};
	if(argc != 3 || (strlen(argv[2]) > 40))
	{
		puts("error,,,,,,,,please input again~_~");
		return -1;
	}
	printf("The %s in %s index is %d\n",\
			argv[2],\
			argv[1],\
			KMP_StrIndex(argv[1], argv[2], next));
	return 0;
}


void GetNextArray(char *t, int next[])
{
	int i = 1;
	int j = 0;
	next[0] = 0;   //define ,Actually,make the array value forward move a position
	while(t[i])
	{
		if(j == 0 || t[i] == t[j])
		{
			++i;
			++j;
			next[i] = j;
		}
		else
		{
			j = next[j];
		}
	}
}


int KMP_StrIndex(char *s, char *t, int *next)
{
	int i = 0;
	int j = 0;
	while(s[i] && t[j])
	{
		if(j == 0 || s[i] == t[j])
		{
			++i;
			++j;
		}
		else
		{
			j = next[j];
		}
	}
	if(t[j] == '\0')
	{
		return i - j;
	}
	else
	{
		return -1;
	}	
}

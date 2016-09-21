/*
 *a simple mode to match a string to return a index
 *
 *author : rutk1t0r
 *
 *2016.8.8
 *
 *GPL
 */



#include<stdio.h>
#include<stdlib.h>


int BF_strIndex(char *s, char *t)
{
	int i = 0, j = 0;
	while(s[i] != '\0' && t[j] != '\0')
	{
		if(s[i] == t[j])
		{
			++i;
			++j;
		}
		else
		{
			i = i - j + 1;  //go back the next position
			j = 0;
		}
	}
	if(t[j] == '\0')
	{
		return i-j;
	}
	else
	{
		return -1;
	}
}
int main(int argc, char *argv[])
{
	if(argc != 3)
	{
		printf("Please input as %s main_string sub_string\n",argv[0]);
		return -1;
	}
	printf("Index:%d\n", BF_strIndex(argv[1], argv[2]));
	return 0;
}

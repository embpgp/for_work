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
			i = i - j + 1;
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

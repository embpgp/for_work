/*
 *Filename:delete_char_from_string.c.c
 *
 *Description:delete all char in a  string from other string
 *
 *Author:rutk1t0r
 *
 *Date: 2016.10.13
 *
 *GPL
 *
 */

#include <stdio.h>
#include <string.h>
#include <malloc.h>
#include <stdlib.h>

char *DeleteCharFromString(const char *str, const char *remove)
{
	int i = 0, j = 0;
	char count[256] = {0};
	char *p = NULL,*ret = NULL;
	if(str == NULL || remove == NULL)
	{
		return NULL;
	}
	while(str[i] != '\0')
	{
		count[str[i]]++;
		i++;
	}
	while(remove[j] != '\0')
	{
		count[remove[j]] = 0;
		j++;
	}
	p = (char*)malloc(i);
	ret = p;
	i = 0;
	while(str[i] != '\0')
	{
		if(count[str[i]] != 0)
		{
			*p++ = str[i];
		}
		++i;
	}
	return ret;

}

int main(int argc, char const *argv[])
{
	/* code */
	if(argc != 3)
	{
		printf("please input like %s string removestring\n", argv[0]);
		return -1;
	}
	char *p = DeleteCharFromString(argv[1], argv[2]);
	printf("Before : %s\n", argv[1]);
	printf("After : %s\n", p);
	free(p);
	return 0;
}
/*
 *Filename:space_2_%20.c
 *
 *Description:replace the space char to "%20"  in a string
 *
 *Author:rutk1t0r
 *
 *Date:2016.10.05
 *
 *GPL
 */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
//the string must have the extra space,the arg length is total length for string pointer
//rather than the length of string pointer 
void ReplaceBlank(char *string, int length)
{
	assert(string != NULL && length > 0);
	int count = 0;   //the blank count
	int len = 0;    //the string length
	int newlen;
	while(string[len] != '\0')
	{
		if(string[len] == ' ')
		{
			++count;
		}
		++len;
	}
	newlen = len + 2*count;  //total length
	if(newlen > length || count == 0)
	{
		return;
	}
	newlen--; //not pointer the \0
	len--;   //pointer the effective char
	while(len > 0 && newlen > len) //while newlen == len it's not other blank 
	{
		if(string[len] == ' ')
		{
			string[newlen--] = '0';
			string[newlen--] = '2';
			string[newlen--] = '%';
		}
		else
		{
			string[newlen--] = string[len];
		}
		len--;  //every scan must pre move

	}

}

int main(int argc, char const *argv[])
{
	char string[1024] = "I am a student in the csust ";
	printf("original:%s\n", string);
	ReplaceBlank(string, sizeof(string));
	printf("new:%s\n", string);
	return 0;
}

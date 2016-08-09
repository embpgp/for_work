/*
 *KMP algorithm
 *
 *make the s string not go back 
 *
 *make the t string go on match the s[i]
 *
 *"T1T2...Tk-1" = "Si-k+1 Si-k+2 ... Si-1"
 *
 *when faild the match,we suppose it's on Si and Tj
 *
 *so we can know T1T2...Tj-1 = Si-j+1 Si-j+2 .. Si-1
 *
 *because k<j,so "Tj-k+1 Tj-k+2 ...Tj-1"="Si-k+1 Si-k+2 .. Si-1"
 *
 *
 *so "T1T2..Tk-1" = "Tj-k+1 Tj-k+2 .. Tj-1" make the Equation hold
 *
 *we can calc the k value for every T string and it's not connected for S string
 */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int KMP_strIndex(char *s, char *t,int *next, int pos)
{
	/*begin the pos char to find match t from s,default pos = 1*/
	int i = pos,j=1,slen,tlen;//the len is in [0]
	while(i<=s[0] && j<=t[0])
	{
		if(j == 0 || s[i] == t[j])
		{
			i++;
			j++;
		}
		else
		{
			j = next[j];   //go back the array value
		}
	}
	if(j>t[0])
	{
		return i - t[0];
	}
	else
	{
		return -1;
	}
}

void Getnext(char *t, int next[])
{
	int i = 1,j = 0;
	next[1] = 0;    //define
	while(i<t[0])
	{
		if(j==0||t[i] == t[j])
		{
			++i;
			++j;
			next[i] = j;
		}
		else
		{
			j = next[j];   //go back until j=0,then the t[i] = j+1 = 1
		}
	}
}
int main(int argc, char *argv[])
{
	int next[40] = {0};
	char s[256] = {0};
	char t[40] = {0};
	if(argc != 3)
	{
		puts("error,please input again!");
		return -1;
	}
	
	if(strlen(argv[2]) > 40 || strlen(argv[1]) > 256)
	{
		puts("the  string is too long!!!");  //protect the buffer overflow
		return -2;
	}
	//make the C style to the Delphi style
	//the len is on string[0]
	strcpy(&s[1], argv[1]);
	s[0] = strlen(argv[1]);
	strcpy(&t[1], argv[2]);
	t[0] = strlen(argv[2]);
	printf("s:%s len :%d t:%s len:%d\n", &s[1], s[0], &t[1], t[0]);
	Getnext(t, next);
	printf("the %s in %s index is %d\n",\
		argv[2],\
		argv[1],\
		KMP_strIndex(s, t, next, 1));
	return 0;
}
#include <stdio.h>



bool PatternMatch(char *pat, char *str)
{
	char *s = NULL;
	char *p = NULL;
	bool star = false;
	bool bBreak = false;

	do
	{
		bBreak = false;
		for(s = str, p = pat; *s; ++s, ++p)
		{
			switch(*p)
			{
				case '?':
					break;
				case '*':
					star = true;
					str = s;
					pat = p;
					if(!*++pat)
						return true;
					bBreak = true;
					break;
				default:
					if(*p != *s)
					{
						if(!star)
							return false;
						str++;
						bBreak = true;
					}
					break;
			}
			if(bBreak)
				break;
		}
		if(bBreak == false)
		{
			if(*p == '*')
				++p;
			return (!*p);
		}
	}while(1);
}


int main(int argc, char **argv)
{
	if (argc != 3){
		printf("Please input like %s pattern string,eg:%s a?cd*ef abcdef\n", argv[0], argv[0]);
		return (0);
	}
	printf("%s pattern %s %s\n", argv[1], argv[2], PatternMatch(argv[1], argv[2])? "true":"false");

	
	return 0;
}

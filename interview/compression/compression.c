/*
 *Filename:compression.c
 *
 *Description:read a file and compression it,like input a "aaabbbacc" and output
 *            like "3a3ba2c"
 *
 *Author:rutk1t0r
 *
 *Date:2016.10.02
 *
 *GPL
 */

#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <errno.h>
#include <stdlib.h>
#include <unistd.h>


#define buf_size 1024

void CompressionString(const char *str, long strlen, char *output, long outputlen)
{
	long i,count = 1;
	char size[16] = {0}; //用来将整数转化为字符串并追加的缓冲
	char c1 = str[0];
	memset(output, 0, outputlen);   
	for(i = 1; i<strlen; ++i)
	{
		char c2 = str[i];
		if(c1 == c2)	
		{
			count++;
			continue;
		}
		sprintf(size, "%lu", count);  //数字转字符
		strcat(output, size);
		strncat(output, (char*)&c1, 1);  //强转追加字符,懒得自己实现了,所以事先
		c1 = c2;                        //必须保证output为字符串,否则会出错
		count = 1;
	}
	sprintf(size, "%lu", count);    //必须统计最后一个字符串
        strcat(output, size);
        strncat(output, (char*)&c1, 1);
}

void compression(const char *path)
{
	int fd, n, i, count = 0;
	char buf[buf_size] = {0};
	char history;
	fd = open(path, O_RDONLY);
	if(fd < 0)
	{
		perror("error for open");
		exit(-1);	
	}
	while( (n = read(fd, buf, buf_size)) > 0)
	{
		i = 0; 
		while(i < n)
		{
			
		}			
	}	
}
int main(int argc, char *argv[])
{
	//const char *str = "aaabbdbaccc";
	const char *str = argv[1];
	char output[100] = {0};
	CompressionString(str, strlen(str), output, sizeof(output));
	printf("压缩之前字符串:%s\n压缩之后字符串:%s\n", str, output);
	return 0;
}

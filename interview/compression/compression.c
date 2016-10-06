/*
 *Filename:compression.c
 *
 *Description: 1,read a file and compression it,the input like "aaabbbacc" and the output like "3a3ba2c"
 *             2,read a string and decompression it, the input like "3a3ba2c" and the file content is aaabbbacc
 *
 *Author:rutk1t0r
 *
 *Date:2016.10.02
 *
 *GPL
 *
 *Method: g++ -o compression compression.c
 *  	  
 *        
 */

#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <errno.h>
#include <unistd.h>
#include <assert.h>
#include <malloc.h>
#include <stdlib.h>

#define buf_size 1024
//copy Linux内核源码关于printf实现部分的函数并作为自己用
static inline int isdigit(int ch)
{
	return (ch >= '0') && (ch <= '9');
}

//这个函数的主要目的在printf里面获取宽度,即类似于 `1024d` 的话就可以使得1024返回并使得指针*s指向d,很方便
static int myatoi(char **s)
{
	int i = 0;
	if(!isdigit(**s))    //此处是我自己根据自身情况修改的
	{
		return 1;
	}
	while (isdigit(**s))
		i = i * 10 + *((*s)++) - '0';
	return i;
}

//压缩字符串
void CompressionString(const char *StrSrc, long StrLen, char *Output, long OutputLen)
{
	assert(StrSrc != NULL && StrLen != 0 && 
	      Output != NULL && OutputLen != 0);
	long i,count = 1;
	char size[32] = {0}; //用来将整数转化为字符串并追加的缓冲
	char c1 = StrSrc[0];
	memset(Output, 0, OutputLen);   //为了保险起见还是应该继续填充为空
	for(i = 1; i < StrLen; ++i)
	{
		char c2 = StrSrc[i];
		if(c1 == c2)	//相同的话,继续匹配	
		{
			count++;
			continue;
		}
		if(count > 1)    //只有一个的话可以省略了,考虑一下最差的情况,也就是每次
		{                //都有变化,但是我们不能凭空还去增加一个1吧,浪费空间
			sprintf(size, "%lu", count);  //数字转字符,也是懒得自己写了
			strcat(Output, size);
		}
		strncat(Output, (char*)&c1, 1);  //强转追加字符,懒得自己实现了,所以事先
		c1 = c2;                        //必须保证output为字符串,否则会出错
		count = 1;
	}
	//最后一个字符并没有加进去,所以这里得加进去
	if(count > 1)    //只有一个的话可以省略了
	{
		sprintf(size, "%lu", count);  //数字转字符,也是懒得自己写了
		strcat(Output, size);
	}
	strncat(Output, (char*)&c1, 1);  
}

//压缩文件,基本思想类似于上面的函数
void CompressionFile(const char *path, char *output, long outputlen)
{
	assert(path != NULL && output != NULL && outputlen != 0);
	int fd, n;
	long count1,count2;  //轮流增加
	char buf[buf_size] = {0}; //辅助读取文件的缓冲
	char temp_output[buf_size] = {0};  //暂时格式化的缓冲
	char size[32] = {0};               //保存大小的缓冲
	char *p, c1, c2;
	char *switch_output = (char*)malloc(outputlen);
	if(switch_output == NULL)
	{
		perror("error for malloc");
		return;
	}
	memset(output, 0, outputlen);
	memset(switch_output, 0, outputlen);
	fd = open(path, O_RDONLY);     //只读的方式打开文件
	if(fd < 0)
	{
		perror("error for open");
		exit(-1);	
	}
	while((n = read(fd, buf, buf_size)) > 0) //一直读到末尾为止
	{
		memset(size, 0, 32);
		CompressionString(buf, n, temp_output, buf_size); //压缩并通过参数返回
		strcat(output, temp_output);             //直接挂在后面,下面的代码继续解析
	}
	if(n == -1)
	{
		perror("read error");
		exit(-1);
	}
	close(fd);          //close the fd

	//printf("%s\n", output);   //合并之前
	p = output;
	count1 = myatoi(&p);   //获得个数并使得指针后移指向字符
	c1 = *p++;          //获得字符并指向下一个字符的个数的地址
	while(*p)           //开始遍历
	{
		memset(size, 0, 32);
		count2 = myatoi(&p);
		c2 = *p++;                 //上述
		if(c1 == c2)
		{
			count1 += count2;   //开始增加
			continue;
		}
		if(count1 > 1)
		{
			sprintf(size, "%lu", count1);  //数字转字符,也是懒得自己写了
			strcat(switch_output, size);
		}
		strncat(switch_output, (char*)&c1, 1);  //强转追加字符,懒得自己实现了,所以事先
		c1 = c2;                        //必须保证output为字符串,否则会出错
		count1 = count2;    
	}

	if(count1 > 1)    //只有一个的话可以省略了
	{
		sprintf(size, "%lu", count1);  //数字转字符,也是懒得自己写了
		strcat(switch_output, size);
	}
	strncat(switch_output, (char*)&c1, 1);
	strcpy(output, switch_output);      //使得辅助的空间要返回,辅助空间需要被释放
	free(switch_output);               //不要忘记释放辅助空间
		
}

//解压代码
void decompression(const char *path, char *input)
{
	assert(path != NULL && input != NULL);
	char *p = input;
	char c;
	ssize_t n;
	size_t count, i = 0;
	int fd;
	fd = open(path, O_WRONLY | O_CREAT | O_TRUNC, 0644);  //新建立一个文件
	if(fd < -1)
	{
		perror("open error");
		exit(-1);
	}
	while(*p)
	{
		count = myatoi(&p);
		c = *p++;
		while(i<count && (n = write(fd, (char*)&c, 1)) > 0) //一直写入,效率低,多次IO操作,在这里为了简单就用系统调用了
		{						   //可以使用带缓存的IO,例如fopen,fwrite等,在这里库函数是对系统调用的封装
			++i;
		}
		if(n == -1)
		{
			perror("write error");
			close(fd);
			exit(-1);
		}
		i = 0;
	}
	close(fd);
}

void Usage(void)
{
	puts("Usage: compression [cd] [string] [file]");
	puts("-c 压缩串,读出一个文件中的串并进行压缩,测试参考方法:在Linux终端下键入 echo -n `python -c \"print 'Abd'+'B'*20480+'c'*1000\"` > file.txt  然后输入 ./compression -c file.txt ");
	puts("-d 解压串,读出用户输入的一个串进行解压到文件保存,测试参考方法:在Linux终端下键入 ./compression -d 3a3ba2c decomression.txt");
}
int main(int argc, char *argv[])
{
	if(argc != 3 && argc != 4)
	{
		Usage();
		return 1;
	}
	if(strcmp(argv[1], "-c") == 0)
	{
		char *path = argv[2];
		char output[4096] = {0};
		CompressionFile(path, output, sizeof(output));
		printf("压缩之后字符串:%s\n", output);
		return 0;
	}
	else if(strcmp(argv[1], "-d") == 0 && argc >= 4)
	{
		char *str = argv[2];
		char *filename = argv[3];
		decompression(argv[3], argv[2]);
		return 0;
	}
	else
	{
		Usage();
	}
	return 1;
}

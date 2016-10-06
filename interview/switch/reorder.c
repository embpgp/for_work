/*
 *Filename: reorder.c
 *
 *Description:split tow part of a array by a condition(function pointer)
 *
 *Author:rutk1t0r
 *
 *Date:2016.10.07
 *
 *GPL
 *
 */
#include <stdio.h>
#include <stdlib.h>


/*提炼出函数指针提高通用性*/
void reorder(int *pData, unsigned int length, bool (*func)(int))
{
	if(pData == NULL || length == 0 || func == NULL)
	{
		return ;
	}
	int *pBegin = pData;/*首尾同时扫描*/
	int *pEnd = pData + length - 1;
	while(pBegin < pEnd)
	{
		while(pBegin < pEnd && !func(*pBegin))//找偶数，如果是奇数则继续后移
		{
			pBegin++;
		}
		while(pBegin < pEnd && func(*pEnd))//找奇数，如果是偶数则继续前移
		{
			pEnd--;
		}
		if(pBegin < pEnd)//交换
		{
			int temp = *pBegin;
			*pBegin = *pEnd;
			*pEnd = temp;
		}
	}
}

//判断是否为偶数，此处测试为把基数都放到前面，偶数都放到后面去
bool isEven(int n)
{
	return (n & 1) == 0;
}

int main(int argc, char const *argv[])
{
	int a[] = {3,6,7,8,2,0,5,2,5,7};
	int i;
	printf("调整之前的数组:\n");
	for(i = 0; i<sizeof(a)/sizeof(int); ++i)
	{
		printf("%4d",  a[i]);
	}
	reorder(a, sizeof(a)/sizeof(int), isEven);
	printf("\n调整之后的数组:\n");
	for(i = 0; i<sizeof(a)/sizeof(int); ++i)
	{
		printf("%4d", a[i]);
	}
	puts("");
	return 0;
}

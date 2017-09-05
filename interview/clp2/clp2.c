/*
 *Filename : clp2.c
 *
 *Description: 求大于等于n以及最靠近n的2的幂
 *
 *Author: rutkt0r
 *
 *Date: 2017.9.5
 *
 *GPL
 *
 *gcc -o clp2 clp2.c -lm
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>


#define FALSE (0)
#define TRUE (!FALSE)


//是否是2的幂
int is_2_power(unsigned int n)
{
    int count = 0;
    while(n > 0)
    {
        if((n & 0x1) == 1)
        {
            ++count;
        }
        n >>= 1;
    }
    if(count == 1 || count == 0)
    {
        return TRUE;  //true
    }
    else
    {
        return FALSE; //false
    }
}

//求二进制前导0的个数，其中ARM指令有实现
int num_pre0(unsigned int n)
{
    int count = 0;
    while((n & 1<<(sizeof(unsigned int)*8 -1)) == 0)
    {
        ++count;
        n <<= 1;
    }
    return count;
}

unsigned int clp2(unsigned int n)
{
    int count = 0;
    if(is_2_power(n))
    {
        return n;
    }
    int num_zero = num_pre0(n);
    return 1 << (sizeof(unsigned int)*8 - num_zero);
}

int main(int argc, char *argv[])
{
	if(argc != 2)
	{
			printf("Usage:\n");
			printf("please input like %s num, example %s 3\n", argv[0], argv[0]);
			return -1;
	}
    printf("the num %d clp2 result is %d\n", atoi(argv[1]), clp2(atoi(argv[1])));
    return 0;
}
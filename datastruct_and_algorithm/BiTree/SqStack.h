/*
 *file:SqStack.h
 *
 *Author:rutk1t0r
 *
 *Date:2016.8.11
 *
 *GPL
 */

#ifndef __SQSTACK__H
#define __SQSTACK__H

#define MaxSize 100
#include "BT.h"
typedef struct 
{
	BiTree Elem[MaxSize];
	int top;
	/* data */
}SqStack,*pSqStack;



#endif
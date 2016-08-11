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

//0
void
StackInit(SqStack *s);
//1
void 
push(SqStack *s, BTNode *p);

//2
BTNode*
pop(SqStack *s);

//3
int 
StackEmpty(SqStack *p);
#endif
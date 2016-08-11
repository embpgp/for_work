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

//for post order unrecursion
typedef struct 
{
	BTNode *ptr;
	int flag;   //diff the times for visit
}stacknode;

typedef struct
{
	stacknode Elem[MaxSize];
	int top;
}SqStack_Post,*pSqStack_Post;

//0
void
StackInit(SqStack *s);
void 
StackInit_Post(SqStack_Post *s);
//1
void 
push(SqStack *s, BTNode *p);

void 
push_post(SqStack_Post *s, stacknode p);

//2
BTNode*
pop(SqStack *s);

stacknode
pop_post(SqStack_Post *s);

//3
int 
StackEmpty(SqStack *s);

int
StackEmpty_Post(SqStack_Post *s);
#endif
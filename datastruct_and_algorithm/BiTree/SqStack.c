/*
 *File:SqStack.c
 *
 *Author:rutk1t0r
 *
 *Date:2016.8.11
 *
 *GPL
 *
 */


#include "SqStack.h"

void 
StackInit(SqStack *s)
{
	s->top = 0;
}
int
StackEmpty(SqStack *s)
{
	if(s->top <= 0)
	{
		puts("error,Empty Stack");
		return 0;
	}
	return !0;
}
void 
push(SqStack *s, BTNode *p)
{
	if(s->top + 1 <= MaxSize)
	{
		s->Elem[s->top ++] = p;
	}
	else
	{
		puts("too many elements,please pop some ...");
	}
}

BTNode*
pop(SqStack *s)
{
	if(StackEmpty(s))
	{
		return s->Elem[--s->top];

	}
	else
	{
		puts("empty ....,please push first");
		return NULL;
	}
}
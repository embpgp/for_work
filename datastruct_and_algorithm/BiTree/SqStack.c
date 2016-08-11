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

void
StackInit_Post(SqStack_Post *s)
{
	s->top = 0;
}

int
StackEmpty(SqStack *s)
{
	if(s->top <= 0)
	{
		//puts("error,Empty Stack");
		return !0;       //true
	}
	return 0;              //false
}

int
StackEmpty_Post(SqStack_Post *s)
{
	if(s->top <= 0)
	{
		//puts("error,Empty Stack");
		return !0;       //true
	}
	return 0;              //false
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

void
push_post(SqStack_Post *s, stacknode p)
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
	if(!StackEmpty(s))
	{
		return s->Elem[--s->top];

	}
	else
	{
		puts("empty ....,please push first");
		return NULL;
	}
}

stacknode
pop_post(SqStack_Post *s)
{
	if(!StackEmpty_Post(s))
	{
		return s->Elem[--s->top];
	}
	else
	{
		puts("empty ....,please push first");
		return *(stacknode*)(0);
	}
}
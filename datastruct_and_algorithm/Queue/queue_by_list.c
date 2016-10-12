/*
 *Filename:queue_by_list.c
 *
 *Description:implement the queue interface by list
 *
 *Author:rutk1t0r
 *
 *Date:2016.10.12
 *
 *GPL
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>

typedef char datatype ;

typedef struct Node
{
	/* data */
	datatype data;
	struct Node *next;
}Node,*pNode;


typedef struct LiQueue
{
	Node *front;
	Node *rear;
}LiQueue,*pLiQueue;


void InitQueue(LiQueue **q)
{
	*q = (LiQueue*)malloc(sizeof(LiQueue));
	(*q)->front = (*q)->front = NULL;
}

int IsEmptyQueue(LiQueue *q)
{
	return q->rear == NULL ? 1:0;
}

void ClearQueue(LiQueue *q)
{
	Node *p = q->front,*r;
	if(p != NULL)
	{
		r = p->next;
		while(r != NULL)
		{
			free(p);
			p = r;
			r = r->next;
		}
	}
	free(q);
}

int EnQueue(LiQueue *q, datatype e)
{
	Node *s = NULL;
	s = (Node*)malloc(sizeof(Node));
	if(s == NULL)
	{
		return 0;
	}
	s->data = e;
	s->next = NULL;
	if(q->rear == NULL)  //the first node
	{
		q->rear = q->front = s;

	}
	else
	{
		q->rear->next = s;
		q->rear = s;
	}
	return 1;
}

int OutQueue(LiQueue *q, datatype * e)
{
	Node *t = NULL;
	if(q->rear == NULL)  //no node
	{
		return -1;
	}
	else if(q->front == q->rear)    //have a node
	{
		t = q->front;
		q->rear = q->front = NULL;
	}
	else                        //many node
	{
		t = q->front;
		q->front = t->next;

	}
	*e = t->data;
	free(t);
	return 1;
}

int main(int argc, char const *argv[])
{
	LiQueue *q;
	char e;
	InitQueue(&q);
	EnQueue(q, 'a');
	EnQueue(q, 'b');
	EnQueue(q, 'c');
	OutQueue(q, &e);
	printf("%c\n", e);
	OutQueue(q, &e);
	printf("%c\n", e);
	OutQueue(q, &e);
	printf("%c\n", e);
	return 0;
}
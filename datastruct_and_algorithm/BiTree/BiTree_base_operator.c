/*
 *BiTree base operator for difine.create.insert.delete.Order
 *
 *
 *author:rukt1t0r
 *
 *
 *date:2016.8.10
 *
 *
 *GPL
 *
 */

#include "BT.h"
#include "SqStack.h"    
/*1*/
BiTree 
Create(datatype root, pBTNode lbt, pBTNode rbt)
{
	/*create a BiTree for root and insert the lchild and rchild*/
	BiTree p = (BiTree)malloc(sizeof(BTNode));
	if(p == NULL)
	{
		return NULL;
	}
	p->data = root;
	p->lchild = lbt;
	p->rchild = rbt;
	return p;
}

/*2*/
BiTree
InsertLeftForParent(BiTree bt, datatype e, BiTree parent)
{
	BiTree p;
	if(parent == NULL)
	{
		printf("\nInsert error");
		return NULL;
	}
	if((p = (BTNode*)malloc(sizeof(BTNode))) == NULL)
	{
		return NULL;
	}

	p->data = e;
	p->lchild = NULL;
	p->rchild = NULL;
	if(parent->lchild == NULL)  //if the parent's lchild is null,directly set
	{
		parent->lchild = p;
	}
	else
	{
		p->lchild = parent->lchild; // otherwise make the parent's lchild as the p's lchild
		parent->lchild = p;         // then set p as the parent's lchild
	}
	return bt;
}

/*3*/
BiTree
InsertRightForParent(BiTree bt, datatype e, BiTree parent)
{
	BiTree p;
	if(parent == NULL)
	{
		printf("\nInsert error");
		return NULL;
	}
	if((p = (BTNode*)malloc(sizeof(BTNode))) == NULL)
	{
		return NULL;
	}

	p->data = e;
	p->lchild = NULL;
	p->rchild = NULL;
	if(parent->rchild == NULL)    //it's the same as Above-mentioned
	{
		parent->rchild = p;
	}
	else
	{
		p->rchild = parent->rchild;
		parent->rchild = p;
	}
	return bt;
}

/*4*/
BiTree 
DeleteLelf(BiTree bt, BiTree parent)
{
	BiTree p;
	if(parent == NULL || parent->lchild == NULL)
	{
		printf("delete error\n");
		return NULL;
	}
	p = parent->lchild;
	parent->lchild = NULL;

	DeleteRecursionSubtree(&p);  //for free
	return bt; 
}

/*5*/
BiTree 
DeleteRight(BiTree bt, BiTree parent)
{
	BiTree p;
	if(parent == NULL || parent->rchild == NULL)
	{
		printf("delete error\n");
		return NULL;
	}
	p = parent->rchild;
	parent->rchild = NULL;

	DeleteRecursionSubtree(&p);  //for free 
	return bt; 
}



/*Recursion delete*/
int 
DeleteRecursionSubtree(BiTree *p)
{
	if(*p == NULL)
	{
		return 0;		
	}	
	DeleteRecursionSubtree(&((*p)->lchild));
	DeleteRecursionSubtree(&((*p)->rchild));
	free(*p);
	*p = NULL;  //make the parent's child set null
	
	return !0;
}


/*Recursion algorithm*/
void
PreOrder(BiTree bt)
{
	if(NULL == bt)
	{
		return ;
	}
	//bt->data = bt->data;  //visit
	printf("%8d", bt->data);
	PreOrder(bt->lchild);
	PreOrder(bt->rchild);
}
void
InOrder(BiTree bt)
{
	if(NULL == bt)
	{
		return;
	}
	InOrder(bt->lchild);
	printf("%8d", bt->data); // visit3
	InOrder(bt->rchild);
}

void
PostOrder(BiTree bt)
{
	if(NULL == bt)
	{
		return;
	}
	PostOrder(bt->lchild);
	PostOrder(bt->rchild);
	printf("%8d", bt->data);//visit
}




/*PreOrderUnRecursion*/
void
PreOrderUnRecursion(BiTree bt)
{
	SqStack s;
	StackInit(&s);
	BTNode *p = bt;
	while(p || !StackEmpty(&s))
	{
		if(p)
		{
			printf("%8d", p->data);   //visit the data
			push(&s, p);
			p = p->lchild;
		}
		else /*if(!StackEmpty(&s))*/
		{
			p = pop(&s);
			p = p->rchild;
		}
	}
}
/*MidOrderUnRecursion*/
void 
MidOrderUnRecursion(BiTree bt)
{
	SqStack s;
	StackInit(&s);
	BTNode *p = bt;
	while(p || !StackEmpty(&s))
	{
		if(p)
		{
			push(&s,p);
			p = p->lchild;
		}
		else /*if(!StackEmpty(&s))*/
		{
			p = pop(&s);            //must pop first
			printf("%8d", p->data); // visit the data
			p = p->rchild;
		}
	}
}

/*PostOrderUnRecursion*/
void
PostOrderUnRecursion(BiTree bt)
{
	SqStack_Post s;
	StackInit_Post(&s);
	stacknode x;
	BTNode *p = bt;
	while(p || !StackEmpty_Post(&s))
	{
		if(p)
		{
			x.ptr = p;
			x.flag = 1;      //set the first visit
			push_post(&s, x); 
			p = p->lchild;
		}
		else
		{
			x = pop_post(&s); 
			if(x.flag == 1)
			{
				x.flag = 2;  //set the second visit
				p = x.ptr;
				push_post(&s, x);
				p = p->rchild;
			}
			else if(x.flag == 2)
			{
				printf("%8d", x.ptr->data);   //visit the x.ptr date,not p
			}
		}
	}

}

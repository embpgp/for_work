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

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>
//difine the datatype
typedef int datatype;
//difine the BT data_structure
typedef struct BTNode
{
	datatype data;
	struct BTNode *lchild;
	struct BTNode *rchild;

}BTNode,*pBTNode,*BiTree;

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
	if(parent->lchild == NULL)
	{
		parent->lchild = p;
	}
	else
	{
		p->lchild = parent->lchild;
		parent->lchild = p;
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
	if(parent->rchild == NULL)
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

	//if(p->li)
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

	//if(p->li)
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
	printf("%d\n", bt->data);
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
	printf("%d\n", bt->data); // visit3
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
	printf("%d\n", bt->data);//visit
}
int 
main(int argc, char *argv[])
{
	BiTree root = Create(1, NULL, NULL);
	InsertLeftForParent(root, 2, root);
	InsertRightForParent(root, 3, root);
	InsertLeftForParent(root, 4, root->lchild);
	InsertRightForParent(root, 5, root->rchild);
	DeleteRecursionSubtree(&(root->rchild));
	puts("**********PreOrder***************");
	PreOrder(root);
	puts("**********InOrder****************");
	InOrder(root);
	puts("**********PostOrder**************");
	PostOrder(root);
	return 0;
}
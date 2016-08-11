/*
 *File:test_for_BT.c
 *
 *Author:rutk1t0r
 *
 *Date:2016.8.11
 *
 *GPL
 *
 */

#include "BT.h"
#include "SqStack.h"


int 
main(int argc, char *argv[])
{
	BiTree root = Create(1, NULL, NULL);
	InsertLeftForParent(root, 2, root);
	InsertRightForParent(root, 3, root);
	InsertLeftForParent(root, 4, root->lchild);
	InsertRightForParent(root, 5, root->rchild);
	DeleteRecursionSubtree(&(root->rchild));
	puts("************PreOrder***************************");
	PreOrder(root);
	puts("\n**********InOrder****************************");
	InOrder(root);
	puts("\n**********PostOrder***************************");
	PostOrder(root);
	puts("\n**********PreOrderUnRecursion***************");
	PreOrderUnRecursion(root);
	puts("\n**********MidOrderUnRecursion****************");
	MidOrderUnRecursion(root);
	puts("\n**********PostOrderUnRecursion****************");
	PostOrderUnRecursion(root);
	puts("");
	return 0;
}
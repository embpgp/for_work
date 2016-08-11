/*
 *file BT.h
 *
 *Author:rutk1t0r
 *
 *Data:2016.8.11
 *
 *GPL
 */

#ifndef __BT__H__
#define __BT__H__


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
Create(datatype root, pBTNode lbt, pBTNode rbt);
/*2*/
BiTree
InsertLeftForParent(BiTree bt, datatype e, BiTree parent);
/*3*/
BiTree
InsertRightForParent(BiTree bt, datatype e, BiTree parent);

/*4*/
BiTree 
DeleteLelf(BiTree bt, BiTree parent);
/*5*/
BiTree 
DeleteRight(BiTree bt, BiTree parent);
/*Recursion delete*/
int 
DeleteRecursionSubtree(BiTree *p);
/*Recursion algorithm*/
void
PreOrder(BiTree bt);
void
InOrder(BiTree bt);
void
PostOrder(BiTree bt);

#endif
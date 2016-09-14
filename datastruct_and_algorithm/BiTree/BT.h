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


/*线索二叉树*/
typedef struct BiThrNode
{
	datatype data;
	struct BiThrNode *lchild;
	struct BiThrNode *rchild;
	unsigned ltag:1;     /*0 is pointer a lchild,1 is pre*/
	unsigned rtag:1;     /*0 is ponter a rchild, 1 is post*/
}BiThrNode, *BiThrTree;

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



/*PreOrderUnRecursion*/
void
PreOrderUnRecursion(BiTree bt);
/*MidOrderUnRecursion*/
void 
MidOrderUnRecursion(BiTree bt);
/*PostOrderUnRecursion*/
void
PostOrderUnRecursion(BiTree bt);





/*
二叉线索树的一些操作

*/
 /*中序遍历过程中进行中序线索化
  */


void 
InThread(BiThrTree p);
/*
 *中序遍历建立二叉索引树
 */
BiThrTree 
InOrderThr(BiThrTree p);

/*
 *访问各个节点
 */

void 
VisitThr(BiThrTree root);


/*创建二叉树*/
BiThrTree 
CreateThr(datatype root, BiThrNode* lbt, BiThrNode* rbt);
/*插入左子树*/
BiThrTree
InsertLeftForParentThr(BiThrTree bt, datatype e, BiThrTree parent);
/*插入右子树*/
BiThrTree
InsertRightForParentThr(BiThrTree bt, datatype e, BiThrTree parent);

#endif
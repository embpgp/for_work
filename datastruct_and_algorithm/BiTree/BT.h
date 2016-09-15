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
 *中序遍历访问各个节点
 */

void 
InVisitThr(BiThrTree root);


/*创建二叉树*/
BiThrTree 
CreateThr(datatype root, BiThrNode* lbt, BiThrNode* rbt);
/*插入左子树*/
BiThrTree
InsertLeftForParentThr(BiThrTree bt, datatype e, BiThrTree parent);
/*插入右子树*/
BiThrTree
InsertRightForParentThr(BiThrTree bt, datatype e, BiThrTree parent);

/*
在一棵建立好了的线索二叉树中查找一个任意节点的前驱节点
1.如果该节点没有左子树,那么它的左标志ltag为1,则左孩子的左指针域就是它的直接前驱
2.当有左子树的时候,ltag = 0,按照中序遍历的定义,该节点的直接前驱应该是以它的左孩子为根节点的子树的最右节点
  即沿着其左子树的右孩子节点指针rchild向下查找,当右标志rtag=1的时候,就找到了
*/

BiThrTree 
InPreNode(BiThrTree p);




/*
在一棵建立好了的线索二叉树中查找任意节点的前驱节点
1.如果这个节点没有右子树,那么它的右标志rtag=1,则右孩子即是它的直接后继
2.如果有右子树的话,那么rtag=0,依照中序遍历的定义,它的直接后继是以它的右孩子为根节点的最左边节点
  即沿着它的右子树的左孩子节点指针lchild向下查找,当左标志ltag=1的时候就找到了
*/

BiThrTree
InPostNode(BiThrTree p);


/*
查找值为e的节点,可以借助上述算法
1.先找到中序遍历的第一个节点,然后依次搜索它的后继节点来匹配
2.先找到中序遍历的最后一个节点,然后依次搜索它的前驱节点来匹配
*/

BiThrTree Locate(BiThrTree H, datatype e);



/*
前序遍历线索化
*/
void 
PreThread(BiThrTree p);
/*建立前序二叉线索树*/
BiThrTree 
PreOrderThr(BiThrTree p);
/*前序遍历访问*/
void 
PreVisitThr(BiThrTree root);



/* 后续遍历线索*/
void
PostThread(BiThrTree p);

/*后序二叉线索树*/
BiThrTree
PostOrderThr(BiThrTree p);
/*后续遍历访问*/
void
PostVisitThr(BiThrTree root);
/*后序线索化求某个节点的父节点*/
BiThrNode *
parent(BiThrTree root, BiThrNode *p);
#endif
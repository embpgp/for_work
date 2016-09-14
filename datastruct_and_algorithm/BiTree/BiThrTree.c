/*
 *File:BiThrTree.c
 *
 *Author:rutk1t0r
 *
 *Date:2016.9.14
 *
 *GPL
 *
 */


#include "BT.h"

BiThrNode *pre = NULL;   /*全局的变量*/

 /*中序遍历过程中进行中序线索化
  */
void InThread(BiThrTree p)
{
   
    if(p)
    {
        InThread(p->lchild);
        if(!p->lchild)
        {
            p->ltag = 1;
            p->lchild = pre;   /*pre 是一个全局指针,始终指向一个刚刚访问过的节点,便于指向
                                 一开始就是一个虚构的头节点,游离于原来的树之外的*/
        }
        else
        {
            p->ltag = 0;
        }
        if(!pre->rchild)
        {
            pre->rtag = 1;
            pre->rchild = p;
        }
        else
        {
            pre->rtag = 0;
        }
        pre = p;
        InThread(p->rchild);
    }
}

/*
 *中序遍历建立二叉索引树
 */
BiThrTree InOrderThr(BiThrTree p)
{
    BiThrTree root = (BiThrTree)malloc(sizeof(BiThrNode));
    root->ltag = 0;             /*建立虚拟根节点*/
    root->rtag = 1;
    root->lchild = p;
    root->rchild = root;
    if(!p)
    {
        root->lchild = root;
    }
    else
    {
        pre = root;
        InThread(p);
        pre->rchild = root;   /*最后访问的那个节点的后继节点为虚拟的根节点*/
        pre->rtag = 1;
        root->rchild = pre;   /*虚拟根节点的后继节点为最后访问的那个节点*/
    }
    return root;            /*不要误以为root是局部指针变量不可在函数中返回
                              在这里它保存的是堆空间首地址,所以可以直接返回传递给上一级的变量保存
                            */
}


/*
 *访问各个节点
 */

void VisitThr(BiThrTree root)
{
    BiThrNode *p = root->lchild;
    while(p != root)
    {
        while(p->ltag == 0)     /*先找到最左边的节点*/
        {
            p = p->lchild;
        }
        printf("%4d", p->data);  //可以直接访问了
        while(p->rtag == 1 && p->rchild != root)   //直接后驱又可以直接访问
        {
            p = p->rchild;
            printf("%4d", p->data);
        }
        p = p->rchild;
    }
}





/*创建二叉树*/
BiThrTree 
CreateThr(datatype root, BiThrNode* lbt, BiThrNode* rbt)
{
	/*create a BiTree for root and insert the lchild and rchild*/
	BiThrNode* p = (BiThrTree)malloc(sizeof(BiThrNode));
	if(p == NULL)
	{
		return NULL;
	}
	p->data = root;
	p->lchild = lbt;
	p->rchild = rbt;
	return p;
}

/*插入左子树*/
BiThrTree
InsertLeftForParentThr(BiThrTree bt, datatype e, BiThrTree parent)
{
	BiThrNode* p;
	if(parent == NULL)
	{
		printf("\nInsert error");
		return NULL;
	}
	if((p = (BiThrNode*)malloc(sizeof(BiThrNode))) == NULL)
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

/*插入右子树*/
BiThrTree
InsertRightForParentThr(BiThrTree bt, datatype e, BiThrTree parent)
{
	BiThrNode* p;
	if(parent == NULL)
	{
		printf("\nInsert error");
		return NULL;
	}
	if((p = (BiThrNode*)malloc(sizeof(BiThrNode))) == NULL)
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
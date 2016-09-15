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
BiThrTree 
InOrderThr(BiThrTree p)
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
        InThread(p);           /*线索化*/
        pre->rchild = root;   /*最后访问的那个节点的后继节点为虚拟的根节点*/
        pre->rtag = 1;
        root->rchild = pre;   /*虚拟根节点的后继节点为最后访问的那个节点*/
    }
    return root;            /*不要误以为root是局部指针变量不可在函数中返回
                              在这里它保存的是堆空间首地址,所以可以直接返回传递给上一级的变量保存
                            */
}


/*
 *中序遍历访问各个节点
 */

void InVisitThr(BiThrTree root)
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




/*
在一棵建立好了的线索二叉树中查找一个任意节点的前驱节点
1.如果该节点没有左子树,那么它的左标志ltag为1,则左孩子的左指针域就是它的直接前驱
2.当有左子树的时候,ltag = 0,按照中序遍历的定义,该节点的直接前驱应该是以它的左孩子为根节点的子树的最右节点
  即沿着其左子树的右孩子节点指针rchild向下查找,当右标志rtag=1的时候,就找到了
*/

BiThrTree 
InPreNode(BiThrTree p)
{
    BiThrNode *pre = p->lchild;
    if(p->ltag != 1)
    {
        while(pre->rtag == 0)
        {
            pre = pre->rchild;
        }
    }
    return pre;
}

/*
在一棵建立好了的线索二叉树中查找任意节点的前驱节点
1.如果这个节点没有右子树,那么它的右标志rtag=1,则右孩子即是它的直接后继
2.如果有右子树的话,那么rtag=0,依照中序遍历的定义,它的直接后继是以它的右孩子为根节点的最左边节点
  即沿着它的右子树的左孩子节点指针lchild向下查找,当左标志ltag=1的时候就找到了
*/

BiThrTree
InPostNode(BiThrTree p)
{
    BiThrNode *post = p->rchild;
    if(p->rtag != 1)
    {
        while(post->ltag == 0)
        {
            post = post->lchild;
        }

    }
    return post;
}

/*
查找值为e的节点,可以借助上述算法
1.先找到中序遍历的第一个节点,然后依次搜索它的后继节点来匹配
2.先找到中序遍历的最后一个节点,然后依次搜索它的前驱节点来匹配
*/

BiThrTree Locate(BiThrTree H, datatype e)
{
    //方法1
    BiThrNode *pre = H->lchild;
    while(pre->ltag == 0 && pre != H)
    {
        pre = pre->lchild;
    }
    while(pre != H && pre->data != e)
    {
        pre = InPostNode(pre);
    }
    if(pre == H)
    {
        printf("Not found the data\n");
        return NULL;
    }
    else
    {
        return pre;
    }
    /*方法2
    BiThrNode *post = H->rchild;
    while(post->rtag == 0 && post != H)
    {
        post = post->rchild;
    }
    while(post != H && post->data != e)
    {
        post = InPostNode(post);
    }
    if(post == H)
    {
        printf("Not found the data\n");
        return NULL;
    }
    else
    {
        return post;
    }

    */    
}




/*
前序遍历线索化
*/
void 
PreThread(BiThrTree p)
{
    if(p)
    {
        if(!p->lchild)
        {
            p->ltag = 1;
            p->lchild = pre;
        }
        else
        {
            p->ltag = 0;
        }
        if(!pre->rchild)      //注意要交换来
        {
            pre->rtag = 1;
            pre->rchild = p;
        }
        else
        {
            pre->rtag = 0;
        }
        pre = p;


        if(p->ltag == 0)
        {
            PreThread(p->lchild);
        }
        if(p->rtag == 0)
        {
            PreThread(p->rchild);
        }
    }
}

/*建立前序二叉线索树*/
BiThrTree 
PreOrderThr(BiThrTree p)
{
    BiThrNode* root = (BiThrNode*)malloc(sizeof(BiThrNode));  //建立虚拟头节点
    root->lchild = p;
    root->ltag = 0;
    root->rtag = 1;
    root->rchild = root;
    if(!p)
    {
        root->lchild = root;
    }
    else
    {
        pre = root;
        PreThread(p);       //线索化
        pre->rtag = 1;
        root->rchild = pre;
        pre->rchild = root;
    }
    return root;
}


/*前序遍历访问*/
void
PreVisitThr(BiThrTree root)
{
    BiThrNode *p = root->lchild;
    while(p != root)
    {
        printf("%4d", p->data);
        if(p->ltag == 0)
        {
            p = p->lchild;
        }
        else
        {
            p = p->rchild;
        }
    }
}




/*
    后续遍历线索化
*/

void
PostThread(BiThrTree p)
{
    if(p)
    {
        PostThread(p->lchild);
        PostThread(p->rchild);
        if(!p->lchild)
        {
            p->ltag = 1;
            p->lchild = pre;
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
        pre = p;            //一定不能忘记这条语句
    }
}

/*
    后序二叉线索树
*/

BiThrTree
PostOrderThr(BiThrTree p)
{
    BiThrNode *root = (BiThrTree)malloc(sizeof(BiThrNode));
    root->rchild = root;
    root->ltag = 0;
    root->rtag = 1;
    root->lchild = p;
    if(!p)
    {
        root->lchild = root;        
    }
    else
    {
        pre = root;
        PostThread(p);
        root->rchild = pre;
        //pre->rchild = root;        出bug的地方,在于没有深刻理解结构体各个成员的含义,xjbg了
        
    }
    return root;
}

/*后序线索化求某个节点的父节点*/
BiThrNode *parent(BiThrTree root, BiThrNode *p)
{
    BiThrNode *temp = root;
    if(p == temp->lchild)
    {
        return temp;
    }    
    else
    {
        temp = temp->lchild;
        while(temp->lchild != p && temp->rchild != p)
        {
            if(temp->rtag == 0)
            {
                temp = temp->rchild;      //一定要先往右边走,为什么呢?因为根据后序遍历的定义一定是
            }                             //它的右子树遍历完了才轮到自己,左右根嘛,果然后序是树里面最难的.....
            else
            {
                temp = temp->lchild;
            }
        }
        return temp;
    }
}

void
PostVisitThr(BiThrTree v_root)
{
    BiThrNode* p = v_root->lchild;
    BiThrNode* par;
    while(1)
    {
        while(p->ltag == 0)
        {
            p = p->lchild;
        }
        if(p->rtag == 0)
        {
            p = p->rchild;
        }
        else
        {
            break;           //先找到第一个需要访问的节点,然后分情况进行讨论
        }
    }


    while(p != v_root)
    {
        printf("%4d", p->data);
        par = parent(v_root, p);
        if(par == v_root)
        {
            p = v_root;  //若p的父节点是根节点,没有后继节点,完成所有遍历
        }
        else if(p == par->rchild || par->rtag == 1)
        {
            p = par;  //若访问的已经是右孩子节点,或者是独生左孩子，则后继为双亲,则马上应该访问它的父节点了
        }
        else
        {
            /*
            while(par->rtag == 0)             //若访问的是具有兄弟节点的左孩子节点,则下一个遍历点应该是它的父节点的右子树
            {                                     //按照后序遍历最左边的节点,这个这个过程应该和上面的那个算法一样的
                par = par->rchild;         //只是没有用while(1)而已
                while(par->ltag == 0)
                {
                    par = par->lchild;
                }

            }
            */
            par = par->rchild;             //这个和上面的一样也阔以跑
            while(1)
            {
                
                while(par->ltag == 0)
                {
                    par = par->lchild;
                }
                if(par->rtag == 0)
                {
                    par = par->rchild;
                }
                else
                {
                    break;
                }
            }
            

            p = par;
        }
    }
}
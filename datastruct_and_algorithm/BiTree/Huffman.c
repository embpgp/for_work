/*Filename:Huffman.c
 *
 *Author:rutk1t0r
 *
 *Date:2016.9.16
 *
 *GPL
 *
 */


#include "Huffman.h"

/*哈夫曼树的生成算法*/
void
HuffmanTree(HNode HuffmanNode[], int n)
{
    int i,j;
    int a1,a2,b1,b2;
    /*
    printf("请输入节点的个数:");
    scanf("%d", &n);
    for(i = 0; i<2*n-1; ++i)
    {
        HuffmanNode[i].weight = 0;
        HuffmanNode[i].parent = -1;
        HuffmanNode[i].lchild = -1;
        HuffmanNode[i].rchild = -1;
    }
    printf("请输入各个节点的权值:");
    for(i = 0; i<n; ++i)
    {
        scanf("%d",&HuffmanNode[i].weight);
    }
    */
    //输入基本完成,可以开始构造哈夫曼树了
    for(i = 0; i<n-1; ++i)    //注意此处的i值为<n-1,如果错写成n就会出问题,因为会造成操作越界,2n-1个节点的最后一个节点
    {                           //的下标为2n-2
        a1 = a2 = MaxWeight;   //记录最小和次小的节点的权值
        b1 = b2 = 0;           //记录最小和次小的节点的本身数组中偏移量
        for(j = 0; j<n+i; ++j)
        {
            if((HuffmanNode[j].weight < a1) && (HuffmanNode[j].parent == -1))
            {
                a2 = a1;
                b2 = b1;
                a1 = HuffmanNode[j].weight;
                b1 = j;
            }
            else if((HuffmanNode[j].weight < a2 ) && (HuffmanNode[j].parent == -1))
            {
                a2 = HuffmanNode[j].weight;
                b2 = j;
            }
        }   //本次for循环退出的时候已经找到了两个最小的节点了,现在开始生成新的节点
        HuffmanNode[b1].parent = n+i;
        HuffmanNode[b2].parent = n+i;
        HuffmanNode[n+i].weight = HuffmanNode[b1].weight + HuffmanNode[b2].weight;
        HuffmanNode[n+i].lchild = b1;
        HuffmanNode[n+i].rchild = b2;
      //所以最后的根节点没有父节点,其parent值为-1

    }
}


//传递进来的哈夫曼树已经构造完成了
void
HuffmanCodeTree(HNode HuffmanNode[], int n, HCodeType HuffmanCode[])
{
    HCodeType cd;    //临时的
    int i,j,child,p;
    for(i = 0; i<n; ++i)
    {
        cd.start = n-1;//
        child = i;
        p = HuffmanNode[child].parent;
        while(p != -1)    //最后的根节点,因为当初约定是没有父节点的节点的parent域值为-1,所以在这里我们
        {                   //用的教科书上是有误的
            if(HuffmanNode[p].lchild == child)
            {
                cd.code[cd.start] = 0;
            }
            else
            {
                cd.code[cd.start] = 1;
            }
            cd.start--;      //逆向递减
            child = p;       //父节点又作为子节点继续往根节点走
            p = HuffmanNode[child].parent;
        }
        for(j = cd.start+1; j<n; ++j)
        {
            HuffmanCode[i].code[j] = cd.code[j];    //临时的赋值回去
        }
        HuffmanCode[i].start = cd.start;
    }
    //打印出来
    for(i = 0; i<n; ++i)
    {
        printf("the node %d code is :", HuffmanNode[i].weight);
        for(j = HuffmanCode[i].start + 1; j<n; j++)
        {
            printf("%d", HuffmanCode[i].code[j]);
        }
        printf("\n");
    }

}
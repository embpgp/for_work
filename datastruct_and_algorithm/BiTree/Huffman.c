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


void
HuffmanTree(HNode HuffmanNode[])
{
    int i,j;
    int a1,a2,b1,b2,n;
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
    //输入基本完成,可以开始构造哈夫曼树了
    for(i = 0; i<n; ++i)
    {
        a1 = a2 = MaxWeight;   //记录最小和次小的节点的权值
        b1 = b2 = 0;           //记录最小和次小的节点的本身数组中偏移量
        for(j = 0; j<n+i; ++j)
        {
            if(HuffmanNode[j].weight < a1 && HuffmanNode[j].parent == -1)
            {
                a2 = a1;
                b2 = b1;
                a1 = HuffmanNode[j].weight;
                b1 = j;
            }
            else if(HuffmanNode[j].weight < a2 && HuffmanNode[j].parent == -1)
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


    }
}
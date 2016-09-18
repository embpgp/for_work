/*
 *filename: test_for_Huffman.c
 *
 *Author:rutk1t0r
 *
 *Data:2016.9.18
 *
 *GPL
 *
 *method:`gcc -o test_for_Huffman test_for_Huffman.c Huffman.c`
 */


#include "Huffman.h"

int main(int argc, char *argv[])
{
    //由于构造哈夫曼树的算法我注释掉了输入的过程,所以在主函数中先进行输入
    HNode HuffmanNode[MaxNode];
    HCodeType HuffmanCode[MaxNode];
    int i,n;
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
    
    /*构造哈夫曼树的算法*/

    HuffmanTree(HuffmanNode,n);
    /*哈弗曼编码算法*/
    printf("value parent lchild rchild\n");
    for(i = 0; i<2*n-1; i++)
    {
        printf("%6d %6d %6d %6d\n", HuffmanNode[i].weight,HuffmanNode[i].parent, HuffmanNode[i].lchild, HuffmanNode[i].rchild);
    }
    HuffmanCodeTree(HuffmanNode,n,HuffmanCode);
    return 0;
}


/*
 *filename: Huffman.h
 *
 *Author:rutk1t0r
 *
 *Data:2016.9.16
 *
 *GPL
 */




#ifndef HUFFMAN_H
#define HUFFMAN_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>

#define MaxWeight 65535
#define MaxNode     128
#define MaxCode     64
typedef struct
{
    int weight; 
    int parent;
    int lchild;
    int rchild;
}HNode;


typedef struct
{
    int code[MaxCode];   //保存序列
    int start;          //从最下面的节点到根节点这一段最下面节点的偏移量,即起始位置,但是保存的时候是"逆向"的
}HCodeType;

/*构造哈夫曼树的算法*/
void 
HuffmanTree(HNode HuffmanNode[],int n);
/*哈弗曼编码算法*/
void
HuffmanCodeTree(HNode HuffmanNode[], int n, HCodeType HuffmanCode[]);
#endif
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
#define MaxNode     100
typedef struct
{
    int weight; 
    int parent;
    int lchild;
    int rchild;
}HNode;



/*构造哈夫曼树的算法*/
void 
HuffmanTree(HNode HuffmanNode[]);
#endif
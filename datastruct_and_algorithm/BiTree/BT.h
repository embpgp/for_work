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


#endif
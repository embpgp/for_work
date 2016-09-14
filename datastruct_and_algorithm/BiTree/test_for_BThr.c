/*
 *File:test_for_BThr.c
 *
 *Author:rutk1t0r
 *
 *Date:2016.9.14
 *
 *GPL
 *
 */

 #include "BT.h"


 int main(int argc, char *argv[])
 {
     BiThrTree root = CreateThr(1, NULL, NULL);
     InsertLeftForParentThr(root, 2, root);
     InsertRightForParentThr(root, 3, root);
     InsertLeftForParentThr(root, 4, root->lchild);
     InsertRightForParentThr(root, 5, root->rchild);
     BiThrTree v_root = InOrderThr(root);
     printf("中序线索遍历结果如下:\n");
     VisitThr(v_root);
     printf("\n");
     return 0;
 }
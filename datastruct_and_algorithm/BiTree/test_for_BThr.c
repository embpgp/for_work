/*
 *File:test_for_BThr.c
 *
 *Author:rutk1t0r
 *
 *Date:2016.9.14
 *
 *GPL
 *
 *method:`gcc -o test_for_BThr BiThrTree.c test_for_BThr.c`
 */

 #include "BT.h"


 int main(int argc, char *argv[])
 {
     /*用最死板的方法创建一个二叉树*/
     BiThrTree root = CreateThr(1, NULL, NULL);
     InsertLeftForParentThr(root, 2, root);
     InsertRightForParentThr(root, 3, root);
     InsertLeftForParentThr(root, 4, root->lchild);
     InsertRightForParentThr(root, 5, root->rchild);
     
     /*
     BiThrTree v_root = InOrderThr(root);
     printf("中序线索遍历结果如下:\n");
     InVisitThr(v_root); 
     printf("\n");
     
     printf("前序遍历结果如下:\n");
     BiThrTree v_root = PreOrderThr(root);
     PreVisitThr(v_root);
     printf("\n");
     */
     
     printf("后序遍历结果如下:\n");
     BiThrTree v_root = PostOrderThr(root);
     PostVisitThr(v_root);
     printf("\n");
     
     return 0;
 }
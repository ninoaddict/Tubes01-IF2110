#include <stdio.h>
#include <stdlib.h>
#include "bintree.h"

BinTree NewTree (ElType root, BinTree left_tree, BinTree right_tree){
    BinTree p = newTreeNode(root);
    if (p != NULL){
        LEFT(p) = left_tree;
        RIGHT(p) = right_tree;
    }
    return p;
}

void CreateTree (ElType root, BinTree left_tree, BinTree right_tree, BinTree *p){
    *p = newTreeNode(root);
    if (*p != NULL){
        LEFT(*p) = left_tree;
        RIGHT(*p) = right_tree;
    }
}

Address newTreeNode(ElType val){
    Address p = (Address) malloc(sizeof(TreeNode));
    if(p != NULL){
        ROOT(p) = val;
        LEFT(p) = NULL;
        RIGHT(p) = NULL;
    }
    return p;
}

void deallocTreeNode (Address p){
    free(p);
}

boolean isTreeEmpty (BinTree p){
    return (p == NULL);
}


boolean isOneElmt (BinTree p){
    return (!isTreeEmpty(p) && isTreeEmpty(LEFT(p)) && isTreeEmpty(RIGHT(p)));
}

boolean isUnerLeft (BinTree p){
    return (!isTreeEmpty(p) && !isTreeEmpty(LEFT(p)) && isTreeEmpty(RIGHT(p)));
}

boolean isUnerRight (BinTree p){
    return (!isTreeEmpty(p) && isTreeEmpty(LEFT(p)) && !isTreeEmpty(RIGHT(p)));
}

boolean isBinary (BinTree p){
    return (!isTreeEmpty(p) && !isTreeEmpty(LEFT(p)) && !isTreeEmpty(RIGHT(p)));
}

void printPreorder(BinTree p){
    printf("(");
    if (isTreeEmpty(p)){
        printf("()");
    }
    else {
        printf("(");
        printf("%d",ROOT(p));
        printPreorder(LEFT(p));
        printPreorder(RIGHT(p));
        printf(")");
    }
}

void printInorder(BinTree p){
    if (isTreeEmpty(p)) {
        printf("()");
    }
    else {
        printf("(");
        printInorder(LEFT(p));
        printf("%d",ROOT(p));
        printInorder(RIGHT(p));
        printf(")");
    }
}

void printPostorder(BinTree p){
    if (isTreeEmpty(p)) {
        printf("()");
    }
    else {
        printf("(");
        printPostorder(LEFT(p));
        printPostorder(RIGHT(p));
        printf("%d",ROOT(p));
        printf(")");
    }
}

void recursivePrintTree(BinTree p, int h, int dep){
// fungsi tambahan
    if(!isTreeEmpty(p)){
        for(int i = 0; i < h*dep; i++){
            printf(" ");
        }
        printf("%d\n", ROOT(p));
        recursivePrintTree(LEFT(p), h, dep+1);
        recursivePrintTree(RIGHT(p), h, dep+1);
    }
}

void printTree(BinTree p, int h) {
    recursivePrintTree(p, h, 0);
}
#ifndef POHONBINER_H
#define POHONBINER_H

#include "boolean.h"
#include <stdio.h>
#include "../linkedlist/linkedlist.h"
#include "../../../src/app/reply/reply.h"
#include "../../../src/app/reply/treebalasan.h"

/* Selektor */
#define ROOT(p) (p)->info
#define LEFT(p) (p)->left
#define RIGHT(p) (p)->right

typedef Balasan ElType;
typedef struct treeNode* Address;
typedef struct treeNode { 
     ElType info;
     Address left;
     Address right;
} TreeNode;

typedef Address BinTree;

BinTree NewTree (ElType root, BinTree left_tree, BinTree right_tree);
    
void CreateTree (ElType root, BinTree left_tree, BinTree right_tree, BinTree *p);
/* I.S. Sembarang
   F.S. Menghasilkan sebuah pohon p
   Menghasilkan sebuah pohon biner p dari akar, l, dan r, jika alokasi 
   berhasil 
   Menghasilkan pohon p yang kosong (NULL) jika alokasi gagal */

Address newTreeNode(ElType val);
/* Alokasi sebuah address p, bernilai tidak NULL jika berhasil */
/* Mengirimkan address hasil alokasi sebuah elemen bernilai val
   Jika alokasi berhasil, maka address tidak NULL, dan misalnya 
   menghasilkan p, maka p↑.info=val, p↑.left=NULL, p↑.right=NULL 
   Jika alokasi gagal, mengirimkan NULL */

void deallocTreeNode (Address p);
/* I.S. p terdefinisi 
   F.S. p dikembalikan ke sistem 
   Melakukan dealokasi/pengembalian address p */

void deleteTreeNode(BinTree p, Address q);
// Delete node beserta left childnya
// Jika node yang akan dihapus merupakan left child, pindahkan pointer root ke right child
// Jika node yang akan dihapus bukan left child, pindahkan pointer yang mengarah ke dirinya ke siblings sebelahnya.

boolean isTreeEmpty (BinTree p);
/* Mengirimkan true jika p adalah pohon biner yang kosong */

boolean isOneElmt (BinTree p);
/* Mengirimkan true jika p tidak kosong dan hanya terdiri atas 1 elemen */

boolean isUnerLeft (BinTree p);
// Buat check punya balasan apa engga

boolean isUnerRight (BinTree p);
// Buat check ada balasan lainnya apa engga

void printLeftChild(BinTree p);
// Print balasan 

void printRightChild(BinTree p);
// Print balasan lainnya

#endif
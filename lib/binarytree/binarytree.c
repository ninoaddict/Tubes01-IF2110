#include "binarytree.h"
#include "boolean.h"
#include <stdio.h>
#include <stdlib.h>

BinTree NewTree(ElType root, BinTree left_tree, BinTree right_tree)
{
   Address p = (Address)malloc(sizeof(TreeNode));
   if (p != NULL)
   {
      ROOT(p) = root;
      LEFT(p) = left_tree;
      RIGHT(p) = right_tree;
   }
}

void CreateTree(ElType root, BinTree left_tree, BinTree right_tree, BinTree *p)
{
   *p = NewTree(root, left_tree, right_tree);
}

Address newTreeNode(ElType val)
{
   Address p = (Address)malloc(sizeof(TreeNode));
   if (p != NULL)
   {
      ROOT(p) = val;
   }
   /* Alokasi sebuah address p, bernilai tidak NULL jika berhasil */
   /* Mengirimkan address hasil alokasi sebuah elemen bernilai val
      Jika alokasi berhasil, maka address tidak NULL, dan misalnya
      menghasilkan p, maka p↑.info=val, p↑.left=NULL, p↑.right=NULL
      Jika alokasi gagal, mengirimkan NULL */
}

void deallocTreeNode(Address p)
{
   free(p);
   /* I.S. p terdefinisi
      F.S. p dikembalikan ke sistem
      Melakukan dealokasi/pengembalian address p */
}

void deleteTreeNode(BinTree p, Address q)
{

   // Delete node beserta left childnya
   // Jika node yang akan dihapus merupakan left child, pindahkan pointer root ke right child
   // Jika node yang akan dihapus bukan left child, pindahkan pointer yang mengarah ke dirinya ke siblings sebelahnya.
}

boolean isTreeEmpty(BinTree p)
{
   return p == NULL;
   /* Mengirimkan true jika p adalah pohon biner yang kosong */
}

boolean isUnerLeft(BinTree p)
{
   return (!isTreeEmpty(p) && LEFT(p) != NULL && RIGHT(p) == NULL);
   /* Mengirimkan true jika pohon biner tidak kosong, p adalah pohon unerleft: hanya mempunyai subpohon kiri */
}

boolean isUnerRight(BinTree p)
{
   return (!isTreeEmpty(p) && LEFT(p) == NULL && RIGHT(p) != NULL);
   // Buat check ada balasan lainnya apa engga
}

void printLeftChild(BinTree p)
{
   printf("%d\n", LEFT(p));
   // Print balasan
}

void printRightChild(BinTree p)
{
   displayList(p);
   // Print balasan lainnya
}

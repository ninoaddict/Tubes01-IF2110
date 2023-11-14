#include <stdio.h>
#include <stdlib.h>
#include "treebalasan.h"

void createTreeBalasan(TreeBalasan *t, int IDbalasan)
{
    CreateTree(IDbalasan, NULL, NULL);
}

void deleteTreeBalasan(TreeBalasan *t)
{
}

void dealocateTreeBalasan(TreeBalasan *t)
{
}

void addBalasan(TreeBalasan *t, int IDyangingindibalasan, int IDbalasan)
{
    Address p = newTreeNode(IDbalasan);
}

Address searchByID (TreeBalasan t, int id){
    boolean isFound = false;
    Address p = LEFT(t);
    if (ID(p) == id){
        return p;
    }
    
}

#include <stdio.h>
#include <stdlib.h>
#include "treebalasan.h"

AddressTree createNewNode(Balasan balasan)
{
    AddressTree newBalasan = (AddressTree) malloc(sizeof(NodeBalasan));
    if (newBalasan != NULL)
    {
        INFO(newBalasan) = balasan;
        LEFT(newBalasan) = NULL;
        RIGHT(newBalasan) = NULL;
    }
    return newBalasan;
}

void createTreeBalasan(TreeBalasan *t)
{
    *t = NULL;
}

void addBalasan(AddressTree *n, Balasan balasan)
{
    AddressTree newBalasan = createNewNode(balasan);
    if (isTreeBalasanEmpty(*n))
    {
        // printf("not ok 1\n");
        *n = newBalasan;
    }
    else if (LEFT(*n) == NULL)
    {
        // printf()
        // printf("not ok 2\n");
        LEFT(*n) = newBalasan;
    }
    else
    {
        // printf("od\n");
        AddressTree p = LEFT(*n);
        while (RIGHT(p) != NULL)
        {
            p = RIGHT(p);
        }
        // printf("Info b: %d\n", IDBALASAN(INFO(p)));
        RIGHT(p) = newBalasan;
    }
}

// void deleteTreeBalasan(TreeBalasan *t, int idFind)
// {
//     AddressTree p;
//     boolean isFound = false;
//     if (searchBalasan(*t, idFind) != NULL)
//     {
//         printf("Info hasil search: %d\n", IDBALASAN(INFO(searchBalasan(*t, idFind))));
//         if (IDBALASAN(INFO(*t)) == idFind)
//         {
//             printf("Masuk diri sendiri\n");
//             deleteAllNode(LEFT(*t));
//             printf("Info left sekarang: %d\n", IDBALASAN(INFO(RIGHT(*t))));
//             p = *t;

//             LEFT(*t) = RIGHT(*t);

//             RIGHT(*t) = RIGHT(LEFT(*t));

//             free(p);
//         }
//         else if (searchBalasan(RIGHT(*t), idFind) != NULL)
//         {
//             deleteTreeBalasan(&RIGHT(*t), idFind);
//             //     else // Kalo di RIGHT(t) gaada, pasti RIGHT(t) punya RIGHT lagi
//             //     {
//             //         AddressTree prevDel = RIGHT(t);
//             //         AddressTree del = RIGHT(prevDel);
//             //         while (!isFound && del != NULL)
//             //         {
//             //             if (IDBALASAN(INFO(del)) == idFind)
//             //             {
//             //                 RIGHT(prevDel) = RIGHT(del);
//             //                 deleteAllNode(del);
//             //                 isFound = true;
//             //             }
//             //             else if (searchBalasan(del, idFind) != 0)
//             //             {
//             //                 deleteTreeBalasan(del, idFind);
//             //                 isFound = true;
//             //             }
//             //             prevDel = RIGHT(prevDel);
//             //             del = RIGHT(del);
//             //         }
//             //     }
//         }
//         else
//         { // Balasan yang ingin dihapus ada di LEFT(t)
//             printf("Masuk kiri bang\n");
//             deleteTreeBalasan(&LEFT(*t), idFind);
//         }
//     }
// }

boolean deleteTreeBalasan(TreeBalasan t, int idFind){
    AddressTree p = t;
    boolean udah = false;
    if (IDBALASAN(INFO(t)) == idFind){
        t = RIGHT(p);
        deleteAllNode(LEFT(p));
        free(p);
        return true;
    }
    else{
        AddressTree sibling = RIGHT(p);
        if (sibling != NULL){
            if (IDBALASAN(INFO(sibling)) == idFind){
                RIGHT(p) = RIGHT(sibling);
                deleteAllNode(LEFT(sibling));
                free(sibling);
                return true;
            }
            else{
                // printf("masuk sini\n");
                udah = deleteTreeBalasan(sibling, idFind);
            }
        }
        AddressTree child = LEFT(p);
        if (child != NULL && !udah){
            if (IDBALASAN(INFO(child)) == idFind){
                LEFT(p) = RIGHT(child);
                deleteAllNode(LEFT(child));
                free(child);
                return true;
            }
            else{
                udah = deleteTreeBalasan(sibling, idFind);
            }
        }
    }
    return udah;
}

void deleteAllNode(AddressTree n)
{
    // printf("line102\n");
    if (!isTreeBalasanEmpty(n))
    {
        if (isOneElementTree(n))
        {
            printf("Masuk onelmt\n");
            // AddressTree p = n;
            // n = NULL;
            // free(p);
        }
        else
        {
            printf("Masuk banyakelmt\n");
            // while (LEFT(n) != NULL)
            // {
            //     deleteAllNode(LEFT(n));
            // }
            // while (RIGHT(n) != NULL)
            // {
            //     deleteAllNode(RIGHT(n));
            // }
            if (LEFT(n) != NULL){
                deleteAllNode(LEFT(n));
            }
            if (RIGHT(n) != NULL){
                deleteAllNode(RIGHT(n));
            }
            // free(n);
        }
    }
    if (n != NULL)
        free(n);
    // printf("line124\n");
}

boolean isTreeBalasanEmpty(TreeBalasan t)
{
    return t == NULL;
}

boolean isOneElementTree(TreeBalasan t)
{
    return t != NULL && LEFT(t) == NULL && RIGHT(t) == NULL;
}

boolean isNodeHaveBalasan(TreeBalasan t)
{
    return LEFT(t) != NULL;
    // RIGHT(t) gausah dicek soalnya dia ngisinya dari LEFT(t), kalo leftnya null pasti rightnya juga null
}

AddressTree searchBalasan(TreeBalasan t, int idFind)
{
    // Mengirimkan nilai address jika ditemukan dan NULL jika tidak ditemukan
    AddressTree p = t;
    if (isTreeBalasanEmpty(t))
    {
        return NULL;
    }
    if (IDBALASAN(INFO(t)) == idFind)
    {
        return p;
    }
    else
    {
        AddressTree leftResult = searchBalasan(LEFT(t), idFind);
        AddressTree rightResult = searchBalasan(RIGHT(t), idFind);

        // Use logical OR to combine the results
        if (leftResult != NULL)
            return leftResult;
        else
            return rightResult;
    }
}

#include "treebalasan.h"

/* Constructor */
AddressTree CreateNewNode(Balasan balasan)
{
    AddressTree newBalasan = (AddressTree)malloc(sizeof(NodeBalasan));
    if (newBalasan != NULL)
    {
        LEFT(newBalasan) = NULL;
        RIGHT(newBalasan) = NULL;
        INFOREP(newBalasan) = balasan;
    }
    return newBalasan;
}

void CreateTreeBalasan(TreeBalasan *t)
{
    t->nEff = 0;
    t->parentNode = NULL;
}

/* Boolean Operation */
boolean isAddressTreeEmpty(AddressTree t)
{
    return t == NULL;
}

boolean isOneElementTree(AddressTree t)
{
    return t != NULL && LEFT(t) == NULL && RIGHT(t) == NULL;
}

boolean doesNodeHaveBalasan(AddressTree t)
{
    return LEFT(t) != NULL;
}

/* Search Operation */
AddressTree searchBalasan(AddressTree t, int idFind)
{
    if (idFind == -1) // if search is done on NULL parent tree
        return NULL;
    else if (isAddressTreeEmpty(t)) // if search is done on empty tree
        return NULL;
    else if (IDBALASAN(INFOREP(t)) == idFind) // if current node id is equal to the query id
        return t;
    else
    {
        AddressTree leftRes = searchBalasan(LEFT(t), idFind);
        if (leftRes != NULL) // if node address alredy found
            return leftRes;
        else
            return searchBalasan(RIGHT(t), idFind);
    }
}

/* Add Operation */
void addBalasan(AddressTree *n, Balasan balasan)
{
    AddressTree newBalasan = CreateNewNode(balasan);
    if (isAddressTreeEmpty(*n))
        *n = newBalasan;
    else if (LEFT(*n) == NULL)
        LEFT(*n) = newBalasan;
    else
    {
        AddressTree p = LEFT(*n);
        while (RIGHT(p) != NULL)
            p = RIGHT(p);
        RIGHT(p) = newBalasan;
    }
}

/* Remove Operation */

void deleteAllNode(AddressTree n)
{
    if (isAddressTreeEmpty(n))
        return;

    // start deletion from child
    if (LEFT(n) != NULL)
        deleteAllNode(LEFT(n));

    // deletion from sibling
    if (RIGHT(n) != NULL)
        deleteAllNode(RIGHT(n));

    free(n);
}

int deleteTreeBalasan(AddressTree *t, int idFind, int currID)
{
    AddressTree p = *t;
    int isDone = 0;
    if (p == NULL)
        return 0;
    else if (IDBALASAN(INFOREP(p)) == idFind)
    {
        if (IDAUTHORBALASAN(INFOREP(p)) == currID)
        {
            *t = RIGHT(p);
            deleteAllNode(LEFT(p));
            free(p);
            return 1;
        }
        else
            return 2;
    }
    else
    {
        // check sibling
        AddressTree sibling = RIGHT(p);
        if (sibling != NULL)
        {
            if (IDBALASAN(INFOREP(sibling)) == idFind)
            {
                if (IDAUTHORBALASAN(INFOREP(sibling)) == currID)
                {
                    RIGHT(p) = RIGHT(sibling);
                    deleteAllNode(LEFT(sibling));
                    free(sibling);
                    return 1;
                }
                else
                    return 2;
            }
            else
            {
                isDone = deleteTreeBalasan(&sibling, idFind, currID);
            }
        }

        // check child
        AddressTree child = LEFT(p);
        if (child != NULL && !isDone)
        {
            if (IDBALASAN(INFOREP(child)) == idFind)
            {
                if (IDAUTHORBALASAN(INFOREP(child)) == currID)
                {
                    LEFT(p) = RIGHT(child);
                    deleteAllNode(LEFT(child));
                    free(child);
                    return 1;
                }
                else
                    return 2;
            }
            else
            {
                isDone = deleteTreeBalasan(&child, idFind, currID);
            }
        }
    }
    return isDone;
}

/* Display */
void skipTab(int dep)
{
    for (int i = 0; i < dep; i++)
    {
        printf("   ");
    }
}

void displayBalasanPublic(Balasan bal, int dep)
{
    skipTab(dep);
    printf("| ID = %d\n", bal.id);
    skipTab(dep);
    printf("| ");
    displayWord(bal.author);
    skipTab(dep);
    printf("| ");
    TulisDATETIME(bal.time);
    printf("\n");
    skipTab(dep);
    printf("| ");
    displayWord(bal.text);
    printf("\n");
}

void displayBalasanPrivate(Balasan bal, int dep)
{
    skipTab(dep);
    printf("| ID = %d\n", bal.id);
    skipTab(dep);
    printf("| PRIVAT\n");
    skipTab(dep);
    printf("| PRIVAT\n");
    skipTab(dep);
    printf("| PRIVAT\n\n");
}

int countTreeElement(AddressTree t){
    if (isAddressTreeEmpty(t))
        return 0;
    else
        return 1 + countTreeElement(LEFT(t)) + countTreeElement(RIGHT(t));
}
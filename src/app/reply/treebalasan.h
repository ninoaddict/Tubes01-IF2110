#ifndef __TREEBALASAN_H__
#define __TREEBALASAN_H__

#include <stdio.h>
#include <stdlib.h>
#include "reply.h"
#include "../../../lib/boolean.h"

/* Constructor */
AddressTree CreateNewNode(Balasan balasan);

void CreateTreeBalasan(TreeBalasan *t);

/* Boolean Operation */

boolean isAddressTreeEmpty(AddressTree t);

boolean isOneElementTree(AddressTree t);

boolean doesNodeHaveBalasan(AddressTree t);

/* Search Operation */

AddressTree searchBalasan(AddressTree t, int idFind);

/* Add Operation */

void addBalasan(AddressTree *n, Balasan balasan);

/* Delete Operation */

void deleteAllNode(AddressTree n);

int deleteTreeBalasan(AddressTree *t, int idFind, int currID);

/* Display */
void displayBalasanPublic(Balasan bal, int dep);
void displayBalasanPrivate(Balasan bal, int dep);
void skipTab(int dep);

#endif
#include <stdio.h>
#include <stdlib.h>
#include "../treebalasan.h"
// #include "../../../../lib/boolean.h"
// #include "../../../../lib/charmachine/charmachine.c"
// #include "../../../../lib/wordmachine/wordmachine.c"
#include "../reply.h"

int main()
{

    Word w;
    CreateWord(&w);
    assignWord(&w, "halo", 4);

    Word isi;
    CreateWord(&isi);
    assignWord(&isi, "haloiniisi", 10);

    Balasan b;
    createBalasan(1, w, isi, &b);

    Balasan b2;
    createBalasan(2, w, isi, &b2);

    Balasan b3;
    createBalasan(3, w, isi, &b3);

    Balasan b4;
    createBalasan(4, w, isi, &b4);

    AddressTree bal;
    createTreeBalasan(&bal);

    addBalasan(&bal, b);
    // printf("%d\n", IDBALASAN(INFO(bal)));

    // AddressTree adr_b = createNewNode(b);
    addBalasan(&bal, b2);
    // printf("%d\n", IDBALASAN(INFO(LEFT(bal))));

    addBalasan(&bal, b3);

    // AddressTree adr_b4 = createNewNode(b4);
    addBalasan(&bal, b4);
    // printf("%d\n", IDBALASAN(INFO(LEFT(bal))));

    printf("%d\n", IDBALASAN(INFO(LEFT(bal))));
    printf("%d\n", IDBALASAN(INFO(RIGHT(LEFT(bal)))));
    printf("%d\n", IDBALASAN(INFO(RIGHT(RIGHT(LEFT(bal))))));


    deleteTreeBalasan(bal, 2);
    printf("%d\n", IDBALASAN(INFO(LEFT(bal))));
    printf("%d\n", IDBALASAN(INFO(RIGHT(LEFT(bal)))));
    // printf("%d\n", IDBALASAN(INFO(LEFT(bal))));

    return 0;
}


// // indent = 0
// void printBalasan(TreeBalasan t, int indent){
//     AddressTree p = t;
//     for (int i = 0; i < indent; i++){
//         // print indent
//     }
//     // print p
//     for (int i = 0; i < indent; i++){
//         // print indent
//     }
//     for (int i = 0; i < indent; i++){
//         // print indent
//     }
//     for (int i = 0; i < indent; i++){
//         // print indent
//     }
//     // manggil child
//     printBalasan(LEFT(p), indent + 1);
//     printBalasan(RIGHT(p), indent);
// }
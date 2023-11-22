#include <stdio.h>
#include "../draft.h"
#include "../liststackdraft.h"

int main(){
    ListStackDraft l;
    StackDraft sd;
    Word w = readWord(100);
    DATETIME t;
    BacaDATETIME(&t);
    Draft d;

    CreateDraft(&d, w, t);
    CreateStackDraft(&sd);
    ELMT(l,2) = sd;
    pushDraft(&ELMT(l,2),d);
    seeDraft(ELMT(l,2));
    return 0;
}
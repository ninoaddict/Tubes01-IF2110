#include "liststackdraft.h"

void CreateListStackDraft(ListStackDraft *l){
    for (int i = 0; i < MaxElListStack; i++){
        CreateStackDraft(&l->contents[i]);
    }
}
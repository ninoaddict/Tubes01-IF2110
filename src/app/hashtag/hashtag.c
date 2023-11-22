#include "hashtag.h"

void CreateHashTag(HashTag *hashtag)
{
    for (int i = 0; i < 1005293; i++)
    {
        CreateWord(&(hashtag->Buffer[i].key));
        hashtag->Buffer[i].val = NULL;
    }
}

int HashFunction(Word w)
{
    int hashRes = 0;
    int p_pow = 1;
    for (int i = 0; i < w.Length; i++)
    {
        hashRes = (hashRes + w.TabWord[i] * p_pow) % mod;
        p_pow = (p_pow * prime) % mod;
    }
    return hashRes;
}

hashAddress newHashNode(int elmt)
{
    hashAddress new = (hashAddress)malloc(sizeof(HashNode));
    new->info = elmt;
    new->next = NULL;
    return new;
}

void insertHashElement(hashAddress *node, int elmt)
{
    hashAddress new = newHashNode(elmt);
    new->next = *node;
    *node = new;
}

int findSlot(Word w, HashTag hashtag)
{
    int i = HashFunction(w);
    while (hashtag.Buffer[i].val != NULL && !isWordEqual(hashtag.Buffer[i].key, w))
    {
        printf("ada collision bos!\n");
        i = (i + 1) % mod;
    }
    return i;
}

void addHashElement(Word w, int idx, HashTag *hashtag)
{
    // int i = findSlot(w, *hashtag);
    int i = HashFunction(w);
    while (hashtag->Buffer[i].val != NULL && !isWordEqual(hashtag->Buffer[i].key, w))
    {
        printf("ada collision bos!\n");
        i = (i + 1) % mod;
    }
    insertHashElement(&(hashtag->Buffer[i].val), idx);
    hashtag->Buffer[i].key = w;
    printf("%d\n", i);
}
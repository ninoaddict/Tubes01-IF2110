#include "fyb.h"

void searchFYB(ListKicauan listkicauan, Friend friendGraph, int currIdx, ListUser listuser)
{
    MaxHeap pq;
    CreateMaxHeap(&pq);
    int len = 0;
    for (int i = 0; i < listkicauan.nEff; i++)
    {
        if ((currIdx != - 1 && isFriend(friendGraph, listkicauan.buffer[i].idAuthor, currIdx)) || listuser.listU[listkicauan.buffer[i].idAuthor].accType)
        {
            pii val;
            val.first = i;
            val.second = listkicauan.buffer[i].like;
            enqueueMaxHeap(&pq, val);
            len++;
        }
    }
    if (len == 0)
    {
        printf("Kicauan masih kosong\n\n");
    }
    else if (len < 8)
    {
        printf("\nBerikut %d kicauan dengan like tertinggi di FYB.\n\n", len);
        int cnt = 1;
        while (!isMaxHeapEmpty(pq))
        {
            pii res;
            dequeueMaxHeap(&pq, &res);
            printf("Kicauan %d: \n", cnt);
            displayKicau(listkicauan.buffer[res.first]);
            cnt++;
        }
    }
    else
    {
        printf("\nBerikut 8 kicauan dengan like tertinggi di FYB.\n\n");
        int cnt = 1;
        while (cnt <= 8)
        {
            pii res;
            dequeueMaxHeap(&pq, &res);
            printf("Kicauan %d: \n", cnt);
            displayKicau(listkicauan.buffer[res.first]);
            cnt++;
        }
    }
}
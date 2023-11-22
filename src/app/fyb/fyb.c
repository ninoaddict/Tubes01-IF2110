#include "fyb.h"

void searchFYB(ListKicauan listkicauan)
{
    MaxHeap pq;
    CreateMaxHeap(&pq);
    for (int i = 0; i < listkicauan.nEff; i++)
    {
        pii val;
        val.first = i;
        val.second = listkicauan.buffer[i].like;
        enqueueMaxHeap(&pq, val);
    }
    if (listkicauan.nEff < 8)
    {
        printf("\nBerikut %d kicauan dengan like tertinggi di FYB.\n\n", listkicauan.nEff);
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
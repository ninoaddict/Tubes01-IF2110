#include <stdio.h>
#include "../datetime.h"

int main(){
    Word arr;
    assignWord(&arr,"14/10/2023 11:09:18\n",21);
    DATETIME t;
    Word b;
    t = string_toDate_time(arr);
    TulisDATETIME(t);printf("\n");
    b = dateTimeToWord(t);
    displayWordWithoutEnter(b);

    return 0;
}
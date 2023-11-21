#include <stdio.h>
#include "../datetime.h"

int main(){
    char arr[] = "14/10/2023 01:09:18\n";
    DATETIME t;
    Word b;
    t = string_toDate_time(arr);
    TulisDATETIME(t);printf("\n");
    b = dateTimeToWord(t);
    displayWordWithoutEnter(b);

    return 0;
}
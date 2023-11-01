# include "wordmachine.h"
# include <stdlib.h>
# include <stdio.h>
# include <math.h>

boolean EndWord;
Word currentWord;

void ignoreSpace(){
    while (currentChar == SPACE || currentChar == CARRIAGE)
    {
        ADV();
    }
}

void IgnoreBlanks(){
    while (currentChar == BLANK)
    {
        ADV();
    }
    
}
/* Mengabaikan satu atau beberapa BLANK
   I.S. : currentChar sembarang
   F.S. : currentChar ≠ BLANK atau currentChar = MARK */

void STARTWORD(){
    START();
    ignoreSpace();
    IgnoreBlanks();
    if (currentChar == MARK){
        EndWord = true;
    }
    else{
        EndWord = false;
        CopyWord();
        ignoreSpace();
        IgnoreBlanks();
    }
}
/* I.S. : currentChar sembarang
   F.S. : EndWord = true, dan currentChar = MARK;
          atau EndWord = false, currentWord adalah kata yang sudah diakuisisi,
          currentChar karakter pertama sesudah karakter terakhir kata */

void ADVWORD(){
    ignoreSpace();
    IgnoreBlanks();
    if (currentChar == MARK){
        EndWord = true;
    }
    else{
        CopyWord();
        ignoreSpace();
        IgnoreBlanks();
    }
}
/* I.S. : currentChar adalah karakter pertama kata yang akan diakuisisi
   F.S. : currentWord adalah kata terakhir yang sudah diakuisisi,
          currentChar adalah karakter pertama dari kata berikutnya, mungkin MARK
          Jika currentChar = MARK, EndWord = true.
   Proses : Akuisisi kata menggunakan procedure SalinWord */

void CopyWord(){
    int i = 0;
    while (currentChar != MARK && currentChar != BLANK && currentChar != SPACE && currentChar != CARRIAGE){
        if (i < NMax){
            currentWord.TabWord[i] = currentChar;
            i++;
        }
        ADV();
    }
    currentWord.Length = i;
}

void CreateWord(Word * w){
    w->Length = 0;
}

Word readWord(int len){
    Word w;
    int cnt = 0;
    CreateWord(&w);
    START();
    ignoreSpace();
    while (!EOP)
    {
        if (cnt < len)
            w.TabWord[cnt] = currentChar;
        cnt++;
        ADV();
    }
    if (cnt > len){
        w.Length = len;
    }
    else{
        w.Length = cnt;
    }
    return w;
}

void displayWord(Word w){
    for (int i = 0; i < w.Length; i++){
        printf("%c", w.TabWord[i]);
    }
    printf("\n");
}

boolean isCharEqual(Word w1, Word w2){ // case insensitive
    if (w1.Length != w2.Length) return false;
    for (int i = 0; i < w1.Length; i++){
        if (w1.TabWord[i] >= 65 && w1.TabWord[i] <= 90) w1.TabWord[i] += 32;
        if (w2.TabWord[i] >= 65 && w2.TabWord[i] <= 90) w2.TabWord[i] += 32;
        if (w1.TabWord[i] != w2.TabWord[i]) return false;
    }
    return true;
}

boolean isWordEqual(Word w1, Word w2){ // case sensitive
    if (w1.Length != w2.Length) return false;
    for (int i = 0; i < w1.Length; i++){
        if (w1.TabWord[i] >= 65 && w1.TabWord[i] <= 90) w1.TabWord[i] += 32;
        if (w2.TabWord[i] >= 65 && w2.TabWord[i] <= 90) w2.TabWord[i] += 32;
        if (w1.TabWord[i] != w2.TabWord[i]) return false;
    }
    return true;
}
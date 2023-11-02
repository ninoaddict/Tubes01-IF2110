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

/*Fungsi untuk membaca word berdasarkan masukan dari terminal. Akan mengembalikan word dengan panjang maksimum len, yang diberikan di parameter*/
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

/*Fungsi untuk menampilkan word w diakhiri dengan spasi*/
void displayWord(Word w){
    for (int i = 0; i < w.Length; i++){
        printf("%c", w.TabWord[i]);
    }
    printf("\n");
}

/*Fungsi untuk menampilkan word w tanpa diakhiri dengan spasi*/
void displayWordWithoutEnter(Word w){
    for (int i = 0; i < w.Length; i++){
        printf("%c", w.TabWord[i]);
    }
}

/*Fungsi yang mengembalikan true jika w1 = w2 dengan case insensitive*/
boolean isCharEqual(Word w1, Word w2){ // case insensitive
    if (w1.Length != w2.Length) return false;
    for (int i = 0; i < w1.Length; i++){
        if (w1.TabWord[i] >= 65 && w1.TabWord[i] <= 90) w1.TabWord[i] += 32;
        if (w2.TabWord[i] >= 65 && w2.TabWord[i] <= 90) w2.TabWord[i] += 32;
        if (w1.TabWord[i] != w2.TabWord[i]) return false;
    }
    return true;
}

/*Fungsi yang mengembalikan true jika w1 = w2 dengan case sensitive*/
boolean isWordEqual(Word w1, Word w2){ // case sensitive
    if (w1.Length != w2.Length) return false;
    for (int i = 0; i < w1.Length; i++){
        if (w1.TabWord[i] != w2.TabWord[i]) return false;
    }
    return true;
}
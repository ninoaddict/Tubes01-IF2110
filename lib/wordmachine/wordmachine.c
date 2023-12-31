#include "wordmachine.h"
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

boolean EndWord;
Word currentWord;

void ignoreSpace()
{
    while (currentChar == SPACE || currentChar == CARRIAGE)
    {
        ADV();
    }
}

void IgnoreBlanks()
{
    while (currentChar == BLANK)
    {
        ADV();
    }
}

void STARTWORD()
{
    START();
    ignoreSpace();
    IgnoreBlanks();
    if (currentChar == MARK)
    {
        EndWord = true;
    }
    else
    {
        EndWord = false;
        CopyWord();
        ignoreSpace();
        IgnoreBlanks();
    }
}

void ADVWORD()
{
    ignoreSpace();
    IgnoreBlanks();
    if (currentChar == MARK)
    {
        EndWord = true;
    }
    else
    {
        CopyWord();
        ignoreSpace();
        IgnoreBlanks();
    }
}

void CopyWord()
{
    int i = 0;
    while (currentChar != MARK && currentChar != BLANK && currentChar != SPACE && currentChar != CARRIAGE)
    {
        if (i < NMax)
        {
            currentWord.TabWord[i++] = currentChar;
        }
        ADV();
    }
    currentWord.Length = i;
}

void CreateWord(Word *w)
{
    w->Length = 0;
}

/*Fungsi untuk membaca word berdasarkan masukan dari terminal. Akan mengembalikan word dengan panjang maksimum len, yang diberikan di parameter*/
Word readWord(int len)
{
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
    if (cnt > len)
    {
        w.Length = len;
    }
    else
    {
        w.Length = cnt;
    }
    return w;
}

/*Fungsi untuk menampilkan word w diakhiri dengan spasi*/
void displayWord(Word w)
{
    for (int i = 0; i < w.Length; i++)
    {
        printf("%c", w.TabWord[i]);
    }
    printf("\n");
}

/*Fungsi untuk menampilkan word w tanpa diakhiri dengan spasi*/
void displayWordWithoutEnter(Word w)
{
    for (int i = 0; i < w.Length; i++)
    {
        printf("%c", w.TabWord[i]);
    }
}

/*Fungsi yang mengembalikan true jika w1 = w2 dengan case insensitive*/
boolean isCharEqual(Word w1, Word w2)
{ // case insensitive
    if (w1.Length != w2.Length)
        return false;
    for (int i = 0; i < w1.Length; i++)
    {
        if (w1.TabWord[i] >= 65 && w1.TabWord[i] <= 90)
            w1.TabWord[i] += 32;
        if (w2.TabWord[i] >= 65 && w2.TabWord[i] <= 90)
            w2.TabWord[i] += 32;
        if (w1.TabWord[i] != w2.TabWord[i])
            return false;
    }
    return true;
}

/*Fungsi yang mengembalikan true jika w1 = w2 dengan case sensitive*/
boolean isWordEqual(Word w1, Word w2)
{ // case sensitive
    if (w1.Length != w2.Length)
        return false;
    for (int i = 0; i < w1.Length; i++)
    {
        if (w1.TabWord[i] != w2.TabWord[i])
            return false;
    }
    return true;
}

/*Word w sembarang*/
void assignWord(Word *w, char arr[], int len)
{
    CreateWord(w);
    for (int i = 0; i < len; i++)
    {
        w->TabWord[i] = arr[i];
    }
    w->Length = len;
}

void readCommand(Word *command)
{
    int cnt = 0;
    STARTWORD();
    while (!EndWord)
    {
        command[cnt] = currentWord;
        cnt++;
        ADVWORD();
    }
    for (int i = cnt; i < 20; i++)
    {
        command[i].Length = 0;
    }
}

int wordToInteger(Word W)
{
    int mult = 1, num = 0, i; // 300
    int end_at = 0;
    if (W.TabWord[0] == '-')
    {
        mult = -1;
        end_at = 1;
    }
    for (i = W.Length - 1; i >= end_at; i--)
    {
        num += (W.TabWord[i] - '0') * mult;
        mult *= 10;
    }
    return num;
}

boolean isAllSpace(Word w)
{
    for (int i = 0; i < w.Length; i++)
    {
        if (w.TabWord[i] != ' ' && w.TabWord[i] != '\t')
            return false;
    }
    return true;
}
void stringToWord(Word *w, char arr[])
{
    CreateWord(w);
    int i = 0;
    while (arr[i] != '\n')
    {
        w->TabWord[i] = arr[i];
        i++;
    }
    w->Length = i;
}

void wordToString(char *arr, Word w)
{
    for (int i = 0; i < w.Length; i++)
    {
        arr[i] = w.TabWord[i];
    }
}

void mergeWord(Word *w1, Word w2)
{
    for (int i = 0; i < w2.Length; i++)
    {
        w1->TabWord[i + w1->Length] = w2.TabWord[i];
    }
    w1->Length += w2.Length;
}

void splitWordAndInt(Word *w, int *number)
{
    Word numberword;
    boolean isnumber = true;
    int i = w->Length - 1;
    while (isnumber)
    {
        int check = w->TabWord[i] - '0';
        if (check < 0 || check > 9)
        {
            isnumber = false;
            i++;
        }
        else
        {
            i--;
        }
    }
    CreateWord(&numberword);
    for (int j = 0; j < w->Length - i; j++)
    {
        numberword.TabWord[j] = w->TabWord[j + i];
    }
    numberword.Length = w->Length - i;
    w->Length = w->Length-numberword.Length-1;
    *number = wordToInteger(numberword);
}

Word addNewline(Word w)
{
    w.TabWord[w.Length] = '\n';
    w.TabWord[w.Length + 1] = '\0';
    w.Length += 2;
    return w;
}

void splitInt(Word *w, int *number1, int *number2){
    Word numberword2;
    boolean isnumber = true;
    int i = w->Length - 1;
    while (isnumber){
        int check = w->TabWord[i] - '0';
        if (check<0 || check>9){
            isnumber = false;
            i++;
        } else {
            i--;
        }
    }
    CreateWord(&numberword2);
    for (int j=0;j<w->Length-i;j++){
        numberword2.TabWord[j] = w->TabWord[j+i];
    }
    numberword2.Length = w->Length-i;
    w->Length -= numberword2.Length-1;
    *number2 = wordToInteger(numberword2);
    *number1 = wordToInteger(*w);
}
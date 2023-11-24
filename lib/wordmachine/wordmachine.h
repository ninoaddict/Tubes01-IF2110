/* File: wordmachine.h */
/* Definisi Mesin Word: Model Akuisisi Versi I */

#ifndef __WORDMACHINE_H__
#define __WORDMACHINE_H__

#include "../boolean.h"
#include "../charmachine/charmachine.h"

#define NMax 1024
#define BLANK ' '
#define SPACE '\n'
#define CARRIAGE '\r'
typedef struct
{
   char TabWord[NMax]; /* container penyimpan kata, indeks yang dipakai [0..NMax-1] */
   int Length;
} Word;

/* State Mesin Word */
extern boolean EndWord;
extern Word currentWord;

void IgnoreBlanks();
/* Mengabaikan satu atau beberapa BLANK
   I.S. : currentChar sembarang
   F.S. : currentChar ≠ BLANK atau currentChar = MARK */

void STARTWORD();
/* I.S. : currentChar sembarang
   F.S. : EndWord = true, dan currentChar = MARK;
          atau EndWord = false, currentWord adalah kata yang sudah diakuisisi,
          currentChar karakter pertama sesudah karakter terakhir kata */

void ADVWORD();
/* I.S. : currentChar adalah karakter pertama kata yang akan diakuisisi
   F.S. : currentWord adalah kata terakhir yang sudah diakuisisi,
          currentChar adalah karakter pertama dari kata berikutnya, mungkin MARK
          Jika currentChar = MARK, EndWord = true.
   Proses : Akuisisi kata menggunakan procedure SalinWord */

void CopyWord();
/* Mengakuisisi kata, menyimpan dalam currentWord
   I.S. : currentChar adalah karakter pertama dari kata
   F.S. : currentWord berisi kata yang sudah diakuisisi;
          currentChar = BLANK atau currentChar = MARK;
          currentChar adalah karakter sesudah karakter terakhir yang diakuisisi.
          Jika panjang kata melebihi NMax, maka sisa kata "dipotong" */

void CreateWord(Word *w);

Word readWord(int len);

void readCommand(Word *command);

void displayWord(Word w);

void displayWordWithoutEnter(Word w);

boolean isWordEqual(Word w1, Word w2); // case sensitive
 
boolean isCharEqual(Word w1, Word w2); // case insensitive

void assignWord(Word *w, char arr[], int len);

int wordToInteger(Word w);

boolean isAllSpace(Word w);

void stringToWord(Word *w, char arr[]);

void wordToString(char *arr, Word w);

void mergeWord(Word *w1, Word w2);

void splitWordAndInt(Word *w, int *number);

Word addNewline(Word w);

#endif
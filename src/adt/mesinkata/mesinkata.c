#include "mesinkata.h"
#include <stdio.h>
#include <stdlib.h>

boolean EndWord;
Word currentWord;

/* Mengabaikan satu atau beberapa BLANK
   I.S. : currentChar sembarang
   F.S. : currentChar ≠ BLANK atau currentChar = MARK */
void IgnoreBlanks()
{
    while (currentChar == BLANK)
    {
        ADV();
    }
}

/* I.S. : currentChar sembarang
   F.S. : EndWord = true, dan currentChar = MARK;
          atau EndWord = false, currentWord adalah kata yang sudah diakuisisi,
          currentChar karakter pertama sesudah karakter terakhir kata */
void STARTWORD(char * savefile)
{
    START(savefile);
    IgnoreBlanks();
    if (currentChar == EOP)
    {
        EndWord = true;
    }
    else
    {
        EndWord = false;
        ADVWORD();
    }
}

/* I.S. : currentChar adalah karakter pertama kata yang akan diakuisisi
   F.S. : currentWord adalah kata terakhir yang sudah diakuisisi,
          currentChar adalah karakter pertama dari kata berikutnya, mungkin MARK
          Jika currentChar = MARK, EndWord = true.
   Proses : Akuisisi kata menggunakan procedure SalinWord */
void ADVWORD()
{
    if (currentChar == EOP)
    {
        EndWord = true;
    }
    else
    {
        CopyWord();
        IgnoreBlanks();
    }
}

/* Mengakuisisi kata, menyimpan dalam currentWord
   I.S. : currentChar adalah karakter pertama dari kata
   F.S. : currentWord berisi kata yang sudah diakuisisi;
          currentChar = BLANK;
          currentChar adalah karakter sesudah karakter terakhir yang diakuisisi.
          Jika panjang kata melebihi NMax, maka sisa kata "dipotong" */
void CopyWord()
{
    int i = 0;
    while ((currentChar != BLANK) && i < NMax && !EOP)
    {
        currentWord.TabWord[i] = currentChar;
        ADV();

        i += 1;
    }
    currentWord.Length = i;
}

void startInputWord() {
/*Melakukan pengisian pita oleh input user
   I.S pita kosong
   F.S pita diisi oleh user dan dilakukan pemrosesan oleh mesin kata
*/
    startInput();
    IgnoreBlanks();
    if (currentChar == EOP)
    {
        EndWord = true;
    }
    else
    {
        EndWord = false;
        CopyWord();
    }
}

boolean stringEQWord(Word w, char* c) {
/*Mengembalikan Nilai true jika string dengan tabword bernilai sama*/
    boolean eq = false;
    if (w.Length == strlength(c)) {
        eq = true;
        int i = 0;
        while (i < w.Length && eq) {
            if (w.TabWord[i] != c[i]) {
                eq = false;
            } else {
                i++;
            }
        }
    }
    
    return eq;
}

void akuisisiCommandWord(Word* w, Word command) {
/*Mengakuisisi command terkhusus untuk LOAD and SAVE
   I.S. pita kata terdefinisi
   F.S. diakuisisi ke dalam w
*/
    int i = 0;
    while (command.TabWord[i] != ' ' && i<command.Length)
    {
        w->TabWord[i] = command.TabWord[i];
        i++;
    }
    w->Length = i;
}

char* akuisisiFile(Word command) {
/*Mengakuisisi nama file yang dimasukkan dari command user*/
    int i=0;
    while (command.TabWord[i] != ' ') {
        i++;
    }
    i++;

    char* ret = malloc( (command.Length-i+2) * sizeof(char));
    char* p = ret;

    while (i < command.Length) {
        *p++ = command.TabWord[i];
        i++;
    }
    *p = '\0';

    return ret;
}
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
    while (currentChar == BLANK && !EOP)
    {
        ADV();
    }
}

/* I.S. : currentChar sembarang
   F.S. : EndWord = true, dan currentChar = MARK;
          atau EndWord = false, currentWord adalah kata yang sudah diakuisisi,
          currentChar karakter pertama sesudah karakter terakhir kata */
void STARTWORD(char *savefile)
{
    START(savefile);
    IgnoreBlanks();
    if (EOP)
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
    if (EOP)
    {
        EndWord = true;
    }
    else
    {
        UpdateCurrentWord();
        IgnoreBlanks();
    }
}

/* Mengakuisisi kata, menyimpan dalam currentWord
   I.S. : currentChar adalah karakter pertama dari kata
   F.S. : currentWord berisi kata yang sudah diakuisisi;
          currentChar = BLANK;
          currentChar adalah karakter sesudah karakter terakhir yang diakuisisi.
          Jika panjang kata melebihi NMax, maka sisa kata "dipotong" */
void UpdateCurrentWord()
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

void startInputWord()
{
    /*Melakukan pengisian pita oleh input user
       I.S pita kosong
       F.S pita diisi oleh user dan dilakukan pemrosesan oleh mesin kata
    */
    startInput();
    IgnoreBlanks();
    if (EOP)
    {
        EndWord = true;
    }
    else
    {
        EndWord = false;
        UpdateCurrentWord();
    }
}

boolean stringEQWord(Word w, char *c)
{
    /*Mengembalikan Nilai true jika string dengan tabword bernilai sama*/
    boolean eq = false;
    if (w.Length == panjangKata(c))
    {
        eq = true;
        int i = 0;
        while (i < w.Length && eq)
        {
            if (w.TabWord[i] != c[i])
            {
                eq = false;
            }
            else
            {
                i++;
            }
        }
    }

    return eq;
}

void akuisisiCommandWord(Word *w, Word command, int kataKe)
{
    /*Mengakuisisi command terkhusus untuk LOAD and SAVE
       I.S. pita kata terdefinisi
       F.S. diakuisisi ke dalam w
    */
    int i = 0, counter = 0, length = 0;
    boolean stop = false;

    while (counter != kataKe - 1 && i < command.Length)
    {
        if (command.TabWord[i] == ' ')
        {
            counter++;
        }

        i++;
        if (i == command.Length)
        {
            counter++;
        }
    }

    while (!stop && i < command.Length)
    {
        if (command.TabWord[i] == ' ')
        {
            stop = true;
        }
        else
        {
            w->TabWord[length] = command.TabWord[i];
            i++;
            length++;
        }
    }
    w->Length = length;
}

char *akuisisiFile(Word command)
{
    /*Mengakuisisi nama file yang dimasukkan dari command user*/
    int i = 0;
    while (command.TabWord[i] != ' ')
    {
        i++;
    }
    i++;

    char *ret = malloc((command.Length - i + 2) * sizeof(char));
    char *p = ret;

    while (i < command.Length)
    {
        *p++ = command.TabWord[i];
        i++;
    }
    *p = '\0';

    return ret;
}

int wordToInt(Word w)
{
    /*
     I.S word terdefinisi
     F.S dirubah ke integer dan dimasukkan ke dalan integer
    */
    int val = 0;
    int i;
    for (i = 0; i < w.Length; i++)
    {
        val = val * 10 + (w.TabWord[i] - 48);
    }

    return val;
}

void printWord(Word w)
{
    /*
     I.S word terdefinisi
     F.S menampilkan word
    */
    int i;
    for (i = 0; i < w.Length; i++)
    {
        printf("%c", w.TabWord[i]);
    }
}

Word stringToWord(char string[100])
{
    Word w;

    int i;
    for (i = 0; i < panjangKata(string); i++)
    {
        w.TabWord[i] = string[i];
    }
    w.Length = panjangKata(string);

    return w;
}
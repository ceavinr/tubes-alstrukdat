#include "mesinkata.h"
#include <stdio.h>
#include <stdlib.h>

boolean EndWord;
Word currentWord;

/* Mengabaikan satu atau beberapa BLANK
   I.S. : currentChar sembarang
   F.S. : currentChar ≠ BLANK ('\n') dan currentChar != EOP */
void IgnoreBlanks()
{
    while (currentChar == BLANK && !EOP)
    {
        ADV();
    }
}

/* I.S. : currentChar sembarang
   F.S. : EndWord = true, dan EOP;
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
          Jika EOP, EndWord = true.
   Proses : Akuisisi kata menggunakan procedure UpdateCurrentWord */
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
          currentChar = BLANK ('\n');
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

/*Melakukan pengisian pita oleh input user
    I.S pita kosong
    F.S pita diisi oleh user dan dilakukan pemrosesan oleh mesin kata
*/
void startInputWord()
{
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

/* Mengakuisisi kata  ke- pada sebuah command
    I.S pita tidak kosong
    F.S kata ke- diakuisi dan disimpan ke dalam w
*/
void akuisisiCommandWord(Word *w, Word command, int kataKe)
{
    /*Mengakuisisi command terkhusus untuk LOAD and SAVE
       I.S. pita kata terdefinisi
       F.S. diakuisisi ke dalam w
    */
    int i = 0, counter = 0, length = 0;
    boolean stop;

    while (counter != kataKe - 1 && i < command.Length)
    {
        stop = false;
        if (command.TabWord[i] == ' ')
        {
            counter++;
            while (i < command.Length && !stop)
            {
                i++;
                if (command.TabWord[i] != ' ')
                {
                    stop = true;
                }
            }
        }
        else
        {
            i++;
        }

        if (i == command.Length)
        {
            counter++;
        }
    }

    stop = false;
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

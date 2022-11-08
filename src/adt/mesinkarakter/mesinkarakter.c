#include <stdio.h>
#include "mesinkarakter.h"

char currentChar;
boolean EOP;

static FILE *pita;
static int retval;

/* Mesin siap dioperasikan. Pita disiapkan untuk dibaca.
   Karakter pertama yang ada pada pita posisinya adalah pada jendela.
   Pita baca diambil dari sebuah file.
   I.S. : sembarang
   F.S. : currentChar adalah karakter pertama pada pita */
void START(char *savefile)
{
    pita = fopen(savefile, "r");
    ADV();
}

/* Pita dimajukan satu karakter.
       I.S. : Karakter pada jendela = currentChar, currentChar != feof
       F.S. : currentChar adalah karakter berikutnya dari currentChar yang lama,
              Jika  pita kosong EOP akan menyala (true) */
void ADV()
{
    if (pita == NULL) // jika file tidak tersedia
    {
        EOP = true;
        printf("File tidak tersedia! Pastikan benar!\n");
    } else {
        retval = fscanf(pita, "%c", &currentChar);

        EOP = (feof(pita));
        if (EOP)
        {
            fclose(pita);
        }
    }
}

/*
    Mengirimkan currentChar
*/
char GetCC()
{ 
    return currentChar;
}

/* 
    Mengirimkan true jika currentChar = MARK
*/
boolean IsEOP()
{
    return EOP;
}

/* Mesin siap dioperasikan. Pita disiapkan untuk dibaca.
   Karakter pertama yang ada pada pita posisinya adalah pada jendela.
   Pita baca diambil dari sebuah stdin.
   I.S. : sembarang
   F.S. : currentChar adalah karakter pertama pada pita */
void startInput()
{
    pita = stdin;
    ADV();
}
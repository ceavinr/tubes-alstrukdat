#include <stdio.h>
#include <time.h>
#include "../../adt/mesin/mesinkarakter.h"
#include "../../adt/mesin/mesinkata.h"
#include "../../adt/arraydin/arraydin.h"
#include "../../adt/word/word.h"
#include "../../adt/string/string.h"

char* kata_random()
{
    int x, total, count;
    ArrayDin arrKata;

    arrKata = MakeArrayDin();
    STARTWORD("kata.txt");

    if (!EOP)
    {
        count = wordToInt(currentWord);
        int i;
        for (i = 0; i < count; i++)
        {
            ADVWORD();
            InsertAt(&arrKata, currentWord, i);
        }
        ADVWORD();
    }

    total = count + 1;
    srand(time(NULL));
    x = rand() % total;

    printf("%d\n", x);
    int j;
    char* kata = malloc (sizeof (char) * BUFFER(arrKata)[x].Length);
    for (j = 0; j < BUFFER(arrKata)[x].Length; j++)
    {
        kata[j] = BUFFER(arrKata)[x].TabWord[j];
    }
    
    return kata;
}




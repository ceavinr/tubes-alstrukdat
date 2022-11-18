#include <stdio.h>
#include <time.h>
#include "../../adt/mesin/mesinkarakter.c"
#include "../../adt/mesin/mesinkata.c"
#include "../../adt/arraydin/arraydin.c"
#include "../../adt/word/word.c"
#include "../../adt/string/string.c"

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
    char* kata = malloc (sizeof (char) * BUFFER(arrKata)[x].Length+1);
    for (j = 0; j < BUFFER(arrKata)[x].Length; j++)
    {
        kata[j] = BUFFER(arrKata)[x].TabWord[j];
    }
    kata[BUFFER(arrKata)[x].Length] = '\0';
    
    return kata;
}




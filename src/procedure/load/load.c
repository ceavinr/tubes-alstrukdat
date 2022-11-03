#include "load.h"

void load(char *savefile, ArrayDin *arr)
{
    STARTWORD(savefile);
    if (!EOP)
    {
        int count;
        wordToInt(currentWord, &count);
        int i;
        for (i = 0; i < count; i++)
        {
            ADVWORD();
            InsertAt(arr, currentWord, i);
        }
        ADVWORD();
    }
}

// TESTER
// int main() {
//     ArrayDin game;
//     ArrayDin history;
//     load("../../../data/savefile1.txt", &game, &history);
//     DeleteAt(&game, 1);
//     ReverseArrayDin(&game);
//     PrintArrayDin(game);
//     PrintArrayDin(history);
// }

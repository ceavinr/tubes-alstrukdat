#include "load.h"

void load(char *savefile, ArrayDin *arrGame, ArrayDin *arrHistory)
{
    *arrGame = MakeArrayDin();
    *arrHistory = MakeArrayDin();
    STARTWORD(savefile);
    if (!EOP)
    {
        int count;
        wordToInt(currentWord, &count);
        int i;
        for (i = 0; i < count; i++)
        {
            ADVWORD();
            InsertAt(arrGame, currentWord, i);
        }
        ADVWORD();
    }
    if (!EOP)
    {
        int count;
        wordToInt(currentWord, &count);
        int j;
        for (j = 0; j < count; j++)
        {
            ADVWORD();
            InsertAt(arrHistory, currentWord, j);
        }
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

#include "mesinkata.h"
#include <stdio.h>

int main()
{
    Word masakan, command;
    startInputWord();
    akuisisiCommandWord(&command, currentWord, 1);
    akuisisiCommandWord(&masakan, currentWord, 2);
    printWord(command);
    printWord(masakan);
}
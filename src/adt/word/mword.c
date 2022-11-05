#include "word.h"
#include "../mesinkata/mesinkata.h"

int main()
{
    Word w;
    char *wString;

    startInputWord();

    akuisisiCommandWord(&w, currentWord, 2);

    wString = wordToString(w);
    printf("%s\n", wString);

    return 0;
}
#include "kata.h"

int panjangKata(char *a)
{
    int i = 0;
    while (a[i] != '\0')
    {
        i++;
    };

    return i;
};

boolean isSame(char a[], char b[])
{
    boolean same = true;
    int i = 0;
    while (a[i] != '\0' && b[i] != '\0')
    {
        if (a[i] != b[i])
        {
            same = false;
            break;
        }
        i++;
    }
    return same;
}
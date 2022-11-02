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

int strlength(char* string) {
/*Mengembalikan panjang string*/
    int length = 0;
    while (*string != '\0') {
        length++;
        *string++;
    }
    return length;
}

char* concat(char* s1, char* s2) {
/*Mengembalikan string berupa gabungan dari s1 dan s2*/
    char* ret = malloc((strlength(s1) + strlength(s2) + 1) * sizeof(char));
    char* p = ret;
    while (*s1 != '\0') {
        *p++ = *s1++;
    }
    while (*s2 != '\0') {
        *p++ = *s2++;
    }
    *p = '\0';
    return ret;
}
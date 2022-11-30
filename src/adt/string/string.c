#include "string.h"

int stringLength(string s)
{
    int i = 0;
    while (s[i] != '\0')
    {
        i++;
    };

    return i;
};

string concat(string s1, string s2)
{
    string ret = malloc((stringLength(s1) + stringLength(s2) + 1) * sizeof(char));
    string p = ret;
    while (*s1 != '\0')
    {
        *p++ = *s1++;
    }
    while (*s2 != '\0')
    {
        *p++ = *s2++;
    }
    *p = '\0';
    return ret;
}

string copyString(string s2)
{
    string s1 = malloc((stringLength(s2) + 1) * sizeof(char));
    string p = s1;
    while (*s2 != '\0')
    {
        *p++ = *s2++;
    }
    *p = '\0';

    return s1;
}
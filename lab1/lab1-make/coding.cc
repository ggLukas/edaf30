#include <coding.h>
#include <iostream>

unsigned char encode(unsigned char c)
{
    if ((c > 64 && c < 91) || (c > 96 && c < 123))
        c++;
    if (c == 91)
        c = 65;
    return c;
}
unsigned char decode(unsigned char c)
{
    if ((c > 64 && c < 91) || (c > 96 && c < 123))
        c--;
    if (c == 96)
        c = 122;
    return c;
}

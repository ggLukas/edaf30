#include <coding.h>
#include <iostream>
#include <fstream>

unsigned char encode(unsigned char c)
{
    if ((c > 31 && c < 127))
        c++;
    if (c == 127)
        c = 32;
    return c;
}
unsigned char decode(unsigned char c)
{
    if ((c > 31 && c < 127))
        c--;
    if (c == 31)
        c = 126;
    return c;
}

void code_file(std::string infile, std::string outfile, bool encoded)
{
    std::ifstream in{infile};
    std::ofstream out{outfile};

    int c;
    while ((c = in.get()) != EOF)
    {
        if (encoded)
            out << decode(static_cast<char>(c));
        else
            out << encode(static_cast<char>(c));
    }
}

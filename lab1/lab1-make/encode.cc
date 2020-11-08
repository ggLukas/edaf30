#include "coding.h"
#include <iostream>
#include <fstream>

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

int main(int argc, char **argv)
{
    if (argc > 3)
    {
        code_file(argv[1], argv[2], false);
        code_file(argv[2], argv[3], true);
    }

    return 0;
}
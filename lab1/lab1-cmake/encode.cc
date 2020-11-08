#include "libs/coding.h"
#include "config.h"
#include <iostream>
#include <fstream>

int main(int argc, char **argv)
{
    std::cout << VERSION_MAJOR << "." << VERSION_MINOR << std::endl;
    if (argc > 3)
    {
        code_file(argv[1], argv[2], false);
        code_file(argv[2], argv[3], true);
    }

    return 0;
}
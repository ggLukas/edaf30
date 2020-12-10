#include "date.h"
#include <iostream>
#include <sstream>

template <typename T>
 T string_cast(std::string s)
{
    s = std::__cxx11::stoi(s);
}

int main()
{
    try
    {
        int i = string_cast<int>("123");
        std::cout << i << std::endl;
        double d = string_cast<double>("12.34");
        Date date = string_cast<Date>("2015-01-10");
    }
    catch (std::invalid_argument &e)
    {
        std::cout << "Error: " << e.what() << std::endl;
    }
}
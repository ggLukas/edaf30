#include "date.h"
#include <iostream>
#include <ostream>
#include <sstream>
#include <stdexcept>

template <typename T>
T string_cast(std::string s)
{
    std::stringstream ss{};
    ss << s;
    T t;
    ss >> t;
    if (ss.fail())
    {
        throw std::invalid_argument("Invalid syntax.");
    }
    return t;
}

int main()
{
    try
    {
        int i = string_cast<int>("123");
        std::cout << i << std::endl;
        double d = string_cast<double>("12.34");
        std::cout << d << std::endl;
        Date date = string_cast<Date>("2015-01-10");
        std::cout << date << std::endl;
        Date dummy = string_cast<Date>("aserdfgh");
        std::cout << dummy << std::endl;
    }
    catch (std::invalid_argument &e)
    {
        std::cout << "Error: " << e.what() << std::endl;
    }
}
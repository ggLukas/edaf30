#include "date.h"
#include <iostream>
#include <sstream>

template<typename T> 
std::string toString(T &t){
    std::stringstream ss{};
    ss << t;
    return ss.str();
}

int main(){
    double d = 1.234;
    Date today;
    std::string sd = toString(d);
    std::string st = toString(today);
    std::cout << sd << std::endl;
    std::cout << st << std::endl; 
}
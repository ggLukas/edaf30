#include <iostream>

class Dummy
{
public:
    Dummy(const std::string &t) : text(t) {}

private:
    std::string text;
};

int main()
{
    Dummy dum("1");
    delete(&dum);
}
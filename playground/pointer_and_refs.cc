#include <iostream>
using std::cout;

void print(int *p)
{
    cout << "the value pointed to is " << *p << "\n";
}

void print(int &r)
{
    cout << "the reference object has value " << r << "\n";
}

void printAddress(int *p)
{
    cout << "the pointer points to address " << p << "\n";
}

void printAddress(int &r)
{
    cout << "the reference object has address " << &r << "\n";
}

int main()
{
    int x = 44;
    print(&x);
    print(x);
    
    printAddress(&x);
    printAddress(x);
    return 0;
}
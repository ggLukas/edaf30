#include <iostream>
using std::cout;
using std::endl;

void swap(int &x, int &y)
{
    int tmp = x;
    x = y;
    y = tmp;
}

void assign(int &x, const int &y)
{
    x = y;
}

int main()
{
    int a = 17;
    int b = 42;

    cout << "a: " << a << ", b: " << b << endl;
    swap(a, b);
    cout << "a: " << a << ", b: " << b << endl;
    assign(a, 100);
    cout << "a: " << a << ", b: " << b << endl;

    cout << "size of integer is: " << sizeof(a) << endl;
    int *p;
    cout << "size of pointer is: " << sizeof(p) << endl;
    int& r = a;
    cout << "size of reference is: " << sizeof(r) << endl;
    cout << "integer value: " << r << endl;
}

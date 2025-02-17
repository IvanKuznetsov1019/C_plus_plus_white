#include <iostream>
using namespace std;

void UpdateIfGreater(int, int&);

int main()
{
    int a, b;
    cin >> a >> b;
    UpdateIfGreater(a, b);
    cout << a << " " << b;
    return 0;
}

void UpdateIfGreater(int first, int& second)
{
    if(first>second) 
    {
        second = first;
    }
}
#include <iostream>
using namespace std;

int main()
{
    int a, b;
    cin >> a >> b;
    if(a % 2 != 0) a++;
    while(a<=b)
    {
        cout << a << " ";
        a += 2;
    }
    return 0;
}
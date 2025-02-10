#include <iostream>
using namespace std;

int main()
{
    int a, b;
    int r=-1;
    cin >> a >> b;
    
    if(a<b)
    {
        a=a^b;
        b=a^b;
        a=a^b;
    }
    
    while(r != 1 && r != 0)
    {
        r = a % b;
        a = b;
        b = r;
    }
    
    r == 0? cout << a: cout << r;
    
    return 0;
}
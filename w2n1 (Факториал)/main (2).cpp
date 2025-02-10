#include <iostream>
using namespace std;

int Factorial(int n)
{
    if(n<0) return -1;
    if(n==0) return 1;
    for(int i = n-1; i>1; i--)
    {
        n*=i;
    }
    return n;
}

int main()
{
    int a;
    cin >> a;
    cout << Factorial(a);
    return 0;
}
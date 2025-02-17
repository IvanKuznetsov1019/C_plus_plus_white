#include <iostream>
#include <string>
using namespace std;

int main()
{
    int n;
    int i=0;
    string s = "";
    cin >> n;
    while(n>0)
    {
        s[i] = (n%2) + 0x30;
        i++;
        n=n/2;
    }
    i--;
    while(i>=0)
    {
        cout<<s[i];
        i--;
    }
    
    return 0;
}
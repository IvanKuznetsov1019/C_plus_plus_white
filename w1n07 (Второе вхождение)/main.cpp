#include <iostream>
#include <string>
using namespace std;

int main()
{
    int n=-2;
    string str;
    cin >> str;
    for(int i = 0; i < str.size(); i++)
    {
        if(str[i]=='f')
        {
            n++;
            if(n==0) 
            {
                n=i;
                break;
            }
        }
    }
    cout << n;
    return 0;
}
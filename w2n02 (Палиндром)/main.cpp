#include <iostream>
#include <string>
using namespace std;

bool IsPalindrom(string str)
{
   for(int i=0; i<(str.size())/2; i++)
   {
       if(str[i]!=str[str.size()-i-1]) return false;
   }
   return true;
}

int main()
{
    string s;
    cin >> s;
    cout << IsPalindrom(s);
    return 0;
}
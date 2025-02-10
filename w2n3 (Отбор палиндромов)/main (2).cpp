#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector <string> PalindromFilter(vector <string> words, int minLenght)
{
    vector <string> ans;
    bool isPalindrom=1;
    for(int i=0; i<words.size(); i++)
    {
        if(words[i].size()>=minLenght)
        {
            for(int j=0; j<(words[i].size())/2; j++)
            {
                if(words[i][j]!=words[i][words[i].size()-1-j]) 
                {
                    isPalindrom=0;
                    break;
                }
            }
            if(isPalindrom) ans.push_back(words[i]);
            else isPalindrom=1;
        }
    }
   return ans;
}

int main()
{
    vector <string> v = {"abacaba", "aba", "weew", "121", "1212", "++c++", "12344331"};
    vector <string> answer;
    answer = PalindromFilter(v, 4);
    for(int i=0; i<answer.size(); i++) cout << answer[i] << endl;
    return 0;
}
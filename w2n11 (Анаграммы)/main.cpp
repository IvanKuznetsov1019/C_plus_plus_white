#include <iostream>
#include <vector>
#include <string>
#include <map>
using namespace std;

map <char, int> MapCreate (string str)
{
    map <char, int> result;
    for(char c : str)
    {
        result[c]+=1;
    }
    return result;
}

int main()
{
    int n;
    string word1, word2;
    cin >> n;
    vector <bool> answer(n);
    for(int i=0; i<n; i++)
    {
        cin >> word1 >> word2;
        if(MapCreate(word1)==MapCreate(word2))
        {
            answer[i]=true;
        }
        else
        {
            answer[i]=false;
        }
    }
    for(bool b : answer)
    {
        if(b) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    return 0;
}
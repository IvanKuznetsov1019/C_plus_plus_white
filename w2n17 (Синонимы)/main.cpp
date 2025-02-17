#include <iostream>
#include <map>
#include <string>
#include <set>

using namespace std;

int main()
{
    map<string, set<string>> synonyms;
    int q;
    cin >> q;
    string word1, word2;
    for (int i = 0; i < q; i++){
        cin >> word1;
        if (word1 == "ADD"){
            cin >> word1 >> word2;
            synonyms[word1].insert(word2);
            synonyms[word2].insert(word1);
        }
        else if (word1 == "COUNT"){
            cin >> word1;
            cout << synonyms[word1].size() << endl;
        }
        else if (word1 == "CHECK"){
            cin >> word1 >> word2;
            if (synonyms[word1].count(word2)){
                cout << "YES" << endl;
            }
            else{
                cout << "NO" << endl;
            }
        }
    }
    return 0;
}
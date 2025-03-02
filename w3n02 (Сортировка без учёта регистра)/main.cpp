#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cctype>

using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<string> v(n);
    for(int i = 0; i< n; i++)
    {
        cin >> v[i];
    }

    sort(begin(v), end(v), [](const string& first_string, const string& second_string){
        return lexicographical_compare(begin(first_string), end(first_string),
        begin(second_string), end(second_string), [](char first_simbol, char second_simbol){
            return tolower(first_simbol) < tolower(second_simbol);
        });
    });
    
    for(int i = 0; i< n; i++)
    {
        cout << v[i] << " ";
    }
    return 0;
}
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class SortedStrings
{
public:
    void AddString(const string &);
    vector<string> GetSortedStrings();

private:
    void StringSort(vector<string> &);
    vector<string> data;
};

void SortedStrings::AddString(const string &s)
{
    data.push_back(s);
    StringSort(data);
}

vector<string> SortedStrings::GetSortedStrings()
{
    return data;
}

void SortedStrings::StringSort(vector<string> &v)
{
    sort(v.begin(), v.end());
}

int main()
{
    SortedStrings s_str;
    s_str.AddString("444");
    s_str.AddString("cat");
    s_str.AddString("111");
    s_str.AddString("333");
    s_str.AddString("222");
    
    for(auto v : s_str.GetSortedStrings()){
        cout << v << endl;
    }
    
    return 0;
}
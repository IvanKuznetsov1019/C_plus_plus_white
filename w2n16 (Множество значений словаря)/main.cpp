#include <iostream>
#include <string>
#include <set>
#include<map>

using namespace std;

set<string> BuildMapValuesSet(const map<int, string>& m)
{
    set<string> values_set;
    for(auto v : m){
        if(!values_set.count(v.second)){
            values_set.insert(v.second);
        }
    }
    return values_set;
}

int main()
{
    map<int, string> data;
    data = 
    {
      {1,"one"},
      {2,"two"},
      {3,"one"},
      {4,"343"},
      {5,"111222"},
      {6,"3434"},
      {7,"343"},
      {8,"dog"},
      {9,"cat"},
      {0,"dog"}
    };
    set<string> set_of_map_values = BuildMapValuesSet(data);
    for(auto value : set_of_map_values){
        cout << value << endl;
    }
    return 0;
}
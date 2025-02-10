#include <iostream>
#include <vector>
#include <string>
using namespace std;

void Reverse (vector <string>& v)
{
    vector <string> v1;
    for(string s : v) v1.push_back(s);
    v.clear();
    string s;
    for(int i = v1.size()-1; i>=0; i--) s=v1[i], v.push_back(s);
}

int main()
{
    vector <string> a ={"1", "22", "333", "4444"};
    Reverse(a);
    for(int i=0; i<a.size(); i++) cout << a[i] << endl;
    return 0;
}

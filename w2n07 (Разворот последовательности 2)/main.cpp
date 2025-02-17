#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector <string> Reversed(const vector <string>& v)
{
    vector <string> ans;
    for(int i = v.size()-1; i>=0; i--) ans.push_back(v[i]);
    return ans;
}

int main()
{
    vector <string> a ={"1", "22", "333", "4444", "55555"};
    a=Reversed(a);
    for(int i=0; i<a.size(); i++) cout << a[i] << endl;
    return 0;
}

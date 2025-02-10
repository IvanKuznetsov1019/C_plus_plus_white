#include <iostream>
#include <vector>
#include <string>
using namespace std;

void MoveStrings (vector <string>& source, vector <string>& destination)
{
    for(string s : source) destination.push_back(s);
    source.clear();
}

int main()
{
    vector <string> a ={"1", "22", "333", "4444"};
    vector <string> b ={"aaaa", "bbb", "cc", "d"};
    MoveStrings(a, b);
    cout << "=====================" << endl;
    for(int i=0; i<b.size(); i++) cout << b[i] << endl;
    cout << "=====================" << endl;
    for(int i=0; i<a.size(); i++) cout << a[i] << endl;
    cout << "=====================" << endl;
    return 0;
}

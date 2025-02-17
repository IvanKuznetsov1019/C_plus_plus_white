#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n;
    float avTemp=0.0f;
    cin >> n;
    vector <int> temp(n);
    vector <int> indexes;
    for(int i=0; i<n; i++) cin >> temp[i], avTemp+=temp[i];
    avTemp=avTemp/n;
    for(int i=0; i<n; i++)
    {
        if(temp[i]>avTemp)
        {
            indexes.push_back(i);
        }
    }
    cout<<indexes.size()<<endl;
    for(int i : indexes) cout << i << " ";
    return 0;
}

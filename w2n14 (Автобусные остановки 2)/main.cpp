#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;

int main()
{
    map <vector <string>, int> buses;
    int q;
    int busNumber=1;
    cin >> q;
    for(int i=0; i<q; i++)
    {
        int n;
        cin >> n;
        vector <string> route(n);
        for(int j=0; j<n; j++)
        {
            cin >> route[j];
        }
        if(buses.count(route)==0)
        {
            buses[route]=busNumber;
            cout << "New bus " << busNumber << endl;;
            busNumber++;
        }
        else
        {
            cout << "Already exists for " << buses[route] << endl;
        }
        
    }
    return 0;
}
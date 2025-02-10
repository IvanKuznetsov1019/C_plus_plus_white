#include <iostream>
#include <set>
#include <map>
#include <string>

using namespace std;

int main()
{
    int q;
    cin >> q;
    int bus_number = 1;
    map<set<string>, int> routes_list;
    for(int i = 0; i < q; i++){
        int n;
        cin >> n;
        string stop_name;
        set<string> stops_list;
        for(int j=0; j<n; j++){
            cin >> stop_name;
            stops_list.insert(stop_name);
        }
        if(routes_list.count(stops_list)==0){
            routes_list[stops_list] = bus_number;
            cout << "New bus " << bus_number++ << endl;
        }
        else{
            cout << "Already exists for " << routes_list[stops_list] << endl;
        }
    }
    return 0;
}
#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;

void VectorPrint (vector <string> stopsOrBuses, string ex)
{
    for(int i=0; i<stopsOrBuses.size(); i++)
    {
        if(stopsOrBuses[i]!=ex)
        {
            cout << stopsOrBuses[i] << " ";
        }
    }
}

int main()
{
    map <string, vector <string>>stations;
    map <string, vector <string>> buses;
    int n;
    cin >> n;
    for(int i=0; i<n; i++)
    {
        string command;
        cin >> command;
        if(command=="NEW_BUS")
        {
            string busName;
            cin >> busName;
            int stopsCount;
            cin >> stopsCount;
            vector <string> stops(stopsCount);
            for(int i=0; i<stopsCount; i++)
            {
                cin >> stops[i];
            }
            buses[busName]=stops;
            for(int i=0; i<stopsCount; i++)
            {
                stations[stops[i]].push_back(busName);
            }
        }
        else if(command=="BUSES_FOR_STOP")
        {
            string stop;
            cin >> stop;
            if(stations.count(stop)==0)
            {
                cout << "No stop" << endl;
            }
            else
            {
                cout << "Stop " << stop << ": ";
                VectorPrint(stations[stop], "-");
                cout << endl;
            }
        }
        else if(command=="STOPS_FOR_BUS")
        {
            string bus;
            vector <string> currentBus;
            cin >> bus;
            if(buses.count(bus)==0)
            {
                cout << "No bus" << endl;
            }
            else
            {
                currentBus.push_back(bus);
                vector <string> stops = buses[bus];
                for(int i=0; i<stops.size(); i++)
                {
                    cout << "Stop " << stops[i] << ": ";
                    if(stations[stops[i]]==currentBus)
                    {
                        cout << "no interchange" << endl;
                    }
                    else
                    {
                        VectorPrint(stations[stops[i]], bus);
                        cout << endl;
                    }
                }
            }
        }
        else if(command=="ALL_BUSES")
        {
            if(buses.size()==0)
            {
                cout << "No buses" << endl;
            }
            else
            {
                for(auto route : buses)
                {   
                    cout << "Bus " << route.first << ": ";
                    VectorPrint(route.second, "-");
                    cout << endl;
                }
            }
        }
    }
    return 0;
}
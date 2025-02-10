#include <iostream>
#include <string>
#include <map>
using namespace std;

void ChangeCapital(map <string, string>& data, string country, string new_capital)
{
    if(data.count(country)==0)
    {
        cout << "Introduce new country " << country << " with capital " << new_capital << endl;
        data[country]=new_capital;
    }
    else if (data[country]==new_capital)
    {
        cout << "Country " << country << " hasn't changed its capital" << endl;
    }
    else
    {
        cout << "Country " << country << " has changed its capital from " << data[country]
        << " to "<< new_capital << endl;
        data[country]=new_capital;
    }
}

void Rename(map <string, string>& data, string old_country, string new_country)
{
    if(data.count(old_country)==0 || data.count(new_country)!=0 || old_country==new_country)
    {
        cout << "Incorrect rename, skip" << endl;
    }
    else
    {
        cout << "Country " << old_country << " with capital " << data[old_country] 
        << " has been renamed to " << new_country << endl;
        data[new_country]=data[old_country];
        data.erase(old_country);
    }
}

void About(map <string, string>& data, string country)
{
    if(data.count(country)==0)
    {
        cout << "Country " << country << " doesn't exist" << endl;
    }
    else
    {
        cout << "Country " << country << " has capital " << data[country] << endl;
    }
}

void Dump(map <string, string>& data)
{
    if(data.size()!=0)
    {
        for(auto item : data)
        {
            cout << item.first << '/' << item.second << " ";
        }
        cout << endl;
    }
    else
    {
        cout << "There are no countries in the world" << endl;
    }
}


int main()
{
    int n;
    string command;
    map <string, string> info;
    cin >> n;
    for(int i=0; i<n; i++)
    {
        cin >> command;
        if(command=="CHANGE_CAPITAL")
        {
            string country, new_capital;
            cin>>country>>new_capital;
            ChangeCapital(info, country, new_capital);
            
        }
        else if(command=="RENAME")
        {
            string old_country, new_country;
            cin>>old_country>>new_country;
            Rename(info, old_country, new_country);
        }
        else if(command=="ABOUT")
        {
            string country;
            cin>>country;
            About(info, country);
        }
        else if(command=="DUMP")
        {
            Dump(info);
        }
        
    }
    return 0;
}
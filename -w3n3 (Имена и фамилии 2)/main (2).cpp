#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

class Person{
    public:
    
    void ChangeFirstName(int year, const string& f_name){
        first_name[year] = f_name;
    }
    
    void ChangeLastName(int year, const string& l_name){
        last_name[year] = l_name;
    }
    
    string GetFullNameWithHistory(int year){
        int l_name_year = -1, f_name_year = -1;
        l_name_year = GetChangeYear(year, last_name);
        f_name_year = GetChangeYear(year, first_name);
        
        vector<string> first_name_history;
        vector<string> last_name_history;
        
        for(auto n : first_name){
            if(n.first < f_name_year){
                first_name_history.push_back(n.second);
            }
            else{
                break;
            }
        }
        
        for(auto n : last_name){
            if(n.first < l_name_year){
                last_name_history.push_back(n.second);
            }
            else{
                break;
            }
        }
        
        string s = "";
        
        if(last_name_history.size()>0 && first_name_history.size()>0)
        {
            s+=first_name[f_name_year];
            s+=" (";
            for(auto n : first_name_history)
            {
                s+=n;
                s+=", ";
            }
            s.pop_back();
            s.pop_back();
            s+=") ";
            s+=last_name[l_name_year];
            s+=" (";
            for(auto n : last_name_history)
            {
                s+=n;
                s+=", ";
            }
            s.pop_back();
            s.pop_back();
            s+=")";
        } else if(last_name_history.size()==0 && first_name_history.size()==0){
            s = GetFullName(year);
        }
        
        /* else if (last_name_history.size()==0 && first_name_history.size()>0){
            
        } else {
            
        }*/
        
        
        // И тут я понял, что этот код уже не спасти.
        // Не уверен, что есть смысл доделывать этот запутаннй клубок,
        // наверно лучше попробую переписать с начала
        return s;
    }
    
    string GetFullName(int year){
        int l_name_year = -1, f_name_year = -1;
        
        l_name_year = GetChangeYear(year, last_name);
        f_name_year = GetChangeYear(year, first_name);
        
        string l_name = l_name_year == (-1) ? "" : last_name[l_name_year];
        string f_name = f_name_year == (-1) ? "" : first_name[f_name_year];
        
        return GetTextForOutput(l_name, f_name);
    }
    
    private:
    
    int GetChangeYear (int year, map<int, string>name){
        int year_of_name_change = -1;
        for(auto n : name){
            if(n.first <= year){
                year_of_name_change = n.first;
            }
            else{
                break;
            }
        }
        return year_of_name_change;
    }
    
    string GetTextForOutput(string l, string f)
    {
        if(f == "" && l == ""){
            return "Incognito";
        }
        else if(f == "" && l != ""){
            return l+" with unknown first name";
        }
        else if(f != "" && l == ""){
            return f+" with unknown last name";
        }
        else {
            string s = f + " " + l;
            return s;
        }
    }
    
    map<int, string> first_name;
    map<int, string> last_name;
};

int main()
{
    Person p;
    p.ChangeFirstName(1965, "Poly");
    p.ChangeLastName(1967, "Sergeeva");
    for(int year : {1900, 1965, 1990}){
        cout << p.GetFullName(year) << endl;
    }
    p.ChangeFirstName(1970, "Appo");
    for(int year : {1969, 1970}){
        cout << p.GetFullName(year) << endl;
    }
    p.ChangeLastName(1968, "Volkova");
    for(int year : {1969, 1970}){
        cout << p.GetFullName(year) << endl;
    }
    for(int year : {1900, 1965, 1967, 1968, 1969, 1990}){
        cout << p.GetFullNameWithHistory(year) << endl;
    }
    return 0;
}
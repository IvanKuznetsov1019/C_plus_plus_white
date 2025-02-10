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
    string GetFullName(int year){
        
        string l_name = "", f_name = "";
        
        for(auto n : first_name){
            if(n.first <= year){
                f_name = n.second;
            }
            else{
                break;
            }
        }
        
        for(auto n : last_name){
            if(n.first <= year){
                l_name = n.second;
            }
            else{
                break;
            }
        }
        
        if(f_name == "" && l_name == ""){
            return "Incognito";
        }
        else if(f_name == "" && l_name != ""){
            return l_name+" with unknown first name";
        }
        else if(f_name != "" && l_name == ""){
            return f_name+" with unknown last name";
        }
        else {
            string s = f_name + " " + l_name;
            return s;
        }
        
    }
    private:
    map<int, string> first_name;
    map<int, string> last_name;
};

int main()
{
    Person p;
    p.ChangeFirstName(1965, "Poly");
    p.ChangeLastName(1967, "Segeeva");
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
    return 0;
}
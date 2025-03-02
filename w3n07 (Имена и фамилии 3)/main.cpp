#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

class Person{
public:
    Person (const string& birth_first_name, const string& birth_last_name, int year){
        birth_year = year;
        first_names[year] = birth_first_name;
        last_names[year] = birth_last_name;
    }
    void ChangeFirstName(int year, const string &first_name){
        if(year >= birth_year){
            first_names[year] = first_name;
        }
    }
    void ChangeLastName(int year, const string &last_name){
        if(year >= birth_year){
            last_names[year] = last_name;
        }
    }
    string GetFullNameWithHistory(int year) {
        if(year < birth_year){
            return "No person";
        }
        string full_name_history = "";
        vector<string> first_name_history = GetNameHistory(first_names, year);
        vector<string> last_name_history = GetNameHistory(last_names, year);
        full_name_history = JoinNames(first_name_history) + " " + JoinNames(last_name_history);
        return full_name_history;
    }
    string GetFullName(int year) {
        if(year < birth_year){
            return "No person";
        }
        string full_name = "";
        string first_name = FindNameByYear(year, first_names);
        string last_name = FindNameByYear(year, last_names);
        full_name = first_name + " " + last_name;
        return full_name;
    }

private:
    map<int, string> first_names;
    map<int, string> last_names;
    int birth_year;
    string JoinNames(const vector<string>& names){
        string joined_names = ""; 
        if (names.size() == 1){
            joined_names = names[0]; 
        }
        else{
            joined_names = names.back(); 
            joined_names += " (";
            for (int i = (names.size() - 2); i >= 1; i--){
                joined_names += (names[i] + ", ");
            }
            joined_names += names.front(); 
            joined_names += ")";
        }
        return joined_names;
    }
    string FindNameByYear(int year, const map<int, string>& names){
        string name = "";
        for (const auto &item : names){
            if (item.first <= year){
                name = item.second;
            }
            else{
                break;
            }
        }
        return name;
    }
    vector<string> GetNameHistory(const map<int, string>& m_names, int year){
        vector<string> names;
        for (const auto &item : m_names){
            if (item.first > year){
                break;
            }
            if ((!names.empty() && item.second != names.back()) || names.empty()){
                names.push_back(item.second);
            }
        }
        return names;
    }
};

int main(){
    Person person("Polina", "Sergeeva", 1960);
    for (int year : {1959, 1960}){
        cout << person.GetFullNameWithHistory(year) << endl;
    }
    person. ChangeFirstName(1965, "Appolinaria");
    person. ChangeLastName(1967, "Ivanova");
     for (int year : {1965, 1967}){
        cout << person.GetFullNameWithHistory(year) << endl;
    }
    return 0;
}
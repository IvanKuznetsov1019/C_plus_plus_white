#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

class Person{
public:
    void ChangeFirstName(int year, const string &first_name){
        first_names[year] = first_name;
    }
    void ChangeLastName(int year, const string &last_name){
        last_names[year] = last_name;
    }
    string GetFullNameWithHistory(int year){
        string full_name_history = "";
        vector<string> first_name_history = GetNameHistory(first_names, year);
        vector<string> last_name_history = GetNameHistory(last_names, year);
        if (first_name_history.empty() && last_name_history.empty()){
            full_name_history = "incognito";
        }
        else if (!first_name_history.empty() && last_name_history.empty()){
            full_name_history = JoinNames(first_name_history) + " with unknown last name";
        }
        else if (first_name_history.empty() && !last_name_history.empty()){
            full_name_history = JoinNames(last_name_history) + " with unknown first name";
        }
        else{
            full_name_history = JoinNames(first_name_history) + " " + JoinNames(last_name_history);
        }
        return full_name_history;
    }
    string GetFullName(int year){
        string full_name = "";
        string first_name = FindNameByYear(year, first_names);
        string last_name = FindNameByYear(year, last_names);
        if (first_name == "" && last_name == ""){
            full_name = "incognito";
        }
        else if (first_name != "" && last_name == ""){
            full_name = last_name + " with unknown first name";
        }
        else if (first_name == "" && last_name != ""){
            full_name = first_name + " with unknown last name";
        }
        else{
            full_name = first_name + " " + last_name;
        }
        return full_name;
    }

private:
    map<int, string> first_names;
    map<int, string> last_names;
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

int main()
{
    Person person;

    person.ChangeFirstName(1965, "Polina");
    person.ChangeLastName(1967, "Sergeeva");
    for (int year : {1900, 1965, 1990}){
        cout << person.GetFullNameWithHistory(year) << endl;
    }

    person.ChangeFirstName(1970, "Appolinaria");
    for (int year : {1969, 1970}){
        cout << person.GetFullNameWithHistory(year) << endl;
    }

    person.ChangeLastName(1968, "Volkova");
    for (int year : {1969, 1970}){
        cout << person.GetFullNameWithHistory(year) << endl;
    }

    person.ChangeFirstName(1990, "Polina");
    person.ChangeLastName(1990, "Volkova-Sergeeva");
    cout << person.GetFullNameWithHistory(1990) << endl;

    person.ChangeFirstName(1966, "Pauline");
    cout << person.GetFullNameWithHistory(1966) << endl;

    person.ChangeLastName(1960, "Sergeeva");
    for (int year : {1960, 1967}){
        cout << person.GetFullNameWithHistory(year) << endl;
    }

    person.ChangeLastName(1961, "Ivanova");
    cout << person.GetFullNameWithHistory(1967) << endl;

    return 0;
}
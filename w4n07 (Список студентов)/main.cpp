#include <iostream>
#include <vector>
#include <map>

using namespace std;

struct student
{
    string first_name = "";
    string last_name = "";
    int birth_day = 0;
    int birth_month = 0;
    int birth_year = 0;
};

int main()
{
    int n;
    cin >> n;
    string first_name, last_name;
    student human;
    vector<student> students;
    for (int i = 0; i < n; i++)
    {
        cin >> human.first_name;
        cin >> human.last_name;
        cin >> human.birth_day;
        cin >> human.birth_month;
        cin >> human.birth_year;
        students.push_back(human);
    }
    int m;
    cin >> m;
    vector<pair<string, int>> requests;
    pair<string, int> request;
    int student_number;
    for (int i = 0; i < m; i++)
    {
        cin >> request.first;
        cin >> request.second;
        request.second = request.second - 1;
        requests.push_back(request);
    }

    for (int i = 0; i < m; i++)
    {
        if (requests[i].first == "name")
        {
            cout << students[requests[i].second].first_name;
            cout << ' ';
            cout << students[requests[i].second].last_name;
            cout << endl;
        }
        else if (requests[i].first == "date")
        {
            cout << students[requests[i].second].birth_day;
            cout << '.';
            cout << students[requests[i].second].birth_month;
            cout << '.';
            cout << students[requests[i].second].birth_year;
            cout << endl;
        }
        else
        {
            cout << "bad request" << endl;
        }
    }
    return 0;
}
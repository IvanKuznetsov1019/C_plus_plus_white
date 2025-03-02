#include <iostream>
#include <fstream>
#include <string>

using namespace std;
int main()
{
    string path = "input.txt";
    string line;
    ifstream input(path);
    if (input.is_open())
    {
        while (getline(input, line))
        {
            cout << line << endl;
        }
    }
    return 0;
}
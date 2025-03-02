#include <iostream>
#include <fstream>
#include <string>

using namespace std;
int main()
{
    ifstream input;
    ofstream output;
    string input_path = "input.txt";
    string output_path = "output.txt";
    string line;

    input.open(input_path);
    output.open(output_path);

    if (input.is_open() && output.is_open())
    {
        while (getline(input, line))
        {
            output << line << endl;
        }
    }
    return 0;
}
#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

int main()
{
    double value;
    ifstream input("input.txt");
    cout << setprecision(3) << fixed;
    while (input >> value)
    {
        cout << value << endl;
    }
    return 0;
}
#include <iostream>
#include <string>
#include <vector>
using namespace std;

void VectorPrint(vector <string> v)
{
    cout << v.size() << " ";
    for(string str : v)
    {
        cout << str << ' ';
    }
    cout << endl;
}

int main()
{
    int q;
    const int monthSize[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int monthNumber=0;
    cin >> q;
    vector<vector<string>> monthPlan(monthSize[0]);
    for(int i=0; i<q; i++)
    {
        string command;
        cin >> command;
        if(command=="ADD")
        {
            int date;
            cin >> date;
            string doing;
            cin >> doing;
            monthPlan[date-1].push_back(doing);
        }
        else if(command=="DUMP")
        {
            int date;
            cin >> date;
            VectorPrint(monthPlan[date-1]);
        }
        else if(command=="NEXT")
        {
            int oldMonthNumber = monthNumber;
            if(monthNumber<11)
            {
                monthNumber++;
            }
            else
            {
                monthNumber=0;
            }
            
            if(monthSize[monthNumber]>monthSize[oldMonthNumber])
            {
                int dateDifference=monthSize[monthNumber]-monthSize[oldMonthNumber];
                vector <vector<string>> monthTail(dateDifference);
                monthPlan.insert(end(monthPlan), begin(monthTail), end(monthTail));
            }
            else if (monthSize[monthNumber]<monthSize[oldMonthNumber])
            {
                
                int dateDifference=monthSize[oldMonthNumber]-monthSize[monthNumber];
                vector <vector<string>> monthTail(dateDifference);
                
                for(int j=0; j<dateDifference; j++)
                {
                    monthTail[j]=monthPlan[monthSize[monthNumber]+j];
                }
                
                monthPlan.resize(monthSize[monthNumber]);
                for(int j=0; j<dateDifference; j++)
                {
                    monthPlan[monthSize[monthNumber]-1].
                    insert(end(monthPlan[monthSize[monthNumber]-1]),
                    begin(monthTail[j]), end(monthTail[j]));
                }
                
            }
        }
    }
    return 0;
}
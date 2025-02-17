#include <iostream>
#include <vector>
#include <string>
using namespace std;

void WorryFunc(vector <bool>& q, int parametr)
{
    q[parametr]=true;
}

int WorryCountFunc(const vector <bool>& q)
{
    int worryCounter=0;
    int y=0;
    for(bool people : q)
    {

        if(people==true) worryCounter++;
        
        y++;
    }
    return worryCounter;
}

void QuietFunc(vector <bool>& q, int parametr)
{
    q[parametr]=false;
}

void ComeFunc(vector <bool>& q, int parametr)
{
    if(parametr>=0)
    {
        for(int i=0; i<parametr; i++)
        {
            q.push_back(false);
        }
    }
    else
    {
        for(int i=0; i<(parametr*(-1)); i++)
        {
            q.erase(q.begin()+q.size()-1);
        }
    }
}

vector <int> CommandParse(vector <bool>& q, vector <string> c, vector <int> p)
{
    vector <int> res;
    for(int i=0; i<c.size(); i++)
    {
        if(c[i]=="WORRY")
        {
            WorryFunc(q, p[i]);
            continue;
        }
        if(c[i]=="QUIET")
        {
            QuietFunc(q, p[i]); 
            continue;
        }
        if(c[i]=="COME")
        {
            ComeFunc(q, p[i]);
            continue;
        }
        if(c[i]=="WORRY_COUNT")
        {
            res.push_back(WorryCountFunc(q));
        }
    }
    return res;
}

int main()
{
    int commandNum;
    cin >> commandNum;
    vector <string> commands(commandNum);
    vector <int> parametrs(commandNum);
    vector <bool> ourQueue;
    for(int i=0; i<commandNum; i++)
    {
        cin>>commands[i];
        if(commands[i]=="WORRY_COUNT")
        {
            parametrs[i]=0;
            continue;
        }
        cin>>parametrs[i];
    }
    vector <int> result = CommandParse(ourQueue, commands, parametrs);
    for(int i=0; i<result.size(); i++)
    {
        cout << result[i] << endl;
    }
    return 0;
}

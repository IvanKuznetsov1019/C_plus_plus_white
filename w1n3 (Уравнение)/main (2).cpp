#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    float a, b, c;
    float d;
    cin >> a >> b >> c;
    if(a!=0)
    {
        if(b!=0)
        {
            if(c!=0)
            {
                d = pow(b, 2) - 4*a*c;
                if(d>0)
                {
                    cout << (sqrt(d)-b)/(2*a) << " " << (-sqrt(d)-b)/(2*a);

                }
                else if (d==0)
                {
                    cout << -b/(2*a);
                }
            }
            else
            {
                cout << 0 << -b/a;
            }           
        }
        else
        {
            if(c!=0)
            {
                if((-c/a) > 0) 
                {
                    cout << sqrt(-c/a) << " " << -sqrt(-c/a);
                }
            }
            else
            {
                cout << 0;
            }
        }
    }
    else
    {
        if(b!=0)
        {
            if(c==0)
            {
                cout << 0;
            }
            else
            {
                cout << -c/b;
            }
        }
    }
    return 0;
}
#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> v(n);
    int num;
    
    for(int i = 0; i < n; i++){
        cin >> num;
        v[i] = num;
    }
    
    sort(begin(v), end(v), [](int first_num, int second_num){
            return abs(first_num)<abs(second_num);
    });
    
    for(int i = 0; i < v.size(); i++){
        cout << v[i] << ' ';
    }
    
    return 0;
}
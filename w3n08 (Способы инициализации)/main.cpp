#include <iostream>
#include <vector>

using namespace std;

class Incognizable{
public:
    Incognizable(){
        data_size = 0;
    }
    Incognizable(int value){
        data.push_back(value);
        data_size = 1;
    }
    Incognizable(int value, int size){
        for(int i = 0; i < size; i++){
            data.push_back(value);
        }
        data_size = size;
    }
    vector <int> data;
    int data_size;
};

int main(){
    Incognizable a;
    Incognizable b = {};
    Incognizable c = {0};
    Incognizable d = {0, 4};
    
    cout << a.data_size << endl;
    cout << b.data_size << endl;
    cout << c.data_size << endl;
    cout << d.data_size << endl;
    
    return 0;
}

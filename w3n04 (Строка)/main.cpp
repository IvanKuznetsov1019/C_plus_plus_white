#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

class ReversibleString{
public:
    ReversibleString(){}
    ReversibleString(const string& str){
        data = str;
    }
    void Reverse(){
        reverse(begin(data), end(data));
    }
    string ToString() const{
        return data;
    }
private:
    string data;
};

int main(){
    ReversibleString s("live");
    s.Reverse();
    cout << s.ToString() << endl;
    
    s.Reverse();
    const ReversibleString& s_ref = s;
    string tmp = s_ref.ToString();
    cout << tmp << endl;
    
    ReversibleString empty;
    cout << "|" << empty.ToString() << "|" << endl;
    
    return 0;
}
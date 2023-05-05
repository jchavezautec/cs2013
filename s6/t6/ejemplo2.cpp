#include <iostream>

using namespace std;

int main(){


    string s = "laptop";
    if (s.begin() != s.end()){
        string::iterator it = s.begin();
        *it = toupper(*it);
    }

    cout << s << endl;
    
    return 0;
}

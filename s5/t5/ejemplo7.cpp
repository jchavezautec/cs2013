#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    vector<string> v = {"Hola","Mundo","en","C++"};

    for_each(v.begin(), v.end(), [](string s){cout << s << ' ';});
    cout << "\n---------------------------------\n";

    sort(v.begin(), v.end(), 
        [](string s1, string s2){return s1.size() < s2.size();});

    for_each(v.begin(), v.end(), [](string s){cout << s << ' ';});
    cout << "\n---------------------------------\n";
}
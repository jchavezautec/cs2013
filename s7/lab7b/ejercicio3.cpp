#include <iostream>
#include <vector>
#include <unordered_set>    

using namespace std;

int loop(vector<int> A){
    unordered_set<int> s;
    for(const int x: A){
        if(s.find(x) != s.end())
            return x;
        s.insert(x);
    }
    return -1;
}

int main(){
    vector<int> v1 = {1,3,2,4,1,5,3,2};
    vector<int> v2 = {5,1,2,4,5};
    vector<int> v3 = {1,2,3,4,5,8};

    cout << loop(v1) << endl;
    cout << loop(v2) << endl;
    cout << loop(v3) << endl;
}
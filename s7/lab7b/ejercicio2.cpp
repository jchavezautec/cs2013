#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

foo(vector<int> A){
    unordered_set<int> s;
    for(const int x: A){
        if(s.find(10-x) != s.end())
            return true;
        s.insert(x);
    }
    return false;
}

int main(){
    vector<int> v1 = {1,3,4,5,8};
    vector<int> v2 = {2,3,4,5,5};
    vector<int> v3 = {-3,1,1,2,3,5,6,10,13};
    vector<int> v4 = {9,1,2,3,5,1,0};

    cout << foo(v1) << endl;
    cout << foo(v2) << endl;
    cout << foo(v3) << endl;
    cout << foo(v4) << endl;

}
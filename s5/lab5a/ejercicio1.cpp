#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

void bubbleSort(vector<int>& v){
    for(int i=0; i<v.size(); i++){
        for(int j=i; j<v.size(); j++){
            if(v[i] > v[j])
                swap(v[i], v[j]);
        }
    }
}

void bubbleSortMod(vector<int>& v, bool (*comp)(int, int)){
    for(int i=0; i<v.size(); i++){
        for(int j=i; j<v.size(); j++){
            if(comp(v[i], v[j]))
                swap(v[i], v[j]);
        }
    }
}
    
bool compasc(int a, int b){ return a > b;}
bool compdes(int a, int b){ return a < b;}
bool compabs(int a, int b){ return abs(a) > abs(b);}

int main(){
    vector<int> v = {7,-6,5,-4,3,-2,1};

    bubbleSortMod(v, compasc);
    for_each(v.begin(), v.end(), [](int x){cout << x << " ";}); cout << endl;

    bubbleSortMod(v, compdes);
    for_each(v.begin(), v.end(), [](int x){cout << x << " ";}); cout << endl;
    
    bubbleSortMod(v, compabs);
    for_each(v.begin(), v.end(), [](int x){cout << x << " ";}); cout << endl;

    return 0;
}


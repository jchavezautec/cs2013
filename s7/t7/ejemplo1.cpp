#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void insertion_sort(std::vector<int>& v){
    for(int j = 1; j < v.size(); j++){
        int key = v[j];
        int i = j-1;

        while(i >= 0 && v[i] > key){
            v[i+1] = v[i];
            i--;
        }
        v[i+1] = key;
    }
}


int main(){
    vector<int> v(10);

    generate(v.begin(), v.end(), [](){return rand()%100;});
    for_each(v.begin(), v.end(), [](int x){cout << x << " ";});cout << endl;

    insertion_sort(v);
    for_each(v.begin(), v.end(), [](int x){cout << x << " ";});cout << endl;

    return 0;
}
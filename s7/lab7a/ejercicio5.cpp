#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void print(vector<int> v, int i1, int i2){
    for(int i=i1; i <= i2; i++)
        cout << v[i] << " ";
    cout << endl;
}

bool invariante_bucle(vector<int>v, int i){
    for(int k=0; k<=i; k++){
        if(v[k] > v[i])
            return false;
    }
    
    for(int k=i+1; k<v.size(); k++){
        if(v[i] > v[k])
            return false;
    }
    return true;
}
void bubble_sort(vector<int>& v){
    for(int i = 0; i < v.size(); i++){
        for(int j=v.size()-1; j > i; j--){
            if(v[j-1] > v[j]){
                swap(v[j-1], v[j]);
            }
        }
        print(v,0,i);
        cout << invariante_bucle(v,i) << endl;
    }
}
int main(){
    vector<int> v(10);
    generate(v.begin(), v.end(), [](){return rand()%100;});

    for (const auto e: v)
        cout << e << " ";
    cout << endl;

    bubble_sort(v);

    for (const auto e: v)
        cout << e << " ";
    cout << endl;

    return 0;
}

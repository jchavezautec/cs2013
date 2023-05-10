#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

template<class T>
void insertion_sort(std::vector<T>& v){
    for(std::size_t j = 1; j < v.size(); j++){
        int key = v[j];
        int i = j-1;

        while(i >= 0 && v[i] > key){
            v[i+1] = v[i];
            i--;
        }
        v[i+1] = key;
    }
}

template<class C>
void print_container(C container){
    for (const auto e: container)
        cout << e << " ";
    cout << endl;
}

int main(){
    vector<int> v(10);

    generate(v.begin(), v.end(), [](){return rand()%100;});
    print_container(v);

    insertion_sort(v);
    print_container(v);

    return 0;
}
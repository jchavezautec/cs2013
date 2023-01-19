#include <iostream>

using namespace std;

template<class T>
T Max(T a, T b){
    return a > b ? a: b;
}

template<class T, class...Ts>
T Max(T a, T b, Ts... args){
    return Max(Max(a,b),args...);
}

int main(){
    cout << Max(3,4) << endl; 
    cout << Max(1,2,3,4,5) << endl; //Max(2,3,4,5)->Max(3,4,5)->Max(4,5)
    cout << Max(3,3,2,7,1,0) << endl;
    return 0;
}

// print(2,3,4,5,6) # Salida:2 3 4 5 6
// vec.push_back(34,5,6,7)
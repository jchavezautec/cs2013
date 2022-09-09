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
    cout << Max(1,2,3,4,5) << endl;
    cout << Max(3,3,2,7,1,0) << endl;
    return 0;
}
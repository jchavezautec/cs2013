#include <iostream>

using namespace std;

template<class...Ts>
float suma(Ts... args){
    return (args+...);
}

template<class...Ts>
float promedio(Ts... args){
    float s = suma(args...);
    return s / sizeof...(args);
}

int main(){
    cout << promedio(1) << endl;
    cout << promedio(1,3) << endl; 
    cout << promedio(1,2,3,4,5) << endl;
    cout << promedio(3,3,-3-5,1.5,0) << endl;
    return 0;
}
#include <iostream>
#include <cmath>

using namespace std;

template<class...Ts>
float suma_de_cuadrados(Ts... args){
    return (pow(args,2)+...);
}

template<class...Ts>
float norma2(Ts... args){
    float s = suma_de_cuadrados(args...);
    return pow(s, 0.5);
}

int main(){
    
    cout << norma2(1) << endl;
    cout << norma2(3,4) << endl; 
    cout << norma2(1,2,3,4,5) << endl;
    cout << norma2(3,3,2,1,0) << endl;
    return 0;
}
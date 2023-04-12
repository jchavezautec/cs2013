#include <iostream>

using namespace std;

template <class T>
bool Max(T a, T b){
    return a>b;
}

template <typename T>
T sumar(T a, T b){
    return a+b;
}

template <class T1, class T2>
bool Max (T1 a, T2 b) {
    return a>b;
}


int main(){
    int x=1;
    char y='a';
    cout << Max(x,y) << endl;
    return 0;
}

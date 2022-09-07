#include <iostream>

using namespace std;

template<class T>
void SwapVal(T& a, T& b){
    T temp = a;
    a = b;
    b = temp;
}

template<>
void SwapVal(float& a, float& b){
    float temp = a;
    a = b;
    b = temp;
}

template<>
void SwapVal(char& a, char& b){
    char temp = a;
    a = b;
    b = temp;
}

int main(){
    int a = 3, b = 1;
    SwapVal(a, b);
    cout << "a = " << a << ", b = " << b << endl;

    float p = 3.4, q = 1.5;
    SwapVal(p, q);
    cout << "p = " << p << ", q = " << q << endl;

    char x = 'x', y = 'y';
    SwapVal(x, y);
    cout << "x = " << x << ", y = " << y << endl;
}
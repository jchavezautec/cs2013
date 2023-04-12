#include <iostream>
#include <math.h>

using namespace std;

template<class T = int>
T raiz(int n){
    T num = n;
    return sqrt(num);
};

template<int n>
int sum_pow(int a, int b){
    return pow(a+b, n);
}

int main(){
    //cout << raiz<float>(3) << endl; // Resultado: 1.73205
    //cout << raiz<int>(3) << endl;   // Resultado: 1
    //cout << raiz(3) << endl;        // Resultado: 2

    cout << sum_pow<3>(3, 4) << endl; // Resultado: 49
}
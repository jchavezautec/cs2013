#include <iostream>

using namespace std;

float suma(float x1, float x2){ return x1 + x2; }
float resta(float x1, float x2){ return x1 - x2; }
float mult(float x1, float x2){ return x1 * x2; }
float div(float x1, float x2){ return x1 / x2; }
float mod(int x1, int x2){ return ((x1 % x2) + x2)%x2; }

template<class T>
void calculadora(float(*f)(T, T), T x1, T x2){
    float resultado = f(x1,x2);
    cout << resultado << endl;
}

int main(){
    calculadora<float>(&suma, 3, 2);
    calculadora<float>(&resta, 3, 2);
    calculadora<float>(&mult, 3, 2);
    calculadora<float>(&div, 3, 2);
    calculadora(&mod, 3, 2);
    return 0;
}


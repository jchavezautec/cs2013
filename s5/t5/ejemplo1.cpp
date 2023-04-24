#include <iostream>

using namespace std;

void printer(){
    cout << "Hola Mundo" << endl;
}

int suma(int x1, int x2){ return x1 + x2; }
int resta(int x1, int x2){ return x1 - x2; }

void calculadora(int(*f)(int, int), int x1, int x2){
    int resultado = f(x1,x2);
    cout << resultado << endl;
}

int main(){
    calculadora(&suma, 3, 2);
    calculadora(&resta, 3, 2);

    return 0;
}


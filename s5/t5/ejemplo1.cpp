#include <iostream>

using namespace std;

int suma(int x1, int x2){return x1 + x2;}
int resta(int x1, int x2){return x1 - x2;}

void calculadora(int (*f)(int, int), int x1, int x2){
    cout << "El resultado es: " << f(x1, x2) << endl;
}

int main(){
    int x1, x2;
    cout << "Introduzca dos numeros: ";
    cin >> x1 >> x2;
    calculadora(suma, x1, x2);
    calculadora(resta, x1, x2);

    int (*pf)(int, int);

    pf = suma;
    cout << "El resultado es: " << pf(x1, x2) << endl;
    pf = resta;
    cout << "El resultado es: " << pf(x1, x2) << endl;
    return 0;
}